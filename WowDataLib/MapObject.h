#pragma once
#include "Renderable.h"
#include <string>
#include <vector>
#include "WMO.h"
#include "Mesh.h"
using namespace std;
class MapObject: public Renderable
{

public:
	string name;
	RootWMO * root_wmo;
	Vector3 position;
	vector<Mesh*> meshes;
	MapObject(string path, WmoInfo wmo_info);
	~MapObject(void);
};

