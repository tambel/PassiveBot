#pragma once
#include "Map.h"

WowMap::WowMap(Vector3 position)
{
	int x=floor((32 - (position.x / TILE_LENGTH)));
	int y=floor((32 - (position.y / TILE_LENGTH)));
	tiles[0][0]=new Tile(33,49);
	tiles[0][1]=new Tile(33,50);
	tiles[0][2]=new Tile(33,51);
	tiles[1][0]=new Tile(34,49);
	tiles[1][1]=new Tile(34,50);
	tiles[1][2]=new Tile(34,51);
	tiles[2][0]=new Tile(35,49);
	tiles[2][1]=new Tile(35,50);
	tiles[2][2]=new Tile(35,51);
}
WowMap::~WowMap(void)
{
}
void WowMap::SetPosition(Vector3 position)
{
	this->position=position;
}
void  WowMap::GoToPlace(Vector3 position)
{
	

} 



