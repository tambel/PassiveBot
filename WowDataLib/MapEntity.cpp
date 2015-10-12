#include "MapEntity.h"


MapEntity::MapEntity(void)
{
	visible=true;
}


MapEntity::~MapEntity(void)
{
}
void MapEntity::SetPosition(Position position)
{
	this->position=position;
}