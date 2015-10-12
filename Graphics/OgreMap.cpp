#include "OgreMap.h"


OgreMap::OgreMap(Vector3 position):WowMap(position)
{
}


OgreMap::~OgreMap(void)
{
}
void OgreMap::InitScene(Ogre::SceneNode * parent)
{
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			tiles[i][j];
		}
	}
}