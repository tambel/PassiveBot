#pragma once
#include "WowMap.h"
#include <algorithm>
WowMap::WowMap(Vector3 position)
{
	dynamic_objects=vector<DynamicObject*>();
	to_update=false;
	to_redraw=false;
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			tiles[i][j]=0;
		}
	}
	GoToPlace(position);
}
void WowMap::GoToPlace(Vector3 ppos)
{
	vector<MapObject*> check_list=vector<MapObject*>();

	bool exist=false;
	//int x=floor((32 - (ppos.x / (TILE_LENGTH))));
	//int y=floor((32 - (ppos.y / (TILE_LENGTH))));
	float block_pos_x=0;
	float block_pos_y=0;
	float tile_pos_x=0;
	float tile_pos_y=0;
	//coords_2D.X=x;
	//coords_2D.Y=y;
	coords_2D=WorldPositionToMapCoords(ppos);
	this->position.coords.x=17066.66656-((float)coords_2D.X * 533.33333)+TILE_LENGTH;
	this->position.coords.y=17066.66656-((float)coords_2D.Y * 533.33333)+TILE_LENGTH;
	this->position.coords.z=0;

	new_object=false;
	Tile * tmp_tiles[3][3];
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			tmp_tiles[i][j]=tiles[i][j];
			tiles[i][j]=0;
		}
	}
	for (int i=0,y=-1;i<3;i++,y++)
	{
		for (int j=0,x=-1;j<3;j++,x++)
		{
			for (int ti=0;ti<3;ti++)
			{
				for (int tj=0;tj<3;tj++)
				{
					if (tmp_tiles[ti][tj]!=0)
					{
						if (tmp_tiles[ti][tj]->indexX==coords_2D.Y+y && tmp_tiles[ti][tj]->indexY==coords_2D.X+x)
						{
							tiles[i][j]=tmp_tiles[ti][tj];
							tmp_tiles[ti][tj]=0;
							tiles[i][j]->is_new=false;
							break;
						}
					}

				}
				if (tiles[i][j]!=0)
				{
					break;
				}
			}
			if (tiles[i][j]==0)
			{
				tiles[i][j]=new Tile(coords_2D.Y+y,coords_2D.X+x);
			}
		}
	}
	for (int i=0,y=-1;i<3;i++,y++)
	{
		for (int j=0,x=-1;j<3;j++,x++)
		{
			delete tmp_tiles[i][j];
			tmp_tiles[i][j]=0;
		}
	}
	/*
	tiles[0][0]=new Tile(coords_2D.Y-1,coords_2D.X-1);
	tiles[0][1]=new Tile(coords_2D.Y-1,coords_2D.X);
	tiles[0][2]=new Tile(coords_2D.Y-1,coords_2D.X+1);
	tiles[1][0]=new Tile(coords_2D.Y,coords_2D.X-1);
	tiles[1][1]=new Tile(coords_2D.Y,coords_2D.X);
	tiles[1][2]=new Tile(coords_2D.Y,coords_2D.X+1);
	tiles[2][0]=new Tile(coords_2D.Y+1,coords_2D.X-1);
	tiles[2][1]=new Tile(coords_2D.Y+1,coords_2D.X);
	tiles[2][2]=new Tile(coords_2D.Y+1,coords_2D.X+1);
	*/

	for (int i=0;i<3;i++)
	{
		tile_pos_y=0;
		for (int j=0;j<3;j++)
		{
			if (this->tiles[i][j]->exists)
			{
				//Ogre::SceneNode * tile_scene = scene->createChildSceneNode("Tile_"+to_string(map->tiles[i][j]->indexX)+"_"+to_string(map->tiles[i][j]->indexY));
				//tile_scene->setPosition(tile_pos_y,tile_pos_x,0);
				tiles[i][j]->position.x=tile_pos_y;
				tiles[i][j]->position.y=tile_pos_x;
				tiles[i][j]->position.z=0;
				block_pos_x=0;
				for (int ti=0;ti<16;ti++)
				{
					block_pos_y=0;
					for (int tj=0;tj<16;tj++)
					{
						//((OgreRenderable*)(map->tiles[i][j]->blocks[ti][tj]))->CreateScene(tile_scene)->setPosition(block_pos_x,block_pos_y,0);
						tiles[i][j]->blocks[ti][tj]->position.coords.x=block_pos_x;
						tiles[i][j]->blocks[ti][tj]->position.coords.y=block_pos_y;
						tiles[i][j]->blocks[ti][tj]->position.coords.z=0;
						block_pos_y+=BLOCK_LENGTH;
					}
					block_pos_x+=BLOCK_LENGTH;
				}
				if (tiles[i][j]->is_new)
				{
					bool exist;

					for (auto map_object:tiles[i][j]->map_objects)
					{
						exist=false;
						for (auto mo:check_list)
						{
							if (mo->id==map_object->id)
							{
								exist=true;
								map_object->visible=false;
								break;
							}
						}
						if (exist)
							continue;
						check_list.push_back(map_object);
						float t_pos_x=tiles[i][j]->indexY * 533.33333-17066.6656;
						float t_pos_y=tiles[i][j]->indexX * 533.33333-17066.6656;
						map_object->position.coords=Vector3(map_object->position.coords.z-t_pos_x,map_object->position.coords.x-t_pos_y,map_object->position.coords.y);

						//Ogre::SceneNode * map_object_scene= tile_scene->createChildSceneNode(map_object->name+"_"+to_string(OgreRenderable::GetUIDAndIncrement()));
						for (auto mesh:map_object->meshes)
						{

							t_pos_x=tiles[i][j]->indexY * 533.33333-17066.6656;
							t_pos_y=tiles[i][j]->indexX * 533.33333-17066.6656;
							Vector3 pos;
							//pos.x=mesh->position.coords.z-t_pos_x;
							//pos.y=mesh->position.coords.x-t_pos_y;
							//pos.z=mesh->position.coords.y;
							mesh->position.coords=Vector3(mesh->position.coords.z-t_pos_x,mesh->position.coords.x-t_pos_y,mesh->position.coords.y);

							//Ogre::SceneNode * mesh_scene=((OgreRenderable*)mesh)->CreateScene(map_object_scene);
							//mesh_scene->setPosition(Vector3ToOgreVector(pos));
							//mesh_scene->rotate(Ogre::Vector3(0,0,1),Ogre::Degree(mesh->position.rotation.y));
							//mesh_scene->rotate(Ogre::Vector3(0,1,0),Ogre::Degree(mesh->position.rotation.z));
							//mesh_scene->rotate(Ogre::Vector3(1,0,0),Ogre::Degree(mesh->position.rotation.x));

						}
					}
					for (auto doodad:tiles[i][j]->doodads)
					{
						if (doodad->meshes[0]->vertice_count==0)
						{
							doodad->visible=false;
						}

						float t_pos_x= tiles[i][j]->indexY * 533.33333-17066.6656;
						float t_pos_y=  tiles[i][j]->indexX * 533.33333-17066.6656;
						doodad->position.coords=Vector3(doodad->position.coords.z-t_pos_x,doodad->position.coords.x-t_pos_y,doodad->position.coords.y);
						//Ogre::SceneNode * map_object_scene= tile_scene->createChildSceneNode(doodad->name+"_"+to_string(OgreRenderable::GetUIDAndIncrement()));
						for (auto mesh:doodad->meshes)
						{
							if (mesh->vertice_count>0)
							{
								t_pos_x= tiles[i][j]->indexY * 533.33333-17066.6656;
								t_pos_y=  tiles[i][j]->indexX * 533.33333-17066.6656;
								Vector3 pos;
								pos.x=mesh->position.coords.z-t_pos_x;
								pos.y=mesh->position.coords.x-t_pos_y;
								pos.z=mesh->position.coords.y;
								//Ogre::SceneNode * mesh_scene=((OgreRenderable*)mesh)->CreateScene(map_object_scene);
								mesh->position.coords=pos;
								//mesh->position.coords=Vector3(mesh->position.coords.z-t_pos_x,mesh->position.coords.x-t_pos_y,mesh->position.coords.y);

								//mesh_scene->rotate(Ogre::Vector3(0,0,1),Ogre::Degree(mesh->position.rotation.y));
								//mesh_scene->rotate(Ogre::Vector3(0,1,0),Ogre::Degree(mesh->position.rotation.z));
								//mesh_scene->rotate(Ogre::Vector3(1,0,0),Ogre::Degree(mesh->position.rotation.x));
							}
						}
					}
				}
			}

			tile_pos_y+=TILE_LENGTH;
		}
		tile_pos_x+=TILE_LENGTH;
	}
	//mCamera->setPosition(Vector3ToOgreVector(map->position));
	//scene->rotate(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3(0,0,1)),Ogre::Node::TS_WORLD);
	//position.coords=Vector3(position.coords.x,position.coords.y,position.coords.z);


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
	this->position.coords=position;
}
Point2D<int> WowMap::WorldPositionToMapCoords(Vector3 position)
{
	return Point2D<int>(floor((32 - (position.x / (TILE_LENGTH)))),floor((32 - (position.y / (TILE_LENGTH)))));
}
bool  WowMap::CheckForTileChange(Vector3 position)
{
	return  !(coords_2D==WorldPositionToMapCoords(position));
}
void WowMap::AddDynamicObject(Wow::WowObject * obj)
{
	bool exist=false;
	for (auto dyn_obj:dynamic_objects)
	{
		if (dyn_obj->object==obj)
		{
			exist=true;
			break;
		}
	}
	if (!exist)
	{
		dynamic_objects.push_back(new DynamicObject(obj));
	}
}
void WowMap::RemoveDynamicObject(Wow::WowObject * obj)
{
	bool exist=false;
	for (auto dyn_obj:dynamic_objects)
	{
		if (dyn_obj->object==obj)
		{
			dynamic_objects.erase(std::remove(dynamic_objects.begin(), dynamic_objects.end(), dyn_obj), dynamic_objects.end());
		}
	}
}
void WowMap::MoveMapTiles(Point2D<int> vector)
{
	Tile * tmp_tiles[3][3];
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			for (int ii=0;ii<3;ii++)
			{
				for (int jj=0;jj<3;jj++)
				{

				}
			}
		}
	}
	if (abs(vector.X)<=1 && abs(vector.Y)<=1)
	{

		for (int i=1;i<4;i++)
		{
			for (int j=1;j<4;j++)
			{
				tiles[i][j]=tiles[j+vector.Y][i+vector.X];
			}
		}
		for (int i=0;i<5;i++)
		{
			for (int j=0;j<5;j++)
			{
				if (i==0 || i==4 || j==0 || j==4)
				{
					delete tiles[i][j];
					tiles[i][j]=0;
				}
			}
		}
	}
	else
	{
		for (int i=0;i<5;i++)
		{
			for (int j=0;j<5;j++)
			{
				delete tiles[i][j];
				tiles[i][j]=0;
			}
		}
	}

}


