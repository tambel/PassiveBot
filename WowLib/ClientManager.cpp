#include "ClientManager.h"
#include <MemLib.h>
#include <iostream>
using namespace ProcessLib;


unsigned ClientManager::base;
void ClientManager::EnumAllVisibleObjects()
{
	unsigned curobject=Process::ReadUInt(base+0xD8);
	int count=0;
	while (curobject!=0)
	{
		unsigned n1=Process::ReadUInt(curobject+0x274);
		unsigned n2=Process::ReadUInt(n1+0xB4);
		unsigned name_ptr;
			WCHAR * name;
		if (Process::ReadUInt(curobject+0x274)!=0)
		{

			name_ptr=Process::ReadUInt(Process::ReadUInt(curobject+0x274)+0xB4);
			name =Process::ReadString_UTF8(name_ptr,0);
			if (name)
			wcout<<name<<endl;
		}
		if (count>64)
		{
			name_ptr=0;
		}
		
		curobject=Process::ReadUInt(curobject+0x3C);
		
		count++;
		cout<<count<<endl;
		
	}
	cout<<count;
}
void ClientManager::Initialize()
{

	base=Process::ReadUInt(Process::ReadUInt(Process::GetProcessBase()+0xFF0248)+0x62C);
	int i;
}