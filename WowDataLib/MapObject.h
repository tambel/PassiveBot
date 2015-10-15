#pragma once
#include "Renderable.h"
#include <string>
#include <vector>
#include "WMO.h"
#include "Mesh.h"
#include "MapEntity.h"
using namespace std;
class MapObject:public MapEntity
{
public:
	unsigned long id;
	string name;
	//RootWMO * root_wmo;
	//vector<Mesh*> meshes;
	MapObject(string path, WmoInfo wmo_info);
	~MapObject(void);
};

