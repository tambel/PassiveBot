#pragma once
#include "Utils.h"
#include <string>

using namespace DataUtils;
using namespace std;
class Renderable
{
protected:
	string name;
public:
	Triangle * triangles;
	unsigned long triangles_count;
	Vector3 position;
	Vector3 rotation;
	Vertice  * vertices;
	unsigned long vertice_count;
	unsigned long index_count;
	unsigned short * indices;
	Renderable(void);
	~Renderable(void);


};

