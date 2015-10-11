#pragma once
#include <string>
#include <vector>
#include "Utils.h"
using namespace Utils;
using namespace std;
struct MOGN
{

	short length;
	unsigned wtf;
	char * group_names;
	MOGN():group_names(0){}
	~MOGN()
	{
		delete  [] group_names;
	}
};
struct MOGI
{
	//unsigned short length;
	//unsigned short offsets[30];
	unsigned  flag[2];
	float f[3];
	float f2[3];
	short offset[20];
};
struct MOGP
{
	unsigned group_name_offset;
	unsigned d_group_name_offset;

};
struct MOVI
{
	unsigned long length;
	
};
struct MOVT
{
	unsigned long length;
}; 
struct WmoInfo
{
	string name;
	Position position;
	//Vector3 position;
	//Vector3 rotation;
	unsigned long id;
};
class WMO
{
public: 
	string name;
	MOGP  mogp;
	Vector3 * vertices;
	unsigned long vertice_count;
	unsigned short * indices;
	unsigned long index_count;
	bool exist;
	WMO(string path);
	~WMO();
};
class RootWMO
{
public:
	string name;
	unsigned long id;
	//MOGN  * mogn;
	//MOGI * mogi;
	vector <WMO*> group;
	//vector<MOGP*> mogp_list;
	RootWMO(string path);
	~RootWMO(void);
};


