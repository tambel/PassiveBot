// PassiveBot.cpp: определяет точку входа для консольного приложения.
//
#pragma once
#include "stdafx.h"
#include <ObjectManager.h>
#include <MemLib.h>
#include <iostream>
using namespace ProcessLib;
using namespace Wow;
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale( LC_ALL,"Russian" );
	Process::Init();
	ObjectManager::Initialize();
	ObjectManager::EnumAllVisibleObjects();
	cout<<"Game Objects"<<endl;
	for (auto game_object:*ObjectManager::GetGameObjectsList())
	{
		wcout<<game_object->GetName()<<endl;
	}
	cout<<"Items"<<endl;
	for (auto item:*ObjectManager::GetItemsList())
	{
		wcout<<item->GetName()<<endl;
	}
	int i;
	cin>>i;
	return 0;
}

