// PassiveBot.cpp: определяет точку входа для консольного приложения.
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
	param.char_name=L"Люблюдашу";
	param.login="lissek7@ya.ru";
	param.password="lebmat2762066";

	bool y=GameInteractor::Start(&param);
	ObjectManager::Initialize();
	ObjectManager::EnumAllVisibleObjects();
	Player * player = ObjectManager::GetPlayer();
	MapView * view=new MapView();
	Position p = player->GetPosition();
	view->map=new WowMap(p.coords);
	
	boost::thread thread(workerFunc, view);
	thread.detach();
	thread.join();

	view->map->AddDynamicObject(player);
	view->SetWorldCamera(GameManager::GetCamera());
	view->map->to_update=true;
	/*
	M2Info info;
	info.position=p;
	info.scale=1.0f;
	Doodad * player_model=new Doodad("E:\\Extracted\\Character\\Tauren\\Male\\TaurenMale.M2",info);
	view->map->new_objects.push_back((MapEntity*)player_model);
	view->map->new_object=true;
	*/
	
	//Sleep(30000);
//	view->update=true;
	while(1)
	{
		if (view->map->CheckForTileChange(player->GetPosition().coords))
		{
			if (!view->map->busy)
			{
				view->map->GoToPlace(player->GetPosition().coords);
				view->map->to_redraw=true;
			}
		}
		//while(view->map->new_object);
		player->DumpPosition();
		//player_model->position=player->GetPosition();
		//player_model->changed=true;
		Sleep(10);
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

