#pragma once
#include "Window.h"
#include "WowDataLib\WowMap.h"
#include "MapScene.h"
#include "WowLib\WowObject.h"
#include "WowLib\Camera.h"

class MapView: public Window
{
	Wow::Camera * world_camera;
protected:

public:
	
	bool update;
	bool ready;
	WowMap * map;
	MapScene * map_scene;
	Ogre::SceneNode * main_scene;
	MapView(void);
	~MapView(void);
	void InitMap();
	void createScene(void);
	void CreateDynamicObject(Wow::WowObject * object);
	void UpdateMap();
	void SetWorldCamera(Wow::Camera * cam);
};

