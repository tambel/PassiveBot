#pragma once 
#include "FileParser.h"
#include "Utils.h"
#include "Adt.h"
#include "Block.h"

#define TERRAIN_PATH L"C:\\Users\\laptop\\Desktop\\Extracted\\World\\Maps\\"
class Tile
{
protected:
	Point2D coords;
public:
	
	Block * blocks[16][16];
	Vector3 position;
	Tile();
	Tile(int x,int y);
	~Tile(void);

	void SetPosition(Vector3 position);
};