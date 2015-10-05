#pragma once
#include "Tile.h"
#include "Adt.h"
#include "Utils.h"
using namespace DataUtils;

class WowMap
{
	
protected:
	Vector3 position;
	
	
public:
	Tile * tiles[3][3];
	WowMap(Vector3 position);
	~WowMap(void);
	void SetPosition(Vector3 position);
	void GoToPlace(Vector3 coords);
	void Draw();

};

