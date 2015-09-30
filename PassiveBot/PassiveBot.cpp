// PassiveBot.cpp: определяет точку входа для консольного приложения.
//
#pragma once

#include "stdafx.h"
#include <GameView.h>
#include <ObjectManager.h>
#include <FrameManager.h>
#include <MemLib.h>
#include <GameInteractor.h>
#include <GameManager.h>
#include <Utils.h>
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h> 

#define _CRTDBG_MAP_ALLOC
//using namespace ProcessLib;
using namespace Wow;
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	
	setlocale( LC_ALL,"Russian" );
	
	/*
	Sleep(5000);
	GameStartParam  param= GameStartParam();
	param.char_name=L"Люблюдашу";
	param.login="lissek7@ya.ru";
	param.password="lebmat2762066";
	
	bool y=GameInteractor::Start(&param);
	ObjectManager::Initialize();
	ObjectManager::EnumAllVisibleObjects();
	Unit * tak=ObjectManager::FindUnitByName(L"Огромный серый кодо");
	//while(1)
	{
		//GameManager::WorldToScreen(tak->GetPosition());
		GameManager::ClickToMove(tak->GetPosition());
	}




	ObjectManager::ClearAllLists();
	FrameManager::ClearFrames();
	delete FrameManager::GetFrames();
	delete ObjectManager::GetGameObjectsList();
	delete ObjectManager::GetItemsList();
	delete ObjectManager::GetPlayersList();
	delete ObjectManager::GetUnitsList();
	_CrtDumpMemoryLeaks();
	*/
	
	GameView view=GameView();
	view.go();
	return 0;
}

