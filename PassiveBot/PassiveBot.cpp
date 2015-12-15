// PassiveBot.cpp: определяет точку входа для консольного приложения.
//
#pragma once

#include "stdafx.h"
//#include <Graphics\MapView.h>
#include <ProcessLib\MemLib.h>

#include "WowLib\Utils.h"
#include "WowLib\ObjectManager.h"
#include "WowLib\FrameManager.h"
#include "WowLib\GameInteractor.h"
#include "WowLib\GameManager.h"

#include "WowDataLib\Adt.h"

#include "WowDataLib\ADTWorker.h"
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <boost\thread\thread.hpp>
using namespace Wow;
using namespace Utils;

//using namespace ProcessLib;
/*
void workerFunc(MapView * view)  
{  

view->go();

}
*/
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
	Vector3 pos=player->GetPosition().coords;
	player->DumpPosition();

	if (!Game::LocationBase::IsInitialized())
		Game::LocationBase::Init();
	//ADT * a=new ADT(Game::LocationBase::Get("Kalimdor"),Utils::WorldPositionToMapBlockCoords(player->GetPosition().coords));
	//ADT * b=new ADT(Game::LocationBase::Get("Kalimdor"),Utils::WorldPositionToMapBlockCoords(player->GetPosition().coords));
	Chunk * c=ADTWorker::GetChunk(Game::LocationBase::Get("Kalimdor"),Utils::WorldPositionToMapBlockCoords(player->GetPosition().coords),Point2D<int>(0,1));
	//c=ADTWorker::GetChunk(Game::LocationBase::Get("Kalimdor"),Utils::WorldPositionToMapBlockCoords(player->GetPosition().coords),Point2D<int>(0,1));

	///boost::thread thread(workerFunc, view);
	//thread.detach();
	//thread.join();
	while (1)
	{
		player->DumpPosition();
		Sleep(50);
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

