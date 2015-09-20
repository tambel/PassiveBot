#include "WowObject.h"
#include "MemLib.h"
#include "offsets.h"
using namespace ProcessLib;

namespace Wow
{
	WowObject::WowObject(unsigned base)
	{
		SetBase(base);
		name=0;
		type=0;
		guid=Guid128();
	}


	WowObject::~WowObject(void)
	{
		if (name)
			delete name;
	}

	void WowObject::SetBase(unsigned base)
	{
		this->base=base;

	}
	char WowObject::GetType(bool refresh)
	{
		if (!type)
		{
			type=Process::ReadUInt(base+WowOffsets::Object::Type);
		}
		return type;
	}
	wchar_t * WowObject::GetName(bool refresh)
	{
		return 0;
	}
	char WowObject::GetType_Static(unsigned base)
	{
		return Process::ReadUInt(base+WowOffsets::Object::Type);
	}
	unsigned WowObject::GetID(bool refresh)
	{
		return Process::ReadUInt(Process::ReadUInt(base+WowOffsets::Descriptors)+WowOffsets::Object::EntityID);
	}
	Guid128 * WowObject::GetGuid(bool refresh)
	{
		if (!guid)
		{
			Process::ReadRaw(Process::ReadUInt(base+WowOffsets::Descriptors),&guid,16);
		}
		return &guid;
	}
}
