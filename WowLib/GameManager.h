#pragma once
#include "Utils.h"
#include "Camera.h"
namespace Wow
{
	class GameManager
	{
		
	public:

		GameManager(void);
		~GameManager(void);
		static Camera * GetCamera();
		static bool WorldToScreen(Position pos);
		
	};
}

