#pragma once
#include "MapEntity.h"
#include "WowLib\WowObject.h"
using namespace Utils::WowTypes;
class DynamicObject
{
	MapEntity * entity;
	
public:
	bool is_new;
	bool to_delete;
	Wow::WowObject * object;
	DynamicObject(Wow::WowObject * obj);
	~DynamicObject(void);
	void SetEntity(Wow::WowObject * obj);
	MapEntity* GetEntity();
};

