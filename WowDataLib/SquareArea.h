#pragma once
#include "Utils.h"
#include "ADTWorker.h"
#include "MapArea.h"
using namespace Utils;
using namespace Utils::Game;
struct ChunkInfo
{
	Location * location;
	Point2D<int> block_coordinates;
	Point2D<int> coordinates;
	Vector3 position;
	ChunkInfo();
	ChunkInfo(	Location * location, Point2D<int> block_coordinates,Point2D<int> coordinates,int radius);//:location(location),block_coordinates(block_coordinates),coordinates(coordinates){}
};
class SquareArea: public MapArea
{
	//Chunk *** chunks;
	int radius;
	Location * location;
	Point2D<int> block_coordinates;
	Point2D<int> coordinates;

public:
	SquareArea(Location * location, Point2D<int> block_coordinates,Point2D<int> coordinates,int radius);
	~SquareArea(void);
};

