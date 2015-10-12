#pragma once
#include "WowDataLib\Tile.h"
#include "OgreSceneManager.h"
class OgreTile: public Tile
{
	Ogre::SceneNode * scene;
public:
	OgreTile(void);
	~OgreTile(void);
	void InitScene(Ogre::SceneNode * parent);
};

