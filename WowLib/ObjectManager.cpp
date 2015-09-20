#pragma once
#include "ObjectManager.h"
#include <MemLib.h>
#include <iostream>
#include "offsets.h"
using namespace ProcessLib;
//using namespace WowOffsets;
namespace Wow
{
	unsigned ObjectManager::base;
	vector<GameObject*> ObjectManager::game_objects=vector<GameObject*>();
	vector<Item*> ObjectManager::items=vector<Item*>();
	void ObjectManager::EnumAllVisibleObjects()
	{
		ClearAllLists();
		unsigned curobject=Process::ReadUInt(base+WowOffsets::ObjectManager::FirstObject);
		int count=0;
		while (curobject!=0)
		{
			switch (WowObject::GetType_Static(curobject))
			{
			case ObjectType::GAMEOBJECT:
				{
					game_objects.push_back(new GameObject(curobject));
					GameObject gj=GameObject(curobject);
					wchar_t * name=gj.GetName();
					break;
				}
			case ObjectType::ITEM:
				{
					items.push_back(new Item(curobject));
					break;
				}
			}

			curobject=Process::ReadUInt(curobject+WowOffsets::ObjectManager::NextObject);

		}
	}
	void ObjectManager::Initialize()
	{

		base=Process::ReadUInt(Process::ReadUInt(Process::GetProcessBase()+WowOffsets::ObjectManager::ObjectPanagerPtr)+WowOffsets::ObjectManager::ObjectManagerOffset);
	}
	
	vector<GameObject*> *ObjectManager::GetGameObjectsList()
	{
			return &game_objects;
	}
	vector<Item*> *ObjectManager::GetItemsList()
	{
			return &items;
	}

	void ObjectManager::ClearAllLists()
	{
		for(auto game_object: game_objects)
		{
			delete game_object;
		}
		for(auto item: items)
		{
			delete item;
		}
		game_objects.clear();
		items.clear();
	}
}
 