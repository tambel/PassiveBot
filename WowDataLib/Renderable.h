#pragma once
#include "Utils.h"
class Renderable
{
	
public:
	Vector3 position;
	Vertice  * vertices;
	unsigned long vertice_count;
	unsigned long index_count;
	unsigned short * indices;
	Renderable(void);
	~Renderable(void);
	void SetPosition(Vector3 position);

};

