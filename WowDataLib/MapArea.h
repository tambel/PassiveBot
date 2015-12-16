#pragma once
#include "Chunk.h"
#include <vector>
using namespace std;
class MapArea
{
protected:
	//Chunk ** chunks;
	vector<Chunk*> chunks;
public:
	MapArea(void);
	~MapArea(void);
	vector<Chunk *>* GetChunks();


};

