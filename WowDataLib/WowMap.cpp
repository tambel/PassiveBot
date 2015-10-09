#pragma once
#include "WowMap.h"

WowMap::WowMap(Vector3 position)
{
	vector<MapObject*> mo_cl=vector<MapObject*>();
	bool exist=false;
	int x=floor((32 - (position.y / TILE_LENGTH)));
	int y=floor((32 - (position.x / TILE_LENGTH)));
	//x=29;
	//y=19;
	tiles[0][0]=new Tile(x-1,y-1);
	tiles[0][1]=new Tile(x-1,y);
	tiles[0][2]=new Tile(x-1,y+1);
	tiles[1][0]=new Tile(x,y-1);
	tiles[1][1]=new Tile(x,y);
	tiles[1][2]=new Tile(x,y+1);
	tiles[2][0]=new Tile(x+1,y-1);
	tiles[2][1]=new Tile(x+1,y);
	tiles[2][2]=new Tile(x+1,y+1);
	
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			for (auto map_object:tiles[i][j]->map_objects)
			{
				for (auto mo:mo_cl)
				{
					if (mo->id==mo->id)
					{
						exist=true;
						break;
					}
				}
				if (exist)
				{
					delete map_object;
					
				}
			}
		}
	}
	objects=vector<Renderable*>();
}
WowMap::~WowMap(void)
{
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			delete tiles[i][j];
		}
	}
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



