#include "GameInteractor.h"
#include "FrameManager.h"
#include "MemLib.h"
using namespace ProcessLib;
namespace Wow
{
	GameInteractor::GameInteractor(void)
	{
	}


	GameInteractor::~GameInteractor(void)
	{
	}
	bool GameInteractor::Login(char * login, char * password)
	{
		FrameManager::EnumAllFrames();
		Frame * email_frame= FrameManager::FindFrameByName("AccountLoginAccountEdit");
		email_frame->MoveMoseToFrame();
		Process::MouseClick();
		Process::MultipleKeyboardButtonPush(KeyboardButton::ARROW_RIGHT,20,50);
		Process::MultipleKeyboardButtonPush(KeyboardButton::BACKSPACE,40,40);
		Process::SetLanguage(Language::ENGLISH);
		Process::TypeByKeyboard(login);
		Frame * password_frame= FrameManager::FindFrameByName("AccountLoginPasswordEdit");
		password_frame->MoveMoseToFrame();
		Process::MouseClick();
		Process::TypeByKeyboard(password);
		Process::PressKeyboardButton(KeyboardButton::ENTER);
		return true;
	}
	bool GameInteractor::Start()
	{
		unsigned attempts_count=10;
		if (!Process::FindExistingProcess())
		{
			Process::LaunchProcess();
			Sleep(20000);
		}
		unsigned attempts=0;
		while(!Process::Init() && attempts<attempts_count)
		{
			cout<<"Retry"<<endl;
			Sleep(5000);
			attempts++;
		}
		if (attempts==attempts_count)
		{
			return false;
		}
		return true;

	}
}