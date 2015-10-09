#pragma once
#include "Utils.h"
#include "Mesh.h"
#include<vector>
using namespace std;
using namespace Utils;

class MapEntity
{
protected:
	
public:
	vector<Mesh*> meshes;
	unsigned long id;
	Vector3 position;
	Vector3 rotation;
	MapEntity(void);
	~MapEntity(void);
	void SetPosition();
};

