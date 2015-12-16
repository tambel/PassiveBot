#pragma once
#include "Window.h"
#include "WowDataLib\SquareArea.h"


class MapFrame: public Window
{
	SquareArea * area;
public:
	MapFrame(void);
	~MapFrame(void);
	void createScene();
	void createTerrain();
};

