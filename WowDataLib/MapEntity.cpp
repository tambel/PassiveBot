#include "MapEntity.h"

unsigned long MapEntity::id_counter=0;
MapEntity::MapEntity(void)
{
	id=id_counter;
	id_counter++;
	visible=true;
	dynamic=false;
}


MapEntity::~MapEntity(void)
{
	for (auto mesh:meshes)
	{
		delete mesh;
	}
	meshes.clear();
}
void MapEntity::SetPosition(Position position)
{
	this->position=position;
}
unsigned long MapEntity::GetID()
{
	return id;
}