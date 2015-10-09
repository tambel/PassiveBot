#pragma once
#include "Utils.h"
using namespace Utils;

class MapEntity
{
protected:
	
public:
	unsigned long id;
	Vector3 position;
	Vector3 rotation;
	MapEntity(void);
	~MapEntity(void);
	void SetPosition();
};

