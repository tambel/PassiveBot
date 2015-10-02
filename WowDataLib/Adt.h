#pragma once
#include <stdint.h>
#include <vector>
#include "Utils.h"
using namespace std;
struct MVER {
	unsigned  version;
};
struct MCIN {
	struct MCINEntry {
		MVER* mcnk;                   // absolute offset.
		uint32_t size;                // the size of the MCNK chunk, this is refering to.
		uint32_t flags;               // these two are always 0. only set in the client.
		uint32_t asyncId;	
	} entries[16*16];
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
	Point2D coords;
};

class Adt
{
	bool is_file_exists;
public:
	MVER mver;
	vector<MCVT> mcvt_list;
	vector<MCNK*> mcnk_list;
	

	Adt(wstring  path);
	~Adt(void);
	unsigned GetVersion();
	bool IsExist();

};

