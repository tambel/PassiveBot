#pragma once
#include "Renderable.h"
#include "FileParser.h"
#include "Utils.h"
#include "Adt.h"
#define TILE_LENGTH 533.33333f
#define BLOCK_LENGTH 33.33333f
#define CHUNK_LENGTH 4.16666f
#define HALF_CHUNK_LENGTH 2.08333f
class Block:public Renderable
{

protected:
	MCNK * mcnk;
	
public:
	Point2D coords;
	Block(MCNK * mcnk);
	Block(void);
	~Block(void);
	//virtual void CreateEntity();
};