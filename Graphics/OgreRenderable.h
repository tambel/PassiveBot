#pragma once
#include <OgreSceneManager.h>
#include <WowDataLib\Renderable.h>
#include <string>
using namespace std;
using namespace Utils::WowTypes;
class OgreRenderable :public Renderable
{
protected:
	static unsigned long current_uid;
public:
	//Ogre::SceneNode * scene;
	static unsigned long GetUIDAndIncrement();
	static void ClearCounter(); 
	Ogre::SceneNode * CreateScene(Ogre::SceneNode * parent_scene);
	void SetPosition(Vector3 position);
};
