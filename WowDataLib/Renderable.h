#pragma once
#include "Utils.h"
#include <string>

using namespace Utils::WowTypes; 
using namespace Utils::Graphics;
using namespace std;

class Renderable
{
protected:
	string name;
public:
	bool changed;
	Triangle * triangles;
	unsigned long triangles_count;
	Position position;
	//Vector3 position;
	Vector3 rotation;
	Vertice  * vertices;
	unsigned long vertice_count;
	unsigned long index_count;
	unsigned short * indices;
	unsigned long * l_indices;
	Renderable(void);
	~Renderable(void);
};

