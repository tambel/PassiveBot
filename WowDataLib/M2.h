#pragma once
#include <string>
#include <vector>
#include "Mesh.h"
using namespace std;
class M2
{
public:
	vector<Mesh*> meshes;
	M2(string path);
	~M2(void);
};

