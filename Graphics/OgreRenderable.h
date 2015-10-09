#pragma once
#include <OgreSceneManager.h>
#include <Renderable.h>
#include <string>
using namespace std;
using namespace Utils::WowTypes;
class OgreRenderable :public Renderable
{
protected:
	static unsigned long current_uid;
	Ogre::SceneNode * scene;
public:
	static unsigned long GetUIDAndIncrement();
	static void ClearCouner();
	Ogre::SceneNode * CreateScene(Ogre::SceneNode * parent_scene);
	void SetPosition(Vector3 position);
};
