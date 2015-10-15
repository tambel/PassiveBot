#include "DynamicObject.h"
#include "Doodad.h"

DynamicObject::DynamicObject(Wow::WowObject * obj)
{
	is_new=true;
	to_delete=false;
	SetEntity(obj);
}


DynamicObject::~DynamicObject(void)
{
	delete entity;
}
void DynamicObject::SetEntity(Wow::WowObject * obj)
{
	M2Info info;
	info.scale=1.0f;
	object=obj;
	entity=new Doodad("E:\\Extracted\\Character\\Tauren\\Male\\TaurenMale.M2",info);
	entity->position=obj->GetPosition();
}
MapEntity * DynamicObject::GetEntity()
{
	return entity;
}
