// PassiveBot.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <ClientManager.h>
#include <MemLib.h>
#include <iostream>
using namespace ProcessLib;
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale( LC_ALL,"Russian" );
	Process::Init();
	ClientManager::Initialize();
	ClientManager::EnumAllVisibleObjects();
	int i;
	cin>>i;
	return 0;
}

