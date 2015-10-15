#include "BlockScene.h"
#include "OgreRenderable.h"
#include "Utils.h"
void BlockScene::SetBlock(Block * block,Ogre::SceneNode * ps)
{
	parent_scene=ps;
	scene_node=((OgreRenderable*)block)->CreateScene(parent_scene);
	scene_node->setPosition(Vector3ToOgreVector(block->position.coords));
}