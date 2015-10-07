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
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
#include <boost\thread\thread.hpp>
using namespace DataUtils;

//using namespace ProcessLib;
using namespace Wow;
using namespace std;
void workerFunc()  
{  
	MapView view=MapView();
	view.go();
	/*
	WowMap map(DataUtils::Vector3(0,0,0));
	WowMap map2(DataUtils::Vector3(0,0,0));
	WowMap map3(DataUtils::Vector3(0,0,0));
	WowMap map4(DataUtils::Vector3(0,0,0));
	WowMap map5(DataUtils::Vector3(0,0,0));
	WowMap map6(DataUtils::Vector3(0,0,0));
	WowMap map7(DataUtils::Vector3(0,0,0));
	*/

}
int _tmain(int argc, _TCHAR* argv[])
{
	/*
	setlocale( LC_ALL,"Russian" );
	
	
	Sleep(5000);
	GameStartParam  param= GameStartParam();
	param.char_name=L"Люблюдашу";
	param.login="lissek7@ya.ru";
	param.password="lebmat2762066";

	bool y=GameInteractor::Start(&param);
	ObjectManager::Initialize();
	ObjectManager::EnumAllVisibleObjects();
	Unit * tak=ObjectManager::FindUnitByName(L"Огромный серый кодо");
	Player * player = ObjectManager::GetPlayer();

	ObjectManager::ClearAllLists();
	FrameManager::ClearFrames();
	delete FrameManager::GetFrames();
	delete ObjectManager::GetGameObjectsList();
	delete ObjectManager::GetItemsList();
	delete ObjectManager::GetPlayersList();
	delete ObjectManager::GetUnitsList();
	*/

	//workerFunc();
	//_CrtDumpMemoryLeaks();
	
	 boost::thread workerThread(workerFunc);
	// workerThread.detach();
	workerThread.join();
	 

	return 0;
}

