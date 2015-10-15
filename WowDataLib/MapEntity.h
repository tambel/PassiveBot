#pragma once
#include "Utils.h"
#include "Mesh.h"
#include<vector>
using namespace std;
using namespace Utils;
class MapEntity
{
	unsigned long id;
	static unsigned long id_counter;
protected:
	
public:
	MapEntity(void);
	virtual ~MapEntity(void);
	bool changed;
	vector<Mesh*> meshes;
	bool dynamic;
	bool visible;
	Position position;
	
	void SetPosition(Position position);
	unsigned long  GetID();
};

