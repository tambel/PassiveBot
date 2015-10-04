#pragma once
#include "Tile.h"
#include "Adt.h"
#include "Utils.h"


class WowMap
{
protected:
	Vector3 position;
	Tile * tiles[3][3];
	
public:
	WowMap(Vector3 position);
	~WowMap(void);
	void SetPosition(Vector3 position);
	void GoToPlace(Vector3 coords);

};

