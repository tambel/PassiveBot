#pragma once
#include "Window.h"
#include <WowMap.h>
class MapView: public Window
{
	
protected:

public:
	WowMap * map;
	MapView(void);
	~MapView(void);
	void InitMap();
	void createScene(void);
	void CreateDynamicObject();
	void UpdateMap();
};

