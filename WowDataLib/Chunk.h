#pragma once
#include "Adt.h"
#include "ChunkedData.h"
#include "MCNK.h"
class Chunk
{
public:
	Chunk(void);
	Chunk(ChunkStreamInfo info);
	~Chunk(void);
};

