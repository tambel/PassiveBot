#include "MapEntityScene.h"
#include "Utils.h"
#include "OgreRenderable.h"

MapEntityScene::MapEntityScene(void)
{
	mesh_scenes=vector<MapMeshScene*>();
}
MapEntityScene::~MapEntityScene(void)
{
	for (auto mesh_scene:mesh_scenes)
	{
		delete mesh_scene;
	}
	mesh_scenes.clear();
}
void MapEntityScene::SetEntity(MapEntity* entity,Ogre::SceneNode * ps)
{
	if (entity->visible)
	{
		id=entity->GetID();
		parent_scene=ps;
		scene_node=parent_scene->createChildSceneNode();
		for (auto mesh:entity->meshes)
		{
			MapMeshScene * ms=new MapMeshScene();
			ms->SetMesh(mesh,scene_node);
			mesh_scenes.push_back(ms);
			//mesh_scenes.push_back(((OgreRenderable*)mesh)->CreateScene(scene_node));
		}
		scene_node->setPosition(Vector3ToOgreVector(entity->position.coords));
		scene_node->rotate(Ogre::Vector3(0,0,1),Ogre::Degree(entity->position.rotation.y));
		scene_node->rotate(Ogre::Vector3(0,1,0),Ogre::Degree(entity->position.rotation.z));
		scene_node->rotate(Ogre::Vector3(1,0,0),Ogre::Degree(entity->position.rotation.x));
	}
}
