#pragma once
#include <stdint.h>
#include <vector>
#include "Utils.h"
#include "WMO.h"
#include "M2.h"
#include "Chunk.h"
#include <fstream>
#include "ChunkedData.h"
using namespace Utils::Graphics;
using namespace std;
namespace ChunkSignatures
{
	namespace ADTSignature
	{
		static const unsigned int Mver = 0x4D564552;
		static const unsigned int Mhdr = 0x4D484452;
		static const unsigned int Mcin = 0x4D43494E;
		static const unsigned int Mtex = 0x4D544558;
		static const unsigned int Mmdx = 0x4D4D4458;
		static const unsigned int Mmid = 0x4D4D4944;
		static const unsigned int Mwmo = 0x4D574D4F;
		static const unsigned int Mwid = 0x4D574944;
		static const unsigned int Mddf = 0x4D444446;
		static const unsigned int Modf = 0x4D4F4446;
		// ReSharper disable once InconsistentNaming
		static const unsigned int Mh2o = 0x4D48324F;
		static const unsigned int Mfbo = 0x4D46414F;
		static const unsigned int Mtxf = 0x4D545846;
		static const unsigned int Mtxp = 0x4D545850;
		static const unsigned int Mcnk = 0x4D434E4B;
		namespace MCNKSignatures
		{
			static const unsigned int Mcvt = 0x4D435654;
		};
	}
	
	/*
	static class Chunks
	{
	public:
	static const unsigned int Mver = 0x4D564552;
	static const unsigned int Mhdr = 0x4D484452;
	static const unsigned int Mcin = 0x4D43494E;
	static const unsigned int Mtex = 0x4D544558;
	static const unsigned int Mmdx = 0x4D4D4458;
	static const unsigned int Mmid = 0x4D4D4944;
	static const unsigned int Mwmo = 0x4D574D4F;
	static const unsigned int Mwid = 0x4D574944;
	static const unsigned int Mddf = 0x4D444446;
	static const unsigned int Modf = 0x4D4F4446;
	// ReSharper disable once InconsistentNaming
	static const unsigned int Mh2o = 0x4D48324F;
	static const unsigned int Mfbo = 0x4D46414F;
	static const unsigned int Mtxf = 0x4D545846;
	static const unsigned int Mtxp = 0x4D545850;
	static const unsigned int Mcnk = 0x4D434E4B;
	};
	*/
}

enum Location
{
	Kamlimdor,
	Eastern_Kindoms
};
class ADT:ChunkedData
{
private:
	BinaryReader * root_reader;
	BinaryReader * tex;
	BinaryReader * obj;
	ChunkStreamInfo chunk_stream_infos[16][16];
public:
	ADT(Location location,Point2D<int> coordinates);

	//Chunk * GetChunk(Point2D<int> coordinates);
};

/*
struct MVER {
unsigned  version;
};
struct MCVT 
{
float height[145];
};
struct MCNK
{
unsigned offset;
Vector3 position;
MCVT mcvt;
Point2D<int> coords;
};
struct MWMO
{
unsigned long length;
//string * names;
char * names;
};
struct MWID
{
unsigned long length;
unsigned long * offsets;
};
struct MMDX 
{
unsigned long length;
//string * names;
char * names;
};
struct MMID
{
unsigned long length;
unsigned long * offsets;
};
struct MODF
{
unsigned mwidEntry;           // references an entry in the MWID chunk, specifying the model to use.
unsigned uniqueId;            // this ID should be unique for all ADTs currently loaded. Best, they are unique for the whole map.
Vector3 position;
Vector3 rotation;            // same as in MDDF.
float lowerBounds[3];         // these two are position plus the wmo bounding box.
float upperBounds[3];
unsigned wtf[2];
};
struct MDDF
{
unsigned mwidEntry;           // references an entry in the MWID chunk, specifying the model to use.
unsigned uniqueId;            // this ID should be unique for all ADTs currently loaded. Best, they are unique for the whole map.
Vector3 position;
Vector3 rotation;     
unsigned short scale;

unsigned short wtf;
};
class Adt
{
bool is_file_exists;
char * root;
unsigned long root_length;
char * obj;
unsigned long obj_length;
char * tex;
unsigned long tex_length;
public:

MVER mver;
vector<MCNK*> mcnk_list;
/*
MWMO * mwmo;
MWID * mwid;
MODF * modf;

vector<WmoInfo> wmo_infos;
vector <M2Info> m2_infos;
Adt(string  path);
~Adt(void);
unsigned GetVersion();
bool IsExist();

};

*/