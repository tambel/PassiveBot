// PassiveBot.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#pragma once
#include "stdafx.h"
#include <ObjectManager.h>
#include <FrameManager.h>
#include <MemLib.h>
#include <iostream>

using namespace ProcessLib;
using namespace Wow;
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale( LC_ALL,"Russian" );
	Process::Init();
	ObjectManager::Initialize();
	ObjectManager::EnumAllVisibleObjects();
	cout<<"Game Objects"<<endl;
	for (auto game_object:*ObjectManager::GetGameObjectsList())
	{
		//wcout<<((WowObject *)game_object)->GetName()<<endl;
	}
	FrameManager::EnumAllFrames();
	cout<<FrameManager::GetScreenWidth()<<endl<<FrameManager::GetScreenHeigth()<<endl;
	//Process::MoveMouse(683,384);
	Frame * f=FrameManager::FindFrameByName("ContainerFrame1");
	Frame*  p=f->GetParent();
	int i;
	cin>>i;
	return 0;
}

