#pragma once
namespace Wow
{
	enum GameState
	{
		TURNED_OFF,
		LAUNCHED,
		LOGIN_SCREEN,
		LOGGED_IN,
		CHARACTER_LIST,
		IN_WORLD
	};
	class GameInteractor
	{
		static GameState state;
		static bool CanLogin();
	public:
		GameInteractor(void);
		~GameInteractor(void);
		static bool Login(char * login, char * password);
		static GameState CurrentGameState();
		static bool TryToStartGame();
		static bool StartGame(unsigned attempts_count=10);
		static bool CheckForRunningGame();
		static bool ContinueGame();
	};
}

