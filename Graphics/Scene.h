#pragma once
#include <OgreSceneManager.h>
class Scene
{
public:
	Scene(void);
	~Scene(void);
	Ogre::SceneNode * scene_node;
	Ogre::SceneNode * parent_scene;
};