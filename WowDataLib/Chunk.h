#pragma once

#include "ChunkedData.h"
#include "Utils.h"
#include "MCNK.h"
using namespace Utils;
using namespace Game;

class StaticFields
{
public:
	static const unsigned long index_count=768;
	unsigned  * indices;
	StaticFields()
	{
		indices=new unsigned[index_count];
		for (unsigned y = 0; y < 8; ++y)
		{
			for (unsigned x = 0; x < 8; ++x)
			{
				unsigned i = y * 8 * 12 + x * 12;
				indices[i + 0] = y * 17 + x;
				indices[i + 2] = y * 17 + x + 1;
				indices[i + 1] = y * 17 + x + 9;

				indices[i + 3] = y * 17 + x + 1;
				indices[i + 5] = y * 17 + x + 18;
				indices[i + 4] = y * 17 + x + 9;

				indices[i + 6] = y * 17 + x + 18;
				indices[i + 8] = y * 17 + x + 17;
				indices[i + 7] = y * 17 + x + 9;

				indices[i + 9] = y * 17 + x + 17;
				indices[i + 11] = y * 17 + x;
				indices[i + 10] = y * 17 + x + 9;
			}
		}
	}
};
class Chunk
{
private:
	Location * location;
	Point2D<int> block_coordinates;
	Point2D<int> coordinates;
	BinaryReader * root_reader;
	ChunkStreamInfo root_info;
	MCNK header;
	Vector3 * vertices;
	//static unsigned * indices;
	static StaticFields s_fileds;
	void LoadMcvt();

public:
	Chunk(void);
	Chunk(ChunkStreamInfo info, Location * loc,Point2D<int> block_coordinates,Point2D<int> coordinates);
	Location * GetLocation() {return location;}
	Point2D<int> GetBlockCoordinates() {return block_coordinates;}
	Point2D<int> GetCoordinates() {return coordinates;}
	~Chunk(void);
};

