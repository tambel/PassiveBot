#include "MapView.h"
#include <WowDataLib\FileParser.h>
#include <WowDataLib\Adt.h>
#include <WowDataLib\Renderable.h>

#include <OgreManualObject.h>
#include "OgreRenderable.h"

#include "Utils.h"
#include <iostream>
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


using namespace std;
using namespace Utils::WowTypes;
MapView::MapView(void)
{
	world_camera=0;
	update=false;
}
MapView::~MapView(void)
{
}
/*
void MapView::InitMap()
{
	main_scene= mSceneMgr->getRootSceneNode()->createChildSceneNode("map");
	map_scene=new MapScene(map,main_scene);
	
	//Ogre::SceneNode * map_scene= mSceneMgr->getRootSceneNode()->createChildSceneNode("map");
	//Ogre::SceneNode * node=((OgreRenderable*)map->solid_mesh)->CreateScene(map_scene);
	mCamera->setPosition(Vector3ToOgreVector(map->position.coords));
	//node->rotate(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3(0,0,1)),Ogre::Node::TS_WORLD);
}
void MapView::createScene(void)
{

	InitMap();
}
void MapView::UpdateMap()
{
	if (map->to_redraw)
	{
		if (!map->busy)
		{
			map->busy=true;
			delete map_scene;
			main_scene->getCreator()->clearScene();
			mSceneMgr->destroyAllManualObjects();
			mSceneMgr->destroyAllMovableObjects();
			Ogre::MeshManager::getSingletonPtr()->unloadAll();
			Ogre::MeshManager::getSingletonPtr()->removeAll();
			main_scene= mSceneMgr->getRootSceneNode()->createChildSceneNode("map");
			map_scene=new MapScene(map,main_scene);
			//Ogre::SceneNode * node=((OgreRenderable*)map->solid_mesh)->CreateScene(map_scene);
			//node->rotate(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3(0,0,1)),Ogre::Node::TS_WORLD);
			/*
			map->busy=true;
			delete map_scene;
			mSceneMgr->destroyAllManualObjects();
			mSceneMgr->destroyAllMovableObjects();
			Ogre::MeshManager::getSingletonPtr()->removeAll();
			map_scene=new MapScene();
			Ogre::SceneNode * scene= mSceneMgr->getRootSceneNode()->createChildSceneNode("map");


			map_scene->SetMap(map,static_cast<Ogre::SceneNode*>(scene));
			*/
			for  (auto dyn_obj:map->dynamic_objects)
			{
			dyn_obj->is_new=true;
			}
			
			map->to_update=true;
			map->to_redraw=false;
			map->busy=false;
			
		}
	}

	if (map->to_update)
	{
		for (auto dyn_obj:map->dynamic_objects)
		{
			if (dyn_obj->is_new)
			{
				map_scene->AddMapEntityScene(dyn_obj);
				dyn_obj->is_new=false;
			}
		}
		map->to_update=false;
	}

	for (auto dyn_obj:map->dynamic_objects)
	{
		for (auto dyn_obj_sc:map_scene->dynamic_objects)
		{
			if (dyn_obj->GetEntity()->GetID()==dyn_obj_sc->id)
			{
					dyn_obj_sc->scene_node->setPosition(Vector3ToOgreVector( dyn_obj->object->GetPosition().coords));
					dyn_obj_sc->scene_node->setOrientation(Ogre::Quaternion(Ogre::Radian(dyn_obj->object->GetPosition().rotation.z),Ogre::Vector3(0,0,1)));
				break;
			}
		}
	}
	if (world_camera!=0)
	{
		Vector3 pos=world_camera->GetPosition(true).coords;
		pos.z+=50;
		//mCamera->setPosition(Vector3ToOgreVector(pos));
	}
}
void MapView::CreateDynamicObject(Wow::WowObject * object)
{

}
void MapView::SetWorldCamera(Wow::Camera * cam)
{
	world_camera=cam;

}
*/