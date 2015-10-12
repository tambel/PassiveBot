#pragma once
#include "WowDataLib\WowMap.h"
#include "OgreSceneManager.h"
class OgreMap: public WowMap
{
	Ogre::SceneNode * scene;

public:
	OgreMap(Vector3 position);
	~OgreMap(void);
	void InitScene(Ogre::SceneNode * parent);
};

