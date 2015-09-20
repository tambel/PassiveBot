#include "MemLib.h"
#include <TlHelp32.h>
using namespace std;
namespace ProcessLib
{
	
#ifdef _WIN32
	HANDLE  Process::process=NULL;
	HWND Process::window=NULL;
	unsigned Process::base_address=0;
	WCHAR * Process::ReadString_UTF8(unsigned address, unsigned long length)
	{
		wchar_t * tmpWCResult;
		wchar_t * tmpResult;
		wchar_t *result;
		MEMORY_BASIC_INFORMATION bi={0};
		VirtualQueryEx(process,(void*)address,&bi,sizeof(bi));
		DWORD real_length=0;
		DWORD resLength=0;
		if (length==0)
		{
			length=1024;
		}
		if (bi.RegionSize-(address-(unsigned)bi.BaseAddress)>=length*2)
		{

			real_length=length;
		}
		else
		{
			real_length=(bi.RegionSize-((DWORD)address-(DWORD)bi.BaseAddress))/2;
		}
		tmpWCResult=new wchar_t[length];
		tmpResult=new wchar_t[length];
		if(!ReadProcessMemory(process,(void*)address,tmpWCResult,real_length*2,NULL))
		{
			return NULL;
		}
		MultiByteToWideChar(65001,0,(LPCCH)tmpWCResult,-1,tmpResult,real_length);
		resLength=wcslen(tmpResult)+1;
		result=new wchar_t[resLength];
		memcpy(result,tmpResult,resLength*2);
		delete tmpWCResult;
		delete tmpResult;
		return result;

	}
	unsigned Process::ReadUInt(unsigned address)
	{
		unsigned result;
		DWORD byte_read; 

		if (!ReadProcessMemory(process,(void*)address,&result,4,&byte_read))
		{
			return 0;
		}

		return result;
	}
	char Process::ReadByte(unsigned address)
	{
		char result;
		DWORD byte_read; 

		if (!ReadProcessMemory(process,(void*)address,&result,1,&byte_read))
		{
			return 0;
		}
		return result;
	}
	bool Process::ReadRaw(unsigned address, void * buffer,unsigned long length)
	{
		DWORD byte_read;
		if (!ReadProcessMemory(process,(void*)address,buffer,length,&byte_read))
		{
			return false;
		}
		return true;
	}
	unsigned Process::ReadRelUInt(unsigned offset)
	{
		return ReadUInt(base_address+offset);
	}
	char * Process::ReadASCII(unsigned address, unsigned long length)
	{
		char * tmp_result;
		char * result;
		MEMORY_BASIC_INFORMATION bi={0};
		VirtualQueryEx(process,(void*)address,&bi,sizeof(bi));
		DWORD real_length=0;
		DWORD res_length=0;
		DWORD byte_read=0;
		if (length==0)
		{
			length=1024;
		}
		if (bi.RegionSize-(address-(unsigned)bi.BaseAddress)>=length)
		{

			real_length=length;
		}
		else
		{
			real_length=(bi.RegionSize-((DWORD)address-(DWORD)bi.BaseAddress));
		}
		tmp_result=new char[real_length];
		if (!ReadProcessMemory(process,(void*)address,tmp_result,real_length,&byte_read))
		{
			return 0;
		}
		res_length=strlen(tmp_result);
		result=new char[res_length+1];
		strcpy(result,tmp_result);
		delete tmp_result;

		return result;

	}
	bool Process::Init()
	{
		DWORD id;
		HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
		MODULEENTRY32 me32;
		window=FindWindow("GXWindowClass","World of Warcraft");
		if (window==NULL)
		{
			return false;
		}

		GetWindowThreadProcessId(window,&id);
		process=OpenProcess(PROCESS_ALL_ACCESS ,NULL,id);
		if (process==NULL)
		{
			return false;
		}

		hModuleSnap = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, id);
		if( hModuleSnap == INVALID_HANDLE_VALUE )
		{
			return false;
		}
		me32.dwSize = sizeof( MODULEENTRY32 );
		// Retrieve information about the first module,
		// and exit if unsuccessful
		if( !Module32First( hModuleSnap, &me32 ) )
		{
			return false;
		}
		base_address=(unsigned)me32.modBaseAddr;
		CloseHandle( hModuleSnap );
		return 1;
	}
	float Process::ReadFloat(unsigned address)
	{
		float result=0;
		DWORD byte_read=0;
		if (!ReadProcessMemory(process,(void*)address,&result,4,&byte_read))
		{
			return 0;
		}
		return result;
	}
	void Process::MoveMouse(int x, int y)
	{
		INPUT input={0};
		input.mi.dx=x*(65536/GetSystemMetrics(SM_CXSCREEN));;
		input.mi.dy=y*(65536/GetSystemMetrics(SM_CYSCREEN));;
		input.mi.mouseData=0;
		input.mi.dwFlags= MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;
		input.type=INPUT_MOUSE;
		SendInput(1,&input,sizeof(input));
	}
	float Process::ReadRelFloat(unsigned offset)
	{
		return ReadFloat(base_address+offset);
	}
#endif

}