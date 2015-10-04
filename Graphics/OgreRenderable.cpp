#include "OgreRenderable.h"

unsigned long OgreRenderable::current_uid=0;

unsigned long OgreRenderable::GetUIDAndIncrement()
{
	return current_uid++;
}
void OgreRenderable::ClearCouner()
{
	current_uid=0;
}