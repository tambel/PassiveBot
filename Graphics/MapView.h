#pragma once
#include "Window.h"
#include <Map.h>
class MapView: public Window
{
	WowMap * map;
protected:

public:
	MapView(void);
	~MapView(void);
	void InitMap();
	void createScene(void);
};

