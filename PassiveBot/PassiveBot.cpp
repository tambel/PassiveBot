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
	//GameInteractor::StartClient();
	//Frame * f=FrameManager::FindFrameByName("ContainerFrame1");
	//Frame * f=FrameManager::FindFrameByName("AuctionFrame");
	//Frame * f=FrameManager::FindFrameByName("ContainerFrame1Item1");
	//Frame * f=FrameManager::FindFrameByName("AccountLoginAccountEdit");

	//GameInteractor::Test();
	Sleep(5000);
	GameStartParam * param=new GameStartParam();
	param->char_name=L"Василующий";
	param->login="arttambel@gmail.com";
	param->password="archi911";
	bool y=GameInteractor::Start(param);
	

	//GameInteractor::Login("arttambel@gmail.com","archi911");
	//GameInteractor::SelectCharacter(L"Василующий");
	int i;
	cin>>i;
	return 0;
}

