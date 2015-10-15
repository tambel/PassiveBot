#pragma once
#include "MapMeshScene.h"
#include "WowDataLib\MapEntity.h"

class MapEntityScene:public Scene
{
public:
	unsigned long id;
	MapEntityScene(void);
	~MapEntityScene(void);
	MapEntity * entity;
	vector<MapMeshScene*> mesh_scenes;
	//vector<MapMeshScene> mesh_scenes;
	void SetEntity(MapEntity* entity,Ogre::SceneNode * ps);
};