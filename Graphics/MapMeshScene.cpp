#include "MapMeshScene.h"
#include "OgreRenderable.h"
MapMeshScene::MapMeshScene(void)
{

}
MapMeshScene::~MapMeshScene(void)
{
}
void MapMeshScene::SetMesh(Mesh * mesh, Ogre::SceneNode * ps)
{
	scene_node=((OgreRenderable*)mesh)->CreateScene(ps);
}