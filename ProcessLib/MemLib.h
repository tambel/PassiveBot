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
		static WCHAR* ReadString_UTF8(unsigned address, unsigned long  length);
		static unsigned ReadUInt(unsigned address);
		static bool Init();
		static unsigned GetProcessBase()
		{
			return base_address;
		}
	};
}