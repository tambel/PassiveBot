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
		Frame * email_frame= FrameManager::FindFrameByName("AccountLoginAccountEdit");
		email_frame->MoveMoseToFrame();
		Process::MouseClick();
		Process::MultipleKeyboardButtonPush(KeyboardButton::ARROW_RIGHT,20,50);
		Process::MultipleKeyboardButtonPush(KeyboardButton::BACKSPACE,40,40);
		Process::SetLanguage(Language::ENGLISH);
		Process::TypeByKeyboard("arttambel@gmail.com");
		Frame * password_frame= FrameManager::FindFrameByName("AccountLoginPasswordEdit");
		password_frame->MoveMoseToFrame();
		Process::MouseClick();
		Process::TypeByKeyboard("archi911");
		Process::PressKeyboardButton(KeyboardButton::ENTER);
		return true;
	}
}