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
	GameInteractor::StartClient();
	//Frame * f=FrameManager::FindFrameByName("ContainerFrame1");
	//Frame * f=FrameManager::FindFrameByName("AuctionFrame");
	//Frame * f=FrameManager::FindFrameByName("ContainerFrame1Item1");
	//Frame * f=FrameManager::FindFrameByName("AccountLoginAccountEdit");

	//GameInteractor::Test();



	GameInteractor::Login("arttambel@gmail.com","archi911");
	GameInteractor::WaitForAuthentification();
	GameInteractor::CheckForPromoFrames();
	Sleep(10000);
	FrameManager::EnumAllFrames();
	vector<Frame*> * frames=FrameManager::GetFrames();
	Frame *frame1=FrameManager::FindFrameByName("CharSelectCharacterButton1");
	frame1->MoveMoseToFrame();
	Process::MouseClick();
	Process::MouseClick();
	int i;
	cin>>i;
	return 0;
}

