#pragma once
#include <OgreSceneManager.h>
#include "WowDataLib\WowMap.h"
#include <vector>
using namespace std;
class Scene
{
public:
	Ogre::SceneNode * scene_node;
	Ogre::SceneNode * parent_scene;
};
class MapMeshScene:public Scene
{
public :
	Mesh * mesh;
};
class MapEntityScene:public Scene
{
public:
	MapEntity * entity;
	vector<Ogre::SceneNode*> mesh_scenes;
	//vector<MapMeshScene> mesh_scenes;
	void SetEntity(MapEntity* entity,Ogre::SceneNode * ps);
};
class BlockScene:public Scene
{
public:
	void SetBlock(Block * block,Ogre::SceneNode * ps);
};
class TileScene:public Scene
{
	Tile * tile;
	BlockScene blocks[16][16];
	vector<MapEntityScene> mes_list;

public: 
	TileScene(void);
	~TileScene(void);
	void SetTile(Tile * tile,Ogre::SceneNode * ps);
};
class MapScene:public Scene
{
	WowMap * map;
	TileScene tiles[3][3];
public:
	MapScene(void);
	~MapScene(void);
	void SetMap(WowMap * map,Ogre::SceneNode * ps);
};

