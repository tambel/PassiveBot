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
	map=new WowMap(Vector3(0,0,0));
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


	/*
	for (int i=0;i<3;i++)
	{
	for (int j=0;j<3;j++)
	{
	Ogre::SceneNode * tile_scene = scene->createChildSceneNode("Tile_"+to_string(map->tiles[i][j]->coords.X)+"_"+to_string(map->tiles[i][j]->coords.Y));
	for (int ti=0;i<16;ti++)
	{
	for (int tj=0;tj<16;tj++)
	{
	((OgreRenderable*)map->tiles[i][j]->blocks[ti][tj])->CreateScene(tile_scene);
	}
	}

	}
	}
	*/

	//mSceneMgr->getRootSceneNode()->addChild(((MapRenderable*)map)->CreateScene(mSceneMgr))
	/*
	string n="name"+to_string(b);
	manual[b] = mSceneMgr->createManualObject(n);
	manual[b]->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
	for (int i=0;i<145;i++)
	{
	manual[b]->position(map->tile->blocks[b]->vertices[i].position.x,map->tile->blocks[b]->vertices[i].position.y,map->tile->blocks[b]->vertices[i].position.z);
	manual[b]->colour(Ogre::ColourValue(map->tile->blocks[b]->vertices[i].color.r,map->tile->blocks[b]->vertices[i].color.g,map->tile->blocks[b]->vertices[i].color.b,map->tile->blocks[b]->vertices[i].color.a));

	}

	for (int i=0;i<768;i++)
	{
	manual[b]->index(map->tile->blocks[b]->indices[i]);
	}
	manual[b]->end();
	Ogre::MeshPtr mesh= manual[b]->convertToMesh(n+"_mesh");

	Ogre::Entity* m_pGraphicEntity = mSceneMgr->createEntity(n+"_ent", mesh->getName());

	Ogre::SceneNode * node=mSceneMgr->getRootSceneNode()->createChildSceneNode();



	node->attachObject(m_pGraphicEntity);
	//node->rotate(Ogre::Vector3(0,1,0),Ogre::Radian(Ogre::Math::PI/2),Ogre::Node::TransformSpace::TS_WORLD);
	//Ogre::SceneNode * node= (Ogre::SceneNode*)mSceneMgr->getRootSceneNode()->getChild(n+"_ent");
	*/





	//mCamera->setPosition(-9600.0f,-1066.66602f,72.7356796f);

}
void MapView::createScene(void)
{
	InitMap();
}