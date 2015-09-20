#include "Item.h"
#include <MemLib.h>
#include "offsets.h"
using namespace ProcessLib;
namespace Wow
{
	Item::Item(unsigned base):WowObject(base)
	{
	}


	Item::~Item(void)
	{
	}
	wchar_t * Item::GetName(bool refresh)
	{
		if (!name)
		{
			name = Process::ReadString_UTF8(Process::ReadUInt(Process::ReadRel(WowOffsets::Item::CachePtr+0x28)+4*(GetID()-Process::ReadRel(WowOffsets::Item::CachePtr+0x14)))+0x198,0);
		}
		return name;
	}
}
