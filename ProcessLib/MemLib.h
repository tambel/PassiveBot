#pragma once
#include <string>
#ifdef _WIN32
#include <Windows.h>
#endif

namespace ProcessLib
{
	using namespace std;
	static class  Process
	{
	protected:
#ifdef _WIN32
		static HANDLE process;
		static HWND window;
#endif
		static unsigned base_address;
	public:
		
		static bool Init();
		static unsigned GetProcessBase();

		static wchar_t * ReadString_UTF8(unsigned address, unsigned long  length);
		static unsigned ReadUInt(unsigned address);
		static char ReadByte(unsigned address);
		static bool ReadRaw(unsigned address, void * buffer, unsigned long length);
		static unsigned ReadRelUInt(unsigned offset);
		static char * ReadASCII(unsigned address,unsigned long length);
		static float ReadFloat(unsigned address);
		static float ReadRelFloat(unsigned offset);
		static void MoveMouse(int x,int y);
	};
}
