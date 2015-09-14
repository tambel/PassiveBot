#include "MemLib.h"
#include <TlHelp32.h>
namespace ProcessLib
{
	using namespace std;
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
			int k=GetLastError();
			return 0;
		}

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
#endif
}