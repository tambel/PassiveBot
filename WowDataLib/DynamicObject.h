#pragma once
#include "Renderable.h"
class DynamicObject: public Renderable
{
	Vector3 position;
	Vector3 rotation;
public:
	DynamicObject(void);
	~DynamicObject(void);
};

