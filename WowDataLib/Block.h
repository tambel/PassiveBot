#pragma once
#include "Renderable.h"
#include "FileParser.h"
#include "Utils.h"
#include "Adt.h"
using namespace Utils::Graphics;
#define BLOCK_LENGTH 533.33333f
#define CHUNK_LENGTH 33.33333f
#define SUBCHUNK_LENGTH 4.16666f
#define HALF_SUBCHUNK_LENGTH 2.08333f
class Block:public Renderable
{

protected:

	
public:

	Point2D<int> coords;
	Block(Point2D<int> coords);
	Block(void);
	~Block(void);
	Point2D<float> centralized_position;
};