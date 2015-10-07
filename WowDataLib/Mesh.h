#pragma once
#include "Renderable.h"
#include <string>
using namespace std;
class Mesh: public Renderable
{
protected:
	
public:
	string name;
	Mesh(string name);
	~Mesh();
};

