/*#include "MemLib.h"
namespace ProcessLib
{
#ifdef _WIN32
	wstring Process::ReadString_UTF8(void *address, DWORD length)
	{
		length?length:length=1024;
		DWORD real_length=length*2;
		DWORD byte_read=0;
		wstring result;
		WCHAR * buffer=new WCHAR[length];
		if (!ReadProcessMemory(process,address,buffer,real_length,&byte_read))
		{
			return 0;
		}
		result=buffer;
		return result;
	}
#endif
}*/