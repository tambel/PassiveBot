#pragma once
#include "Scene.h"
#include "WowDataLib\Mesh.h"
class MapMeshScene:public Scene
{
public :
	Mesh * mesh;
	MapMeshScene(void);
	~MapMeshScene(void);
	void SetMesh(Mesh * mesh, Ogre::SceneNode * ps);
};