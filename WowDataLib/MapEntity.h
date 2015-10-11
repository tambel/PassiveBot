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
	bool changed;
	vector<Mesh*> meshes;
	unsigned long id;
	Position position;
	MapEntity(void);
	~MapEntity(void);
	void SetPosition(Position position);
};

