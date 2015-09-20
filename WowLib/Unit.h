#pragma once
#include "WowObject.h"
namespace Wow
{
	class Unit: public WowObject
	{
	public:
		Unit(unsigned base);
		~Unit(void);
	};
}

