#include "GameInteractor.h"
#include "FrameManager.h"
#include "MemLib.h"
#include "offsets.h"
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
		cout<<"Logging in"<<endl;
		if (!WaitUntilClientLoad())
		{
			return false;
		}
		
		FrameManager::EnumAllFrames();
		Frame * email_frame= FrameManager::FindFrameByName("AccountLoginAccountEdit");
		if (!email_frame)
		{
			cout<<"Email frame not found";
			return false;
		}

		if (!email_frame->WaitForFrameVisibility() || !email_frame->IsVisible())
		{
			cout<<"Email frame is not visible"<<endl;
			return false;
		}
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
	bool GameInteractor::StartClient()
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
			cout<<"   Retry"<<endl;
			Sleep(5000);
			attempts++;
		}
		if (attempts==attempts_count)
		{
			return false;
		}
		return true;

	}
	bool GameInteractor::IsLoaded()
	{
		return Process::ReadRelBool(WowOffsets::Client::Loaded); 
	}
	bool GameInteractor::WaitUntilClientLoad()
	{
		cout<<"Waiting for client load..."<<endl;
		unsigned attempts=0;
		while(!IsLoaded() && attempts<6000)
		{
			Sleep(10);
			attempts++;
		}
		if (IsLoaded())
		{
			cout<<"Done"<<endl;
			return true;
		}
		else
		{
			cout<<"Client not loaded"<<endl;
			return false;
		}

	}
	bool GameInteractor::WaitForAuthentification()
	{
		cout<<"Waiting for client authentification..."<<endl;
		unsigned attempts=0;
		while(Process::ReadRelBool(WowOffsets::Client::Unavalible) && attempts<6000)
		{
			Sleep(10);
			attempts++;
		}
		if (!Process::ReadRelBool(WowOffsets::Client::Unavalible))
		{
			cout<<"Done"<<endl;
			return true;
		}
		else
		{
			cout<<"Authentification failed"<<endl;
			return false;
		}
	}
	void GameInteractor::CheckForPromoFrames()
	{
		FrameManager::EnumAllFrames();
		Frame *starter=FrameManager::FindFrameByName("StarterEditionPopUpExitButton");
		unsigned attempts=0;
		while (!starter->IsVisible() && attempts<1000)
		{
			Sleep(10);
			attempts++;
		}
		if (starter->IsVisible())
		{
			starter->MoveMoseToFrame();
			Process::MouseClick();
		}
	}
	void GameInteractor::Test()
	{
		FrameManager::EnumAllFrames();
		vector<Frame*> * frames=FrameManager::GetFrames();
		Frame *frame1=FrameManager::FindFrameByName("CharSelectCharacterButton1");
		vector<wchar_t*> names=vector<wchar_t*>();
		vector<unsigned> u=vector<unsigned>();
		vector<unsigned> u2=vector<unsigned>();
		for (unsigned i=0;i<1000;i+=4)
		{
			u.push_back(Process::ReadUInt(frame1->GetBase()+i));
		}
		Sleep(7000);
		for (unsigned i=0;i<1000;i+=4)
		{
			u2.push_back(Process::ReadUInt(frame1->GetBase()+i));
		}
		Frame *frame2=FrameManager::FindFrameByName("CharSelectAccountUpgradePanelFeature3");
		Frame *frame3=FrameManager::FindFrameByName("StarterEditionPopUpFeature2");
		Frame *frame4=FrameManager::FindFrameByName("StarterEditionPopUpFeature3");
		Frame *frame5=FrameManager::FindFrameByName("StarterEditionPopUpExitButton");
		Sleep(5000);
		frame1->MoveMoseToFrame();
		bool y=frame5->IsVisible();

	}
}