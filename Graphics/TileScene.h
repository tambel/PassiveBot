#include <OgreSceneManager.h>
#include "WowDataLib\Tile.h"
#include "BlockScene.h"
#include "MapEntityScene.h"
class TileScene:public Scene
{
	Tile * tile;
	BlockScene * blocks[16][16];
	vector<MapEntityScene *> mes_list;

public: 
	TileScene(void);
	~TileScene(void);
	void SetTile(Tile * tile,Ogre::SceneNode * ps);
};