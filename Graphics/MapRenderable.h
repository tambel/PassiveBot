#pragma once
#include <Map.h>
#include "Renderable.h"
#include <OgreSceneManager.h>
class BlockRenderable:public Block
{
public:
	void CreateEntity(Ogre::SceneNode * parent_scene);

};
class TileRenderable:public Tile
{
public:
	void CreateScene(Ogre::SceneNode * parent_scene);
};
class MapRenderable:public WowMap
{
public:
	void CreateScene(Ogre::SceneNode * parent_scene);
};

