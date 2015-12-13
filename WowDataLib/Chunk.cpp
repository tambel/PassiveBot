#include "Chunk.h"
using namespace ChunkSignatures::ADTSignature;

Chunk::Chunk(void)
{
}
Chunk::Chunk(ChunkStreamInfo info)
{
	info.reader->GetStream()->seekg(info.start,ios::beg);
	MCNK_Header mcnk_heared;
	MCVT height;
	info.reader->GetStream()->read((char*)&mcnk_heared,sizeof(MCNK_Header));
	unsigned sig;
	unsigned size;
	while (info.reader->GetPosition()<=info.start+info.size)
	{
		sig=info.reader->ReadUInt();
		size=info.reader->ReadUInt();
		switch (sig)
		{
		case MCNKSignatures::Mcvt:
			{
				info.reader->GetStream()->read((char*)&height,size);
			}
		default:
			break;
		}
	}
	info.reader->MoveForward(8);
	info.reader->GetStream()->read((char*)&height,sizeof(MCVT));

	//info.reader->ReadBytes((char*)&height,

}
Chunk::~Chunk(void)
{
}
