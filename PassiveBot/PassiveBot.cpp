// PassiveBot.cpp: определяет точку входа для консольного приложения.
//
#pragma once

#include "stdafx.h"
#include <Graphics\MapFrame.h>

#include <ProcessLib\MemLib.h>

#include "WowLib\Utils.h"
#include "WowLib\ObjectManager.h"
#include "WowLib\FrameManager.h"
#include "WowLib\GameInteractor.h"
#include "WowLib\GameManager.h"

#include "WowDataLib\Adt.h"
#include "WowDataLib\SquareArea.h"


#include "WowDataLib\ADTWorker.h"
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <boost\thread\thread.hpp>
using namespace Wow;
using namespace Utils;

//using namespace ProcessLib;

void workerFunc(MapFrame * frame, Position pos)  
{  
	
	frame->go();
	frame->SetCamera(pos);

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
	Vector3 pos=player->GetPosition().coords;
	player->DumpPosition();
	if (!Game::LocationBase::IsInitialized())
		Game::LocationBase::Init(); 
	
	MapFrame * frame=new MapFrame();
	SquareArea * area=new SquareArea(Game::LocationBase::Get("Kalimdor"),Utils::WorldPositionToBlockCoords(player->GetPosition().coords),Utils::WorldPositionToChunkCoords(player->GetPosition().coords),5);//Point2D<int>(0,1),10);
	area->AddWowObjectAvatar(player);
	frame->SetArea(area);
	

	//ADT * a=new ADT(Game::LocationBase::Get("Kalimdor"),Utils::WorldPositionToMapBlockCoords(player->GetPosition().coords));
	//ADT * b=new ADT(Game::LocationBase::Get("Kalimdor"),Utils::WorldPositionToMapBlockCoords(player->GetPosition().coords));
	//Chunk * c=ADTWorker::GetChunk(Game::LocationBase::Get("Kalimdor"),Utils::WorldPositionToMapBlockCoords(player->GetPosition().coords),Point2D<int>(0,0));
	//c=ADTWorker::GetChunk(Game::LocationBase::Get("Kalimdor"),Utils::WorldPositionToMapBlockCoords(player->GetPosition().coords),Point2D<int>(0,1));
	


	boost::thread thread(workerFunc,frame,player->GetPosition());
	thread.detach();
	thread.join();

	while (1)
	{

		area->Move(Game::LocationBase::Get("Kalimdor"),Utils::WorldPositionToBlockCoords(player->GetPosition().coords),Utils::WorldPositionToChunkCoords(player->GetPosition().coords));

		// area=new SquareArea(Game::LocationBase::Get("Kalimdor"),Utils::WorldPositionToBlockCoords(player->GetPosition().coords),Utils::WorldPositionToChunkCoords(player->GetPosition().coords),10);//Point2D<int>(0,1),10);
	
		Sleep(500);
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

