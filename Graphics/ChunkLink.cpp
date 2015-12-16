#include "ChunkLink.h"


ChunkLink::ChunkLink(Chunk * chunk):chunk(chunk)
{
	
}


ChunkLink::~ChunkLink(void)
{
}
Vertice * ChunkLink::GetVertices()
{
	return chunk->GetVertices();
}
unsigned long ChunkLink::GetVerticeCount()
{
	return 145;
}
unsigned long * ChunkLink::GetIndices()
{
	return chunk->GetIndices();
}
unsigned long ChunkLink::GetIndexCount()
{
	return 768;
}
