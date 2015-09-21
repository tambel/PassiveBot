#pragma once
namespace Wow
{
	class GameInteractor
	{
	public:
		GameInteractor(void);
		~GameInteractor(void);
		static bool Login(char * login, char * password);
		static bool Start();
	};
}

