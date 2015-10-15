#pragma once
#include <OgreSceneManager.h>
#include "Scene.h"
#include "WowDataLib\Block.h"
class BlockScene:public Scene
{
public:
	void SetBlock(Block * block,Ogre::SceneNode * ps);
};
