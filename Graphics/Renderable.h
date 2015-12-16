#pragma once
#include "Link.h"
#include "OgreSceneManager.h"
#include "Utils.h"
class Renderable
{
	static unsigned long counter;
	unsigned long id;
	Link * link;
	Ogre::SceneNode * scene;
public:
	Renderable(Link * link);
	~Renderable(void);
	void CreateScene(Ogre::SceneNode * parent);
	unsigned long GetID() {return id;}
	Ogre::SceneNode * GetScene() {return scene;}

};

