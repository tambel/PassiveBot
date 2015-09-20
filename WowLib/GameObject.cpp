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
		if (!name || refresh)
		{
			name= Process::ReadString_UTF8(Process::ReadUInt(Process::ReadUInt(base+WowOffsets::GameObject::GameObjectNameCache)+WowOffsets::GameObject::GameObjectNameOffset),0);
		}
		return name;
	}
}