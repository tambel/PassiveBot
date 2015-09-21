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
	//Process::Init();
	GameInteractor::Start();
	//ObjectManager::Initialize();
	//ObjectManager::EnumAllVisibleObjects();
	//cout<<FrameManager::GetScreenWidth()<<endl<<FrameManager::GetScreenHeigth()<<endl;
	//Process::MoveMouse(683,384);
	//Frame * f=FrameManager::FindFrameByName("ContainerFrame1");
	//Frame * f=FrameManager::FindFrameByName("AuctionFrame");
	//Frame * f=FrameManager::FindFrameByName("ContainerFrame1Item1");
	//Frame * f=FrameManager::FindFrameByName("AccountLoginAccountEdit");
	int i;
	//cin>>i;
	GameInteractor::Login("arttambel@gmail.com","archi911");
	//Process::MoveMouse(65000,65535);


	cin>>i;
	return 0;
}

