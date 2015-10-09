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
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <boost\thread\thread.hpp>
using namespace DataUtils;

//using namespace ProcessLib;
using namespace Wow;
using namespace std;
void workerFunc(MapView * view)  
{  

	view->go();

}
int _tmain(int argc, _TCHAR* argv[])
{

	setlocale( LC_ALL,"Russian" );


	Sleep(5000);
	GameStartParam  param= GameStartParam();
	param.char_name=L"Люблюдашу";
	param.login="lissek7@ya.ru";
	param.password="lebmat2762066";

	bool y=GameInteractor::Start(&param);
	ObjectManager::Initialize();
	ObjectManager::EnumAllVisibleObjects();
	Player * player = ObjectManager::GetPlayer();
	MapView * view=new MapView();
	Position p = player->GetPosition();
	view->map=new WowMap(DataUtils::Vector3(p.coords.x,p.coords.y,p.coords.z));
	boost::thread thread(workerFunc, view);
	thread.detach();
	thread.join();
	while(1)
	{
		player->DumpPosition();
	}




	ObjectManager::ClearAllLists();
	FrameManager::ClearFrames();
	delete FrameManager::GetFrames();
	delete ObjectManager::GetGameObjectsList();
	delete ObjectManager::GetItemsList();
	delete ObjectManager::GetPlayersList();
	delete ObjectManager::GetUnitsList();

	//_CrtDumpMemoryLeaks();




	return 0;
}

