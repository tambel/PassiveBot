#include "MapView.h"
#include <FileParser.h>
#include <Adt.h>
#include "Renderable.h"
#include <OgreManualObject.h>
#include "MapRenderable.h"
#include "OgreRenderable.h"
#include "Utils.h"
MapView::MapView(void)
{

}
MapView::~MapView(void)
{
}
void MapView::InitMap()
{
	OgreRenderable::ClearCouner();
	WowMap * map= new WowMap(Vector3(0,0,0));
	mSceneMgr->getRootSceneNode()->setPosition(0,0,0);
	Ogre::SceneNode * scene= mSceneMgr->getRootSceneNode()->createChildSceneNode("Map");

	float block_pos_x=0;
	float block_pos_y=0;
	float tile_pos_x=0;
	float tile_pos_y=0;
	for (int i=0;i<3;i++)
	{
		tile_pos_y=0;
		for (int j=0;j<3;j++)
		{
			
			Ogre::SceneNode * tile_scene = scene->createChildSceneNode("Tile_"+to_string(map->tiles[i][j]->coords.X)+"_"+to_string(map->tiles[i][j]->coords.Y));
			tile_scene->setPosition(tile_pos_y,tile_pos_x,0);
			block_pos_x=0;
			for (int ti=0;ti<16;ti++)
			{
				block_pos_y=0;
				for (int tj=0;tj<16;tj++)
				{
					((OgreRenderable*)(map->tiles[i][j]->blocks[ti][tj]))->CreateScene(tile_scene)->setPosition(block_pos_x,block_pos_y,0);
					block_pos_y+=BLOCK_LENGTH;
				}
				block_pos_x+=BLOCK_LENGTH;
			}
			for (auto map_object:map->tiles[i][j]->map_objects)
			{
				for (auto mesh:map_object->meshes)
				{
					float t_pos_x= map->tiles[i][j]->coords.Y * 533.33333-17066.6656;
					float t_pos_y=  map->tiles[i][j]->coords.X * 533.33333-17066.6656;
					Vector3 pos;
					pos.x=mesh->position.z-	t_pos_x;
					pos.y=mesh->position.x-	t_pos_y;
					pos.z=mesh->position.y;
					Ogre::SceneNode * mesh_scene=((OgreRenderable*)mesh)->CreateScene(tile_scene);
					mesh_scene->setPosition(Vector3ToOgreVector(pos));
					mesh_scene->rotate(Ogre::Vector3(0,0,1),Ogre::Degree(mesh->rotation.y));
					mesh_scene->rotate(Ogre::Vector3(0,1,0),Ogre::Degree(mesh->rotation.z));
					mesh_scene->rotate(Ogre::Vector3(1,0,0),Ogre::Degree(mesh->rotation.x));

				}
			}
			tile_pos_y+=TILE_LENGTH;
		}
		tile_pos_x+=TILE_LENGTH;
	}
	//delete map;
}
void MapView::createScene(void)
{
	InitMap();
}