#pragma once
#include "Cache.h"
#include "Chunk.h"
#include "Utils.h"
using namespace Utils;
class ChunkCache:public Cache<Chunk>
{
public:
	static Chunk * Find(Location *  location, Point2D<int> block_coordinates, Point2D<int>coordinates);

};

