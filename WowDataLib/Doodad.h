#pragma once
#include <string>
#include "M2.h"
#include "MapEntity.h"
using namespace std;
class Doodad: public MapEntity
{
public:
	string name;
	M2 * m2;
	vector<Mesh*> meshes;
	Doodad(string path, M2Info info);
	~Doodad(void);
};

