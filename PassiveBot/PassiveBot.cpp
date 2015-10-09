// PassiveBot.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#pragma once

#include "stdafx.h"
#include <Graphics\MapView.h>
#include "WowLib\Utils.h"

#include "WowLib\ObjectManager.h"
#include "WowLib\FrameManager.h"
#include <ProcessLib\MemLib.h>
#include "WowLib\GameInteractor.h"
#include "WowLib\GameManager.h"

#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <boost\thread\thread.hpp>
using namespace Wow;

//using namespace ProcessLib;
void workerFunc(MapView * view)  
{  

	view->go();

}
int _tmain(int argc, _TCHAR* argv[])
{

	setlocale( LC_ALL,"Russian" );


	Sleep(5000);
	
	GameStartParam  param= GameStartParam();
	param.char_name=L"���������";
	param.login="lissek7@ya.ru";
	param.password="lebmat2762066";

	bool y=GameInteractor::Start(&param);
	ObjectManager::Initialize();
	ObjectManager::EnumAllVisibleObjects();
	Player * player = ObjectManager::GetPlayer();
	MapView * view=new MapView();
	Position p = player->GetPosition();
	view->map=new WowMap(Utils::WowTypes::Vector3(p.coords.x,p.coords.y,p.coords.z));
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

