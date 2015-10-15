#pragma once
#include <string>
#include "M2.h"
#include "MapEntity.h"
using namespace std;
class Doodad: public MapEntity
{
public:
	unsigned long id;
	string name;
	//M2 * m2;
	float scale;
	//vector<Mesh*> meshes;
	Doodad(string path, M2Info info);
	~Doodad(void);
};
