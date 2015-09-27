// PassiveBot.cpp: определяет точку входа для консольного приложения.
//
#pragma once
#include "stdafx.h"
#include <ObjectManager.h>
#include <FrameManager.h>
#include <MemLib.h>
#include <GameInteractor.h>
#include <GameManager.h>
#include <Utils.h>
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
	param->char_name=L"Люблюдашу";
	param->login="lissek7@ya.ru";
	param->password="lebmat2762066";
	bool y=GameInteractor::Start(param);
	FrameManager::EnumAllFrames();
	Frame * f =FrameManager::FindFrameByName("ContainerFrame1");
	//f->MoveMoseToFrame();
	ObjectManager::Initialize();
	ObjectManager::EnumAllVisibleObjects();
	Player * p=ObjectManager::GetPlayer();
	Position pos=p->GetPosition();
	Unit * tak=ObjectManager::FindUnitByName(L"Так");
	//GameManager::WorldToScreen(tak->GetPosition());
	GameManager::WorldToScreen(pos);
	int at=0;
	while (1)
	{
		/*
		Camera * cam=GameManager::GetCamera();
		
		cout<<"Player position"<<endl;
		cout<<pos.coords.x<<" "<<pos.coords.y<<" "<<pos.coords.z<<endl<<"Rotation "<<pos.rotation<<endl;
		cout<<"Camera position"<<endl;
		cout<<cam->GetPosition(true).coords.x<<" "<<cam->GetPosition(true).coords.y<<" "<<cam->GetPosition(true).coords.z<<endl<<"Rotation "<<cam->GetPosition(true).rotation<<endl;
		cout<<"FOV "<<cam->GetFOV(true)<<endl<<"Near "<<cam->GetNearClip(true)<<" Far "<<cam->GetFarClip(true)<<endl;
		cout<<"Camera matrix"<<endl;
		float tmp[3][3];
		memcpy(tmp,cam->GetMatrix(true),36);
		for (int i=0;i<3;i++)
		{
			for (int j=0;j<3;j++)
			{
				cout<<tmp[i][j]<<" ";
			}
			cout<<endl;
		}
		*/
		GameManager::WorldToScreen(tak->GetPosition());
		Sleep(10);
	}
	int i;
	cin>>i;
	return 0;
}

