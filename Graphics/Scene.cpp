#include "Scene.h"
Scene::Scene(void)
{
}
Scene::~Scene(void)
{
	/*
	Ogre::SceneManager::MovableObjectIterator iterator= scene_node->getCreator()->getMovableObjectIterator("Entity");
	while(iterator.hasMoreElements())
	{
		Ogre::MovableObject * mo=iterator.getNext();
		if (mo->isInScene())
		{
			if (mo->getParentNode()==scene_node)
			{
				scene_node->getCreator()->destroyMovableObject(mo);
			}
		}
		
	}
	
	scene_node->detachAllObjects();
	*/
}