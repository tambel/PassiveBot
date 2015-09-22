#pragma once
namespace Wow
{
	class GameInteractor
	{
	public:
		GameInteractor(void);
		~GameInteractor(void);
		static bool Login(char * login, char * password);
		static bool StartClient();
		static bool IsLoaded();
		static bool WaitUntilClientLoad();
		static bool WaitForAuthentification();
		static void CheckForPromoFrames();
		static void Test();
	};
}

