#include "Unit.h"
#include "MemLib.h"
#include "offsets.h"
using namespace ProcessLib;
namespace Wow
{
	Unit::Unit(unsigned base):WowObject(base)
	{
	}


	Unit::~Unit(void)
	{
	}
	wchar_t * Unit::GetName(bool refresh)
	{
		if (!name || refresh)
		{
			name= Process::ReadString_UTF8(Process::ReadUInt(Process::ReadUInt(base+WowOffsets::Unit::UnitNameCache)+WowOffsets::Unit::UnitNameOffset),0);
		}
		return name;
	}
}
