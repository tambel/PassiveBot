#include "Chunk.h"

StaticFields Chunk::s_fileds=StaticFields();

Chunk::Chunk(void)
{
}
Chunk::Chunk(ChunkStreamInfo info, Location * location, Point2D<int> block_coordinates,Point2D<int> coordinates):root_info(info),location(location),block_coordinates(block_coordinates),coordinates(coordinates)
{
	header=MCNK();
	root_info=info;
	root_reader=root_info.reader;
	//root_reader->GetStream()->seekg(root_info.start,ios::beg);
	root_reader->SetPosition(root_info.start);
	header =root_reader->Read<MCNK>();
	//root_reader->GetStream()->read((char*)&header,sizeof(MCNK));
	unsigned sig;
	unsigned size;
	while (root_reader->GetPosition()<=root_info.start+root_info.size)
	{
		sig=root_reader->ReadUInt();
		size=root_reader->ReadUInt();
		switch (sig)
		{
		case ChunkSignatures::ADTSignature::MCNKSignatures::Mcvt:
			{
				LoadMcvt();
				break;
			}
		default:
			break;
		}
	}

	//root_reader->ReadBytes((char*)&height,

}
Chunk::~Chunk(void)
{
	delete [] vertices;
	vertices=0;
}
void Chunk::LoadMcvt()
{
	float * heights=new float[145];
	root_reader->ReadArray<float>((char*)heights,145);
	float posx = Metrics::MapMidPoint - header.position.y;
	float posy = Metrics::MapMidPoint + header.position.x;
	float posz = header.position.z;
	int counter = 0;
	vertices=new Vector3[145];
	for(int i = 0; i < 17; ++i)
	{
		for(int j = 0; j < (((i % 2) != 0) ? 8 : 9); ++j)
		{
			float height = posz + heights[counter];
			float x = posx + j * Metrics::UnitSize;
			if ((i % 2) != 0)
				x += 0.5f * Metrics::UnitSize;
			float y = posy - i * Metrics::UnitSize * 0.5f;

			vertices[counter] =Vector3(x, y, height);
			++counter;
		}
	}

	delete [] heights;
}