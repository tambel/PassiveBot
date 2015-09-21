// PassiveBot.cpp: определяет точку входа для консольного приложения.
//
#pragma once
#include "stdafx.h"
#include <ObjectManager.h>
#include <FrameManager.h>
#include <MemLib.h>
#include <GameInteractor.h>
#include <iostream>

using namespace ProcessLib;
using namespace Wow;
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale( LC_ALL,"Russian" );
	//Process::Initialize();
	GameInteractor::StartGame();
	ObjectManager::Initialize();
	ObjectManager::EnumAllVisibleObjects();
	cout<<"Game Objects"<<endl;
	for (auto game_object:*ObjectManager::GetGameObjectsList())
	{
		//wcout<<((WowObject *)game_object)->GetName()<<endl;
	}
	FrameManager::EnumAllFrames();
	//cout<<FrameManager::GetScreenWidth()<<endl<<FrameManager::GetScreenHeigth()<<endl;
	//Process::MoveMouse(683,384);
	//Frame * f=FrameManager::FindFrameByName("ContainerFrame1");
	//Frame * f=FrameManager::FindFrameByName("AuctionFrame");
	//Frame * f=FrameManager::FindFrameByName("ContainerFrame1Item1");
	//Frame * f=FrameManager::FindFrameByName("AccountLoginAccountEdit");
	int i;



	cin>>i;
	return 0;
}

