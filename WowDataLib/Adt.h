#pragma once
#include <stdint.h>
#include <vector>
#include "Utils.h"
#include "WMO.h"
#include "M2.h"
using namespace Utils::Graphics;
using namespace std;

enum Continent
{
	Kamlimdor,
	Eastern_Kindoms
};
class ADT
{
	ADT(Continent continent,Point2D<int> coordinates);
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