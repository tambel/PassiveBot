#pragma once
#include "Link.h"
#include "WowDataLib\Chunk.h"
class ChunkLink: public Link
{
	Chunk * chunk;
public:
	ChunkLink(Chunk * chunk);
	~ChunkLink(void);
	virtual Vertice * GetVertices();
	virtual unsigned long GetVerticeCount();
	virtual unsigned long *  GetIndices();
	virtual unsigned long GetIndexCount();

};

