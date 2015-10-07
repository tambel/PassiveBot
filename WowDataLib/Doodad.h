#pragma once
#include <string>
#include "M2.h"
using namespace std;
class Doodad
{
public:
	string name;
	M2 * m2;
	Vector3 position;
	Vector3 rotation;
	vector<Mesh*> meshes;
	Doodad(string path, M2Info info);
	~Doodad(void);
};

