#include "Renderable.h"


Renderable::Renderable(void)
{
	changed=false;
	vertice_count=0;
	index_count=0;
	vertices=0;
	indices=0;
	triangles=0;
	triangles_count=0;
}


Renderable::~Renderable(void)
{
	delete [] vertices;
	vertices=0;
	vertice_count=0;
	delete [] indices;
	indices=0;
	index_count=0;
	delete [] triangles;
	triangles=0;
}