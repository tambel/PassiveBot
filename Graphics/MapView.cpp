#include "MapView.h"
#include <WowDataLib\FileParser.h>
#include <WowDataLib\Adt.h>
#include <WowDataLib\Renderable.h>
#include <OgreManualObject.h>
#include "OgreRenderable.h"
#include "Utils.h"
#include <iostream>
#include <iostream>
using namespace std;
using namespace Utils::WowTypes;
MapView::MapView(void)
{

}
MapView::~MapView(void)
{
}
void MapView::InitMap()
{
	OgreRenderable::ClearCouner();
	//mSceneMgr->getRootSceneNode()->setPosition(0,0,0);
	Ogre::SceneNode * map_scene= mSceneMgr->getRootSceneNode()->createChildSceneNode("map");
	Ogre::SceneNode * scene=map_scene->createChildSceneNode("qqqq");
	//scene->rotate(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3(1,0,0)),Ogre::Node::TS_PARENT);
	//scene->needUpdate();
	float block_pos_x=0;
	float block_pos_y=0;
	float tile_pos_x=0;
	float tile_pos_y=0;
	vector<MapObject*> check_list=vector<MapObject*>();
	for (int i=0;i<3;i++)
	{
		tile_pos_y=0;
		for (int j=0;j<3;j++)
		{
			if (map->tiles[i][j]->exists)
			{
				Ogre::SceneNode * tile_scene = scene->createChildSceneNode("Tile_"+to_string(map->tiles[i][j]->indexX)+"_"+to_string(map->tiles[i][j]->indexY));
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
				bool exist;
				
				for (auto map_object:map->tiles[i][j]->map_objects)
				{
					exist=false;
					for (auto mo:check_list)
					{
						if (mo->id==map_object->id)
						{
							exist=true;
							break;
						}
					}
					if (exist)
						continue;
					check_list.push_back(map_object);
					Ogre::SceneNode * map_object_scene= tile_scene->createChildSceneNode(map_object->name+"_"+to_string(OgreRenderable::GetUIDAndIncrement()));
					for (auto mesh:map_object->meshes)
					{

						float t_pos_x= map->tiles[i][j]->indexY * 533.33333-17066.6656;
						float t_pos_y=  map->tiles[i][j]->indexX * 533.33333-17066.6656;
						Vector3 pos;
						pos.x=mesh->position.coords.z-	t_pos_x;
						pos.y=mesh->position.coords.x-	t_pos_y;
						pos.z=mesh->position.coords.y;
						Ogre::SceneNode * mesh_scene=((OgreRenderable*)mesh)->CreateScene(map_object_scene);
						mesh_scene->setPosition(Vector3ToOgreVector(pos));
						mesh_scene->rotate(Ogre::Vector3(0,0,1),Ogre::Degree(mesh->position.rotation.y));
						mesh_scene->rotate(Ogre::Vector3(0,1,0),Ogre::Degree(mesh->position.rotation.z));
						mesh_scene->rotate(Ogre::Vector3(1,0,0),Ogre::Degree(mesh->position.rotation.x));

					}
				}
				
				
				for (auto doodad:map->tiles[i][j]->doodads)
				{
					cout<<doodad->name<<endl;
					Ogre::SceneNode * map_object_scene= tile_scene->createChildSceneNode(doodad->name+"_"+to_string(OgreRenderable::GetUIDAndIncrement()));
					for (auto mesh:doodad->meshes)
					{
						float t_pos_x= map->tiles[i][j]->indexY * 533.33333-17066.6656;
						float t_pos_y=  map->tiles[i][j]->indexX * 533.33333-17066.6656;
						Vector3 pos;
						pos.x=mesh->position.coords.z-	t_pos_x;
						pos.y=mesh->position.coords.x-	t_pos_y;
						pos.z=mesh->position.coords.y;
						Ogre::SceneNode * mesh_scene=((OgreRenderable*)mesh)->CreateScene(map_object_scene);
						mesh_scene->setPosition(Vector3ToOgreVector(pos));
						mesh_scene->rotate(Ogre::Vector3(0,0,1),Ogre::Degree(mesh->position.rotation.y));
						mesh_scene->rotate(Ogre::Vector3(0,1,0),Ogre::Degree(mesh->position.rotation.z));
						mesh_scene->rotate(Ogre::Vector3(1,0,0),Ogre::Degree(mesh->position.rotation.x));
					}
				}
			}
			
			tile_pos_y+=TILE_LENGTH;
		}
		tile_pos_x+=TILE_LENGTH;
	}
	mCamera->setPosition(Vector3ToOgreVector(map->position));
	//scene->roll(Ogre::Radian(Ogre::Math::PI/2));
	scene->rotate(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3(0,0,1)),Ogre::Node::TS_WORLD);
	//scene->setOrientation(Ogre::Quaternion(Ogre::Degree(90), Ogre::Vector3(1,0,0)));
	scene->setPosition(map->position.x+TILE_LENGTH,map->position.y+TILE_LENGTH,map->position.z);
	//scene->setPosition(Vector3ToOgreVector(map->position));
	//mSceneMgr->getRootSceneNode()->needUpdate();
	//delete map;
}
void MapView::createScene(void)
{

	InitMap();
}
void MapView::UpdateMap()
{
	if (map->new_object)
	{
		for (auto nmo:map->new_objects)
		{

			Ogre::SceneNode * nmo_scene=mSceneMgr->getSceneNode("map");
			for (auto mesh:nmo->meshes)
			{
				for (unsigned long i =0;i<mesh->vertice_count;i++ )
				{
					//mesh->vertices[i].position.x*=100;
					//mesh->vertices[i].position.y*=100;
					//mesh->vertices[i].position.z*=100;
				}

				Ogre::SceneNode * node= ((OgreRenderable*)mesh)->CreateScene(nmo_scene);
				string s=node->getParentSceneNode()->getName();
				//node->rotate(Ogre::Quaternion(Ogre::Degree(-90), Ogre::Vector3(1,0,0)),Ogre::Node::TS_WORLD);

				node->setPosition(Vector3ToOgreVector( nmo->position.coords));
				node->rotate(Ogre::Vector3(0,0,1),Ogre::Radian(nmo->position.rotation.z));
			}
		}
		map->new_object=false;
	}
	for (auto dyn_obj:map->new_objects)
	{
		if (dyn_obj->changed)
		{
			for (auto mesh:dyn_obj->meshes)
			{
				((OgreRenderable*)mesh)->scene->setPosition(Vector3ToOgreVector(dyn_obj->position.coords));
				((OgreRenderable*)mesh)->scene->setOrientation(Ogre::Quaternion(Ogre::Radian(dyn_obj->position.rotation.z),Ogre::Vector3(0,0,1)));   //(Ogre::Vector3(0,0,1),Ogre::Radian(dyn_obj->position.rotation.z));
				dyn_obj->changed=false;
			}
		}
	}
}