#include "GameObject.h"
#include <MemLib.h>
#include "offsets.h"
using namespace ProcessLib;
namespace Wow
{

	GameObject::GameObject(unsigned base):WowObject(base)
	{
	}


	GameObject::~GameObject(void)
	{

	}
	wchar_t * GameObject::GetName(bool refresh)
	{
		if (!name)
		{
			name= Process::ReadString_UTF8(Process::ReadUInt(Process::ReadUInt(base+WowOffsets::GameObject::NamePtr)+WowOffsets::GameObject::NameOffset),0);
		}
		return name;
	}
}