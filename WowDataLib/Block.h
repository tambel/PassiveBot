#pragma once
#include "Renderable.h"
#include "FileParser.h"
#include "Utils.h"
#include "Adt.h"
using namespace Utils::Graphics;
#define TILE_LENGTH 533.33333f
#define BLOCK_LENGTH 33.33333f
#define CHUNK_LENGTH 4.16666f
#define HALF_CHUNK_LENGTH 2.08333f
class Block:public Renderable
{

protected:

	
public:
	Point2D coords;
	Block(MCNK * mcnk, bool exist =true);
	Block(void);
	~Block(void);
	//virtual void CreateEntity();
};