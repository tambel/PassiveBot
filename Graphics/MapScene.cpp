#include "MapScene.h"
#include "Utils.h"
#include "OgreRenderable.h"

MapScene::MapScene(void)
{
}


MapScene::~MapScene(void)
{
}

void MapScene::SetMap(WowMap * map,Ogre::SceneNode * ps)
{
	parent_scene=ps;
	scene_node=parent_scene->createChildSceneNode();
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			tiles[i][j].SetTile(map->tiles[i][j],scene_node);
			//tiles[i][j].scene_node->setPosition(Vector3ToOgreVector(map->tiles[i][j]->position));
		}
	}
	scene_node->setPosition(Vector3ToOgreVector(map->position.coords));
	//scene_node->rotate(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3(0,0,1)),Ogre::Node::TS_WORLD);

}
TileScene::TileScene(void)
{
}
TileScene::~TileScene(void)
{
}
void TileScene::SetTile(Tile * tile,Ogre::SceneNode * ps)
{
	parent_scene=ps;
	scene_node=parent_scene->createChildSceneNode();
	for (int i=0;i<16;i++)
	{
		for (int j=0;j<16;j++)
		{
			blocks[i][j].SetBlock(tile->blocks[i][j],scene_node);
			blocks[i][j].scene_node->setPosition(Vector3ToOgreVector(tile->blocks[i][j]->position.coords));
			
		}
	}
	for (auto map_object:tile->map_objects)
	{
		if (map_object->visible)
		{
			MapEntityScene mes=MapEntityScene();
			mes.SetEntity(map_object,scene_node);

			mes_list.push_back(mes);
		}
	}

	for (auto doodad:tile->doodads)
	{
		MapEntityScene mes=MapEntityScene();
		mes.SetEntity(doodad,scene_node);
		mes_list.push_back(mes);
	}
	scene_node->setPosition(Vector3ToOgreVector(tile->position));
	//scene_node->rotate(Ogre::Vector3(0,0,1),Ogre::Radian(-1.57));
}
void BlockScene::SetBlock(Block * block,Ogre::SceneNode * ps)
{
	parent_scene=ps;
	scene_node=((OgreRenderable*)block)->CreateScene(parent_scene);
	scene_node->setPosition(Vector3ToOgreVector(block->position.coords));
}
void MapEntityScene::SetEntity(MapEntity* entity,Ogre::SceneNode * ps)
{
	if (entity->visible)
	{
		parent_scene=ps;
		scene_node=parent_scene->createChildSceneNode();
		for (auto mesh:entity->meshes)
		{
			mesh_scenes.push_back(((OgreRenderable*)mesh)->CreateScene(scene_node));
		}
		scene_node->setPosition(Vector3ToOgreVector(entity->position.coords));
		scene_node->rotate(Ogre::Vector3(0,0,1),Ogre::Degree(entity->position.rotation.y));
		scene_node->rotate(Ogre::Vector3(0,1,0),Ogre::Degree(entity->position.rotation.z));
		scene_node->rotate(Ogre::Vector3(1,0,0),Ogre::Degree(entity->position.rotation.x));
	}
}
