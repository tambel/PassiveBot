/*
#include "Tile.h"
#include <string>
#include <algorithm>
using namespace std;
Tile::Tile(int x,int y)
{
	string path=PATH+ string(TERRAIN_PATH);
	path+="Azeroth\\Azeroth_"+to_string(x)+"_"+to_string(y);
	is_new=true;
	map_objects=vector<MapObject*>();
	doodads=vector<Doodad*>();
	indexX=x;
	indexY=y;
	position.x= indexY * 533.33333-17066.6656;
	position.y= indexX * 533.33333-17066.6656;
	Adt * adt=new Adt(path);
	for (unsigned i=0;i<16;i++)
	{
		for (unsigned j=0;j<16;j++)
		{
			for (auto mcnk:adt->mcnk_list)
			{
				if (mcnk->coords.X==i && mcnk->coords.Y==j)
				{
					blocks[i][j]=new Block(mcnk,adt->IsExist());
				}
			}
		}

	}
	if (adt->IsExist())
	{
		MapObject * map_object;
		for (auto info:adt->wmo_infos)
		{
			map_object=new MapObject(PATH+info.name,info);
			map_objects.push_back(map_object);
		}
		Doodad * doodad;
		for (auto info:adt->m2_infos)
		{
			doodad=new Doodad(PATH+info.name,info);
			//if (doodad->m2->vert_count>0)
				doodads.push_back(doodad);
			//else
				//delete doodad;
		}

		exists=true;

	}
	else
	{
		exists=false;
	}
	delete adt;
}
Tile::Tile(void)
{
}
Tile::~Tile(void)
{
	for (auto map_object:map_objects)
	{
		delete map_object;
	}
	for (auto doodad:doodads)
	{
		delete doodad;
	}
	doodads.clear();
	map_objects.clear();
	for (unsigned i=0;i<16;i++)
	{
		for (unsigned j=0;j<16;j++)
		{
			delete blocks[i][j];
		}
	}
}
void Tile::SetPosition(Vector3 position)
{
	this->position=position;
}
void Tile::Draw()
{
	for (unsigned i=0;i<16;i++)
	{
		for (unsigned j=0;j<16;j++)
		{
			blocks[i][j];
		}
	}
}
*/