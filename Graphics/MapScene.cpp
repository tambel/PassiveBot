#include "MapScene.h"
#include "Utils.h"
#include "OgreRenderable.h"

MapScene::MapScene(WowMap * map,Ogre::SceneNode * ps)
{
	dynamic_objects=vector<MapEntityScene*>();
	SetMap(map,ps);
}


MapScene::~MapScene(void)
{
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			//delete tiles[i][j];
		}
	}
	for (auto dyn_obj:dynamic_objects)
	{
		//delete dyn_obj;
	}
	//dynamic_objects.clear();
	Ogre::MeshManager::getSingletonPtr()->unloadAll();

	scene_node->getCreator()->clearScene();
}

void MapScene::SetMap(WowMap * map,Ogre::SceneNode * ps)
{
	parent_scene=ps;
	scene_node=((OgreRenderable*)map->solid_mesh)->CreateScene(parent_scene);
	//scene_node=parent_scene->createChildSceneNode();
	/*
	for (auto dynamic_object:map->dynamic_objects)
	{
		MapEntityScene * mes=new MapEntityScene();
		mes->SetEntity(dynamic_object->GetEntity(),scene_node->getCreator()->getRootSceneNode());
		dynamic_objects.push_back(mes);
	}
	*/
	scene_node->setPosition(Vector3ToOgreVector(map->position.coords));
	scene_node->rotate(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3(0,0,1)),Ogre::Node::TS_WORLD);
	scene_node->rotate(Ogre::Quaternion(Ogre::Degree(-90), Ogre::Vector3(1,0,0)),Ogre::Node::TS_WORLD);

}
void MapScene::AddMapEntityScene(DynamicObject * dyn_obj)
{
	MapEntityScene * mes = new MapEntityScene();
	mes->SetEntity(dyn_obj->GetEntity(),parent_scene);
	dynamic_objects.push_back(mes);

}

