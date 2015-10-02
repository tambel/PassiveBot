#include "Renderable.h"


Renderable::Renderable(void)
{

}


Renderable::~Renderable(void)
{
	delete [] vertices;
	delete [] indices;
}
void Renderable::SetPosition(Vector3 position)
{
	this->position=position;
}