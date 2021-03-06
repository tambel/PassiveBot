#include "MemLib.h"
#include <TlHelp32.h>
#include <iostream>
using namespace std;
using namespace std;
namespace ProcessLib
{

#ifdef _WIN32
	HANDLE  Process::process=NULL;
	DWORD Process::thread_id=NULL;
	HWND Process::window=NULL;
	unsigned Process::base_address=0;
	unsigned Process::mouse_x=0;
	unsigned Process::mouse_y=0;
	bool Process::Init()
	{
		cout<<"Process initialization"<<endl;
		CloseHandle(process);
		DWORD id;
		HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
		MODULEENTRY32 me32;
		window=FindWindow("GXWindowClass","World of Warcraft");
		if (window==NULL)
		{
			cout<<"   Window not found"<<endl;
			return false;
		}

		GetWindowThreadProcessId(window,&id);

		process=OpenProcess(PROCESS_ALL_ACCESS ,NULL,id);
		if (process==NULL)
		{
			cout<<"   OpenProcess failed"<<endl;
			return false;
		}

		hModuleSnap = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE, id);
		if( hModuleSnap == INVALID_HANDLE_VALUE )
		{
			return false;
		}
		me32.dwSize = sizeof( MODULEENTRY32 );
		if( !Module32First( hModuleSnap, &me32 ) )
		{
			return false;
		}
		base_address=(unsigned)me32.modBaseAddr;
		hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
		if (hModuleSnap != INVALID_HANDLE_VALUE) {
			THREADENTRY32 te;
			FILETIME time={0};
			bool first=true;
			te.dwSize = sizeof(te);
			if (!Thread32First(hModuleSnap, &te))
			{
				return 0;
			} 

			do
			{
				if (te.th32OwnerProcessID==id)
				{
					HANDLE thread=OpenThread(  THREAD_ALL_ACCESS ,FALSE,te.th32ThreadID);
					int error=GetLastError();
					FILETIME ct={0};
					FILETIME et={0};
					FILETIME kt={0};
					FILETIME ut={0};
					GetThreadTimes(thread,&ct,&et,&kt,&ut);
					if (first)
					{
						time=ct;
						thread_id=te.th32ThreadID;
						first=false;
						continue;
					}
					if (CompareFileTime(&time,&ct)>0)
					{
						time=ct;
						thread_id=te.th32ThreadID;

					}
				}
			}
			while (Thread32Next(hModuleSnap, &te));
		}
		//thread=me32.th32ModuleID;
		CloseHandle( hModuleSnap );
		return 1;
	}
	bool Process::FindExistingProcess()
	{
		PROCESSENTRY32 entry;
		entry.dwSize = sizeof(PROCESSENTRY32);

		HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

		if (Process32First(snapshot, &entry) == TRUE)
		{
			while (Process32Next(snapshot, &entry) == TRUE)
			{
				if (strcmp(entry.szExeFile, "Wow.exe") == 0)
				{  
					CloseHandle(snapshot);
					return true;
				}
			}
		}
		return false;
	}
	bool Process::LaunchProcess()
	{
		PROCESS_INFORMATION pi = {0};
		STARTUPINFO si = {0};
		HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
		MODULEENTRY32 me32={0};
		me32.dwSize = sizeof( MODULEENTRY32 );
		if (!CreateProcess(WOW_EXECUTABLE_PATH,NULL,NULL,NULL,FALSE,0,NULL,NULL,&si,&pi))
		{
			TerminateProcess(pi.hProcess,0);
			return false;
		}
		return true;
	}
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
			delete [] tmpWCResult;
			delete [] tmpResult;
			return NULL;
		}
		MultiByteToWideChar(65001,0,(LPCCH)tmpWCResult,-1,tmpResult,real_length);
		resLength=wcslen(tmpResult)+1;
		result=new wchar_t[resLength];
		memcpy(result,tmpResult,resLength*2);
		delete [] tmpWCResult;
		delete [] tmpResult;
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
	bool Process::ReadRelRaw(unsigned offest,void * buffer, unsigned long length)
	{
		return ReadRaw(Process::GetProcessBase()+offest,buffer,length);
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
			delete [] tmp_result;
			return 0;
		}
		res_length=strlen(tmp_result);
		result=new char[res_length+1];
		strcpy(result,tmp_result);
		delete [] tmp_result;

		return result;

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
	void Process::MoveMouse(unsigned x, unsigned y,unsigned long time)
	{
		INPUT input={0};
		input.mi.dx=x;
		input.mi.dy=y;
		input.mi.mouseData=0;
		input.mi.dwFlags= MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;
		input.type=INPUT_MOUSE;
		Sleep(time);
		SendInput(1,&input,sizeof(input));
		mouse_x=x;
		mouse_y=y;
	}
	float Process::ReadRelFloat(unsigned offset)
	{
		return ReadFloat(base_address+offset);
	}
	Language Process::GetCurrentLanguage()
	{
		HKL l=GetKeyboardLayout(thread_id);
		Language lang;
		WORD low=(WORD)l>>0;
		char low2=low>>0;
		switch (low2>>0)
		{
		case LANG_RUSSIAN:
			lang=Language::RUSSIAN;
			break;
		case LANG_ENGLISH:
			lang=Language::ENGLISH;
			break;
		}
		return lang;
	}
	void Process::MouseUp(MouseButton button)
	{
		INPUT input={0};
		input.mi.dx=mouse_x;
		input.mi.dy=mouse_y;
		input.mi.mouseData=0;
		switch (button)
		{
		case MouseButton::LEFT:
			input.mi.dwFlags= MOUSEEVENTF_LEFTUP;
			break;
		case MouseButton::RIGHT:
			input.mi.dwFlags= MOUSEEVENTF_RIGHTUP;
			break;
		case MouseButton::WHEEL:
			break;
		default:
			break;
		}
		input.type=INPUT_MOUSE;
		SendInput(1,&input,sizeof(input));
	}
	void Process::MouseDown(MouseButton button)
	{
		INPUT input={0};
		input.mi.dx=mouse_x;
		input.mi.dy=mouse_y;
		input.mi.mouseData=0;
		switch (button)
		{
		case MouseButton::LEFT:
			input.mi.dwFlags= MOUSEEVENTF_LEFTDOWN;
			break;
		case MouseButton::RIGHT:
			input.mi.dwFlags= MOUSEEVENTF_RIGHTDOWN;
			break;
		case MouseButton::WHEEL:
			break;
		default:
			break;
		}
		input.type=INPUT_MOUSE;
		SendInput(1,&input,sizeof(input));
	}
	void Process::MouseClick( MouseButton button, unsigned long delay)
	{
		MouseDown(button);
		Sleep(delay);
		MouseUp(button);
		/*
		INPUT input={0};
		input.mi.dx=mouse_x;
		input.mi.dy=mouse_y;
		input.mi.mouseData=0;
		input.mi.dwFlags= MOUSEEVENTF_LEFTDOWN;
		input.type=INPUT_MOUSE;
		SendInput(1,&input,sizeof(input));
		Sleep(delay);
		input.mi.dwFlags= MOUSEEVENTF_LEFTUP;
		SendInput(1,&input,sizeof(input));
		*/
	}
	void Process::DoubleClick(MouseButton button, unsigned long interval)
	{
		MouseClick(button);
		Sleep(interval);
		MouseClick(button);
	}
	unsigned short Process::ReinterpretKeybardKey(unsigned short button)
	{
		WORD key;
		if (button>=0x41 && button<=0x5A)
		{
			key=button;
		}
		else if (button>=0x30 && button<=0x39)
		{
			key=button;
		}
		switch (button)
		{
		case KeyboardButton::ARROW_RIGHT:
			key=VK_RIGHT;
			break;
		case KeyboardButton::ARROW_LEFT:
			key=VK_LEFT;
			break;
		case KeyboardButton::BACKSPACE:
			key=VK_BACK;
			break;
		case KeyboardButton::AT:
			key=VK_ATTN;
			break;
		case KeyboardButton::PERIOD:
			key=VK_OEM_PERIOD;
			break;
		case KeyboardButton::ALT:
			key=VK_MENU;
			break;
		case KeyboardButton::CONTROL:
			key=VK_CONTROL;
			break;
		case KeyboardButton::LSHIFT:
			key=VK_LSHIFT;
			break;
		case KeyboardButton::ENTER:
			key=VK_RETURN;
			break;
		}
		return key;
	}
	void Process::PushKeyboardButton(unsigned short button)
	{
		INPUT input={0};
		input.type=INPUT_KEYBOARD;
		input.ki.wVk=ReinterpretKeybardKey(button);
		SendInput(1,&input,sizeof(input));
	}
	void Process::ReleaseKeyboardButton(unsigned short button)
	{
		INPUT input={0};
		input.type=INPUT_KEYBOARD;
		input.ki.wVk=ReinterpretKeybardKey(button);
		input.ki.dwFlags=KEYEVENTF_KEYUP;
		SendInput(1,&input,sizeof(input));
	}
	void Process::PressKeyboardButton(unsigned short button,unsigned long delay,unsigned short add_button)
	{
		INPUT input={0};
		input.type=INPUT_KEYBOARD;
		input.ki.wVk=ReinterpretKeybardKey(button);
		if (add_button)
		{
			PushKeyboardButton(add_button);
			SendInput(1,&input,sizeof(input));
			input.ki.dwFlags=KEYEVENTF_KEYUP;
			SendInput(1,&input,sizeof(input));
			ReleaseKeyboardButton(add_button);
		}
		else
		{
			SendInput(1,&input,sizeof(input));
			input.ki.dwFlags=KEYEVENTF_KEYUP;
			SendInput(1,&input,sizeof(input));
		}
		delay?Sleep(delay):delay;
	}
	char Process::ReadRelByte(unsigned offset)	
	{
		return ReadByte(base_address+offset);
	}
	bool Process::ReadBool(unsigned address)
	{
		if (Process::ReadByte(address))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Process::ReadRelBool(unsigned offset)
	{
		return ReadBool(base_address+offset);
	}
	HWND Process::GetWindow()
	{
		return window;
	}
	Rect Process::GetClientSize()
	{
		RECT rc={0};
		Rect result={0};
		GetClientRect(window,&rc);
		int e =GetLastError();
		result.heigth=rc.bottom-rc.top;
		result.width=rc.right-rc.left;
		return result;
	}
#endif

}