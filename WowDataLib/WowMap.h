#pragma once
#include "Tile.h"
#include "Adt.h"
#include "Utils.h"
#include <vector>
#include "DynamicObject.h"
using namespace std;
//using namespace Utils::;

class WowMap
{
	
protected:
	
	
	
public:
	Vector3 position;
	Tile * tiles[3][3];
	vector<MapEntity*> objects;
	WowMap(Vector3 position);
	~WowMap(void);
	void SetPosition(Vector3 position);
	void GoToPlace(Vector3 coords);

	
	void Draw();

};

