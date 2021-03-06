#pragma once
#include "Frame.h"
#include <iostream>
#include <vector>
using namespace std;
namespace Wow
{
	class FrameManager
	{
		static vector <Frame*> * frames; 
		static float screen_width;
		static float screen_heigth;
	public:
		FrameManager(void);
		~FrameManager(void);
		static vector <Frame*> * GetFrames();
		static void EnumAllFrames();
		static void FindParents();
		static void DumpAllFramesNames();
		static void ClearFrames();
		static float GetScreenWidth(bool refresh=false);
		static float GetScreenHeigth(bool refresh=false);
		static Frame * FindFrameByName(const char * name);
		static Frame * FindFrameByAddress(unsigned address);
	};
}

