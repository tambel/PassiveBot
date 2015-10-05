// PassiveBot.cpp: определяет точку входа для консольного приложения.
//
#pragma once

#include "stdafx.h"
#include <MapView.h>
#include <ObjectManager.h>
#include <FrameManager.h>
#include <MemLib.h>
#include <GameInteractor.h>
#include <GameManager.h>
#include <Utils.h>
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h> 
#include <boost\thread\thread.hpp>

#define _CRTDBG_MAP_ALLOC
//using namespace ProcessLib;
using namespace Wow;
using namespace std;
void workerFunc()  
{  
	MapView view=MapView();
	view.go();
}
int _tmain(int argc, _TCHAR* argv[])
{
	
	setlocale( LC_ALL,"Russian" );
	
	
	Sleep(5000);
	GameStartParam  param= GameStartParam();
	param.char_name=L"Люблюдашу";
	param.login="lissek7@ya.ru";
	param.password="lebmat2762066";
	/*
	bool y=GameInteractor::Start(&param);
	ObjectManager::Initialize();
	ObjectManager::EnumAllVisibleObjects();
	Unit * tak=ObjectManager::FindUnitByName(L"Огромный серый кодо");
	Player * player = ObjectManager::GetPlayer();
	*/



	
	//_CrtDumpMemoryLeaks();
	 boost::thread workerThread(workerFunc);
	 //workerThread.detach();
	 workerThread.join();

	 int i;
	 while (1)
	 {
		 
		// cout<<"X "<<player->GetPosition().coords.x<<"Y "<<player->GetPosition().coords.y<<"Z "<<player->GetPosition().coords.z<<endl;
		// cout<<"X "<<floor((32 - (player->GetPosition().coords.x / 533.33333)))<<"Y "<< floor((32 - (player->GetPosition().coords.y / 533.33333)))<<endl;
	 }
	 ObjectManager::ClearAllLists();
	FrameManager::ClearFrames();
	delete FrameManager::GetFrames();
	delete ObjectManager::GetGameObjectsList();
	delete ObjectManager::GetItemsList();
	delete ObjectManager::GetPlayersList();
	delete ObjectManager::GetUnitsList();
	
	return 0;
}

