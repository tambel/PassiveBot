#include "Renderable.h"


Renderable::Renderable(void)
{
	vertice_count=0;
	index_count=0;
	vertices=0;
	indices=0;
}


Renderable::~Renderable(void)
{
	delete [] vertices;
	delete [] indices;
}