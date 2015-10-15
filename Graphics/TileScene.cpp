#include "TileScene.h"
#include "Utils.h"
TileScene::TileScene(void)
{
	for (int i=0;i<16;i++)
	{
		for (int j =0;j<16;j++)
		{
			blocks[i][j]=new BlockScene();
		}
	}
}
TileScene::~TileScene(void)
{
	for (int i=0;i<16;i++)
	{
		for (int j =0;j<16;j++)
		{
			delete blocks[i][j];
		}
	}
	for (auto mes:mes_list)
	{
		delete mes;
	}
	mes_list.clear();
}
void TileScene::SetTile(Tile * tile,Ogre::SceneNode * ps)
{

	parent_scene=ps;
	scene_node=parent_scene->createChildSceneNode();

	if (tile->exists)
	{
		for (int i=0;i<16;i++)
		{
			for (int j=0;j<16;j++)
			{
				blocks[i][j]->SetBlock(tile->blocks[i][j],scene_node);
				blocks[i][j]->scene_node->setPosition(Vector3ToOgreVector(tile->blocks[i][j]->position.coords));

			}
		}
		for (auto map_object:tile->map_objects)
		{
			if (map_object->visible)
			{
				MapEntityScene * mes=new MapEntityScene();
				mes->SetEntity(map_object,scene_node);

				mes_list.push_back(mes);
			}
		}

		for (auto doodad:tile->doodads)
		{
			if (doodad->visible)
			{
				MapEntityScene * mes=new MapEntityScene();
				mes->SetEntity(doodad,scene_node);
				mes_list.push_back(mes);
			}
		}
		scene_node->setPosition(Vector3ToOgreVector(tile->position));
	}
	//scene_node->rotate(Ogre::Vector3(0,0,1),Ogre::Radian(-1.57));
}