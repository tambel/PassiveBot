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
	Point2D<int> coords_2D;
	bool new_object;
	bool to_update;
	bool busy;
	bool to_redraw;
	Position position;
	Tile * tiles[3][3];
	vector<DynamicObject*> dynamic_objects;
	vector<MapEntity*> new_objects;
	WowMap(Vector3 position);
	~WowMap(void);
	void SetPosition(Vector3 position);
	void GoToPlace(Vector3 position);
	static Point2D<int> WorldPositionToMapCoords(Vector3 position);
	bool CheckForTileChange(Vector3 position);
	void AddDynamicObject(Wow::WowObject* obj);
	void RemoveDynamicObject(Wow::WowObject* obj);
	void MoveMapTiles(Point2D<int> vector);

	void Draw();

};

