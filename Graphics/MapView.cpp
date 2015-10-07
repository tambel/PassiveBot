#include "MapView.h"
#include <FileParser.h>
#include <Adt.h>
#include "Renderable.h"
#include <OgreManualObject.h>
#include "OgreRenderable.h"
#include "Utils.h"
#include <iostream>
#include <iostream>
using namespace std;
MapView::MapView(void)
{

}
MapView::~MapView(void)
{
}
void MapView::InitMap()
{
	OgreRenderable::ClearCouner();
	WowMap * map= new WowMap(Vector3(0,0,0));
	mSceneMgr->getRootSceneNode()->setPosition(0,0,0);
	Ogre::SceneNode * scene= mSceneMgr->getRootSceneNode()->createChildSceneNode("Map");

	float block_pos_x=0;
	float block_pos_y=0;
	float tile_pos_x=0;
	float tile_pos_y=0;
	vector<MapObject*> check_list=vector<MapObject*>();
	for (int i=0;i<3;i++)
	{
		tile_pos_y=0;
		for (int j=0;j<3;j++)
		{

			Ogre::SceneNode * tile_scene = scene->createChildSceneNode("Tile_"+to_string(map->tiles[i][j]->coords.X)+"_"+to_string(map->tiles[i][j]->coords.Y));
			tile_scene->setPosition(tile_pos_y,tile_pos_x,0);
			block_pos_x=0;
			for (int ti=0;ti<16;ti++)
			{
				block_pos_y=0;
				for (int tj=0;tj<16;tj++)
				{
					((OgreRenderable*)(map->tiles[i][j]->blocks[ti][tj]))->CreateScene(tile_scene)->setPosition(block_pos_x,block_pos_y,0);
					block_pos_y+=BLOCK_LENGTH;
				}
				block_pos_x+=BLOCK_LENGTH;
			}
			bool exist;
			for (auto map_object:map->tiles[i][j]->map_objects)
			{
				exist=false;
				for (auto mo:check_list)
				{
					if (mo->root_wmo->id==map_object->root_wmo->id)
					{
						exist=true;
						break;
					}
				}
				if (exist)
					continue;
				check_list.push_back(map_object);
				Ogre::SceneNode * map_object_scene= tile_scene->createChildSceneNode(map_object->name+"_"+to_string(OgreRenderable::GetUIDAndIncrement()));
				for (auto mesh:map_object->meshes)
				{

					float t_pos_x= map->tiles[i][j]->coords.Y * 533.33333-17066.6656;
					float t_pos_y=  map->tiles[i][j]->coords.X * 533.33333-17066.6656;
					Vector3 pos;
					pos.x=mesh->position.z-	t_pos_x;
					pos.y=mesh->position.x-	t_pos_y;
					pos.z=mesh->position.y;
					Ogre::SceneNode * mesh_scene=((OgreRenderable*)mesh)->CreateScene(map_object_scene);
					mesh_scene->setPosition(Vector3ToOgreVector(pos));
					mesh_scene->rotate(Ogre::Vector3(0,0,1),Ogre::Degree(mesh->rotation.y));
					mesh_scene->rotate(Ogre::Vector3(0,1,0),Ogre::Degree(mesh->rotation.z));
					mesh_scene->rotate(Ogre::Vector3(1,0,0),Ogre::Degree(mesh->rotation.x));

				}
			}
			for (auto doodad:map->tiles[i][j]->doodads)
			{
				cout<<doodad->name<<endl;
				Ogre::SceneNode * map_object_scene= tile_scene->createChildSceneNode(doodad->name+"_"+to_string(OgreRenderable::GetUIDAndIncrement()));
				for (auto mesh:doodad->meshes)
				{
					float t_pos_x= map->tiles[i][j]->coords.Y * 533.33333-17066.6656;
					float t_pos_y=  map->tiles[i][j]->coords.X * 533.33333-17066.6656;
					Vector3 pos;
					pos.x=mesh->position.z-	t_pos_x;
					pos.y=mesh->position.x-	t_pos_y;
					pos.z=mesh->position.y;
					Ogre::SceneNode * mesh_scene=((OgreRenderable*)mesh)->CreateScene(map_object_scene);
					mesh_scene->setPosition(Vector3ToOgreVector(pos));
					mesh_scene->rotate(Ogre::Vector3(0,0,1),Ogre::Degree(mesh->rotation.y));
					mesh_scene->rotate(Ogre::Vector3(0,1,0),Ogre::Degree(mesh->rotation.z));
					mesh_scene->rotate(Ogre::Vector3(1,0,0),Ogre::Degree(mesh->rotation.x));

				}
			}
			tile_pos_y+=TILE_LENGTH;
		}
		tile_pos_x+=TILE_LENGTH;
	}
	int k;
	k=10;
	//delete map;
}
void MapView::createScene(void)
{
	
	InitMap();
	/*
	unsigned length;
	char * buff;
	unsigned length2;
	char * buff2;
	ifstream file("E:\\Extracted\\WORLD\\KALIMDOR\\BARRENS\\PASSIVEDOODADS\\wagon\\BarrensWagon01.m2", ios::binary | ios::ate);
	if (file) {
		// get length of file:
		file.seekg (0, file.end);
		length = file.tellg();
		file.seekg (0, file.beg);
		buff = new char [length];
		file.read (buff,length);
	}
	file=ifstream("E:\\Extracted\\WORLD\\KALIMDOR\\BARRENS\\PASSIVEDOODADS\\wagon\\BarrensWagon0100.skin", ios::binary | ios::ate);

	if (file) {
		// get length of file:
		file.seekg (0, file.end);
		length2 = file.tellg();
		file.seekg (0, file.beg);
		buff2 = new char [length2];
		file.read (buff2,length);
	}
	unsigned vert_count=*(unsigned*)(buff+0x3C);
	unsigned vert_offset=*(unsigned*)(buff+0x40);
	M2Vertice * vertices=new M2Vertice[vert_count];
	M2Vertice vert[340];
	memcpy(vertices,buff+vert_offset,vert_count*48);
	//memcpy(vert,buff+vert_offset,vert_count*48);
	struct SkinHeader {
		unsigned ID;
		unsigned nIndices;
		unsigned ofsIndices;
		unsigned nTriangles;
		unsigned ofsSubmeshes;
		unsigned nTextureUnits;
		unsigned ofsTextureUnits;
		unsigned LOD;
	};
	SkinHeader * h=(SkinHeader*)(buff2);
	unsigned short * indices= new unsigned short[h->nIndices];
	unsigned short ind[1000];
	memcpy(indices,buff2+h->ofsIndices,h->nIndices*2);
	memcpy(ind,buff2+h->ofsIndices,h->nIndices*2);
	//Triangle tri
	//memcpy(t,buff2+h->ofsSubmeshes,h->nTriangles*2);
	//unsigned short tu[564];
	Triangle * tr = new Triangle[h->nTriangles/3];
	memcpy(tr,buff2+h->ofsSubmeshes,h->nTriangles*2);
	//memcpy(t,buff2+h->nIndices*2,h->nTriangles*2);
	//memcpy(tu,buff2+h->nIndices*2,h->nTriangles*2);
	Ogre::SceneNode * node= mSceneMgr->getRootSceneNode()->createChildSceneNode();
	Ogre::ManualObject * manual= mSceneMgr->createManualObject("man");
	manual->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);

	for (unsigned i=0;i<vert_count;i++)
	{
		vertices[i].position=Vector3(vertices[i].position.x,-vertices[i].position.y,vertices[i].position.z);
		manual->position(Vector3ToOgreVector(vertices[i].position));
		if (i%2==0)
			manual->colour(Ogre::ColourValue::White);
		else 
			manual->colour(Ogre::ColourValue::Green);
			
		
	}
	for (unsigned i=0;i<h->nTriangles/3;i++)
	{
		manual->index(tr[i].indices[0]);
		manual->index(tr[i].indices[1]);
		manual->index(tr[i].indices[2]);
		//manual->index(tr[i].indices[0]);
		//manual->index(tr[i].indices[1]);
		//manual->index(tr[i].indices[2]);

		//manual->index(indices[i]);
		
	}

	manual->end();
	node->attachObject(manual);
	int k;

	k=10;
	*/
}