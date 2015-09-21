#include "GameInteractor.h"
#include "FrameManager.h"
#include "MemLib.h"
#include <TlHelp32.h>
using namespace ProcessLib;
namespace Wow
{

	GameState GameInteractor::state=GameState::TURNED_OFF;
	GameInteractor::GameInteractor(void)
	{
	}

	bool GameInteractor::CanLogin()
	{
		Frame * email_frame= FrameManager::FindFrameByName("AccountLoginAccountEdit");
		if (email_frame)
		{
			return email_frame->IsVisible();
		}
		return false;
	}
	GameInteractor::~GameInteractor(void)
	{
	}
	bool GameInteractor::Login(char * login, char * password)
	{
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
	GameState GameInteractor::CurrentGameState()
	{
		return state;
	}
	bool GameInteractor::TryToStartGame()
	{
		if (state==GameState::TURNED_OFF)
		{
			cout<<"Starting Wow.exe"<<endl;
			if (!Process::LaunchGame())
			{
				return 0;
			}
			Sleep(10000);
			state=GameState::LAUNCHED;
		}
		if (state==GameState::LAUNCHED)
		{
			cout<<"Initializing Process interaction"<<endl;
			if (!Process::Initialize())
			{
				return 0;
			}
			cout<<"Initializing Frames"<<endl;
			if (!FrameManager::EnumAllFrames())
			{
				return 0;
			}
			if (!CanLogin())
			{
				return 0;
			}
			state=GameState::LOGIN_SCREEN;
		}
		if (state==GameState::LOGIN_SCREEN)
		{
			cout<<"Logging in"<<endl;
			if (!Login("arttambel@gmail.com","archi911"))
			{
				return 0;
			}
			state=GameState::LOGGED_IN;
		}
		if (state=GameState::LOGGED_IN)
		{


		}

	}
	bool GameInteractor::StartGame(unsigned attempts_count)
	{
		if (CheckForRunningGame())
		{
			state=GameState::LAUNCHED;
		}

		unsigned attemps=0;
		Sleep(1000);
		while(!TryToStartGame() && attemps<attempts_count)
		{
			cout<<"Game start failed, retrying..."<<endl<<"Failed on: "<<state<<endl;
			Sleep(10000);
			attemps++;
		}
		if (attemps==attempts_count)
		{
			return false;
		}
		return true;




	}
	bool GameInteractor::CheckForRunningGame()
	{
		return Process::CheckForProcessExistanse();
	}
	bool GameInteractor::ContinueGame()
	{
		if(!Process::CheckForProcessExistanse())
	}


}