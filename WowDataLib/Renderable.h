#pragma once
#include "Utils.h"
class Renderable
{
	
public:
	Vector3 position;
	Vertice  * vertices;
	unsigned * indices;
	Renderable(void);
	~Renderable(void);
	void SetPosition(Vector3 position);

};

