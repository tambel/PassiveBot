#pragma once
#include <string>
#include <vector>
#include "Utils.h"
using namespace std;
struct MOGN
{

	short length;
	unsigned wtf;
	char * group_names;
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
	unsigned short * indices;
};
struct MOVT
{
	unsigned long length;
	Vector3 * vetices;
}; 
struct WmoInfo
{
	string name;
	Vector3 position;
	Vector3 rotation;
	unsigned long id;
};
class WMO
{
public: 
	string name;
	MOGP * mogp;
	MOVI * movi;
	MOVT * movt;
	bool exist;
	WMO(string path);
	~WMO();
};
class RootWMO
{
public:
	string name;
	MOGN  * mogn;
	MOGI * mogi;
	vector <WMO*> groups;
	vector<MOGP*> mogp_list;
	RootWMO(string path);
	~RootWMO(void);
};


