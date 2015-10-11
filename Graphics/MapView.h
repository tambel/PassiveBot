#pragma once
#include "Window.h"
#include "WowDataLib\WowMap.h"
class MapView: public Window
{
	
protected:

public:
	bool ready;
	WowMap * map;
	MapView(void);
	~MapView(void);
	void InitMap();
	void createScene(void);
	void CreateDynamicObject();
	void UpdateMap();
};

