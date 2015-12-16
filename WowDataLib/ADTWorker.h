#pragma once
#include "ADTCache.h"
#include "ChunkCache.h"
class ADTWorker
{

public:
	static Chunk * GetChunk(Location * location, Point2D<int> block_coordinates, Point2D<int>coordinates);
	static ADT * GetADT(Location * location, Point2D<int> coordinates);
};

