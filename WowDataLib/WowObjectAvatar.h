#pragma once
#include "Doodad.h"
#include "WowLib\WowObject.h"
class WowObjectAvatar
{
public:
	Wow::WowObject * wow_object;
	Doodad * doodad;
	WowObjectAvatar();
	WowObjectAvatar(Wow::WowObject * wow_object);
	~WowObjectAvatar(void);
	Position   GetPosition();
};

