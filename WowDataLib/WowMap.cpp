#pragma once
#include "WowMap.h"

WowMap::WowMap(Vector3 ppos)
{
	vector<MapObject*> check_list=vector<MapObject*>();

	bool exist=false;
	int x=floor((32 - (ppos.x / (TILE_LENGTH))));
	int y=floor((32 - (ppos.y / (TILE_LENGTH))));
	float block_pos_x=0;
	float block_pos_y=0;
	float tile_pos_x=0;
	float tile_pos_y=0;
	this->position.coords.x=17066.66656-((float)x * 533.33333);
	this->position.coords.y=17066.66656-((float)y * 533.33333);
	this->position.coords.z=0;
	new_object=false;
	tiles[0][0]=new Tile(y-1,x-1);
	tiles[0][1]=new Tile(y-1,x);
	tiles[0][2]=new Tile(y-1,x+1);
	tiles[1][0]=new Tile(y,x-1);
	tiles[1][1]=new Tile(y,x);
	tiles[1][2]=new Tile(y,x+1);
	tiles[2][0]=new Tile(y+1,x-1);
	tiles[2][1]=new Tile(y+1,x);
	tiles[2][2]=new Tile(y+1,x+1);

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

			tile_pos_y+=TILE_LENGTH;
		}
		tile_pos_x+=TILE_LENGTH;
	}
	//mCamera->setPosition(Vector3ToOgreVector(map->position));
	//scene->rotate(Ogre::Quaternion(Ogre::Degree(180), Ogre::Vector3(0,0,1)),Ogre::Node::TS_WORLD);
	position.coords=Vector3(position.coords.x+TILE_LENGTH,position.coords.y+TILE_LENGTH,position.coords.z);
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
	this->position.coords=position;
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



