#pragma once
#include "Renderable.h"
#include <string>
using namespace std;
class Mesh: public Renderable
{
protected:
	string name;
public:
	Mesh(string name);
	~Mesh(void);
};

