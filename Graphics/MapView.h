#pragma once
#include "Window.h"
#include "WowDataLib\WowMap.h"
#include "MapScene.h"
#include "WowLib\WowObject.h"
#include "WowLib\Camera.h"


struct DynamicObjectContainer
{
	MapEntityScene * scene;
};
class MapView: public Window
{
	Wow::Camera * world_camera;
protected:

public:
	
	bool update;
	MapScene * map_scene;
	bool ready;
	WowMap * map;

	MapView(void);
	~MapView(void);
	void InitMap();
	void createScene(void);
	void CreateDynamicObject(Wow::WowObject * object);
	void UpdateMap();
	void SetWorldCamera(Wow::Camera * cam);
};

