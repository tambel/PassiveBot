#include "MapArea.h"


MapArea::MapArea(void)
{
}


MapArea::~MapArea(void)
{
}
vector <Chunk *>* MapArea::GetChunks()
{
	return &chunks;
}
