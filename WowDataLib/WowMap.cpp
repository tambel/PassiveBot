#pragma once
#include "WowMap.h"

WowMap::WowMap(Vector3 position)
{
	vector<MapObject*> mo_cl=vector<MapObject*>();
	
	bool exist=false;
	int x=floor((32 - (position.x / (TILE_LENGTH))));
	int y=floor((32 - (position.y / (TILE_LENGTH))));
	this->position.x=17066.66656-((float)x * 533.33333);
	this->position.y=17066.66656-((float)y * 533.33333);
	this->position.z=0;
	//this->position=position;
	//this->position=position;
	new_object=false;
	//x=29;
	//y=19;
	tiles[0][0]=new Tile(y-1,x-1);
	tiles[0][1]=new Tile(y-1,x);
	tiles[0][2]=new Tile(y-1,x+1);
	tiles[1][0]=new Tile(y,x-1);
	tiles[1][1]=new Tile(y,x);
	tiles[1][2]=new Tile(y,x+1);
	tiles[2][0]=new Tile(y+1,x-1);
	tiles[2][1]=new Tile(y+1,x);
	tiles[2][2]=new Tile(y+1,x+1);
	objects=vector<MapEntity*>();
	new_objects=vector<MapEntity*>();
}
WowMap::~WowMap(void)
{
	tiles[1][1];
	/*
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			delete tiles[i][j];
		}
	}
	*/
}
void WowMap::SetPosition(Vector3 position)
{
	this->position=position;
}
void  WowMap::GoToPlace(Vector3 position)
{
	

} 
void WowMap::Draw()
{
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;i++)
		{
			tiles[i][j];
		}
	}
}



