#include "MemLib.h"

namespace ProcessLib
{
	 static class WindowsProcess: protected Process
	{

	public:
		 static wstring ReadString_UTF8(void *address, DWORD length);
	};
}