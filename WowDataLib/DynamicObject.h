#pragma once
#include "MapEntity.h"
using namespace Utils::WowTypes;
class DynamicObject: public MapEntity
{
	
public:
	DynamicObject(void);
	~DynamicObject(void);
	void SetPosition();
};

