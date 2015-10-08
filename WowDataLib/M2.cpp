#include "M2.h"
#include "FileParser.h"
#include <iostream>
using namespace std;
M2::M2(string path)
{
	int view_index=0;
	meshes=vector<Mesh*>();
	data=0;
	file_length=0;
	vertices=0;
	indices=0;
	index_count=0;
	vert_count=0;
	triangles=0;
	triangles_count=0;
	skin_file_length=0;
	
	M2Header_s *s;
	if (FileParser::FileExist(path))
	{

		file_length=FileParser::Parse(path,&data);
		s =(M2Header_s*)data;
		vert_count=s->numVertices;
		//vert_count=*(unsigned*)(data+0x3C);
		//unsigned vert_off=*(unsigned*)(data+0x40);
		vertices=new M2Vertice[s->numVertices];
		//M2Vertice vv[1000];
		memcpy(vertices,data+s->verticesOff,s->numVertices*48);
	}
	//cout<<path<<endl;
	string skin_path=path;
	if (path=="E:\\Extracted\\WORLD\\KALIMDOR\\BARRENS\\PASSIVEDOODADS\\TREES\\BarrensTree04.m2")
	{
		int k;
		k=10;
	}
	if (path=="E:\\Extracted\\WORLD\\KALIMDOR\\BARRENS\\PASSIVEDOODADS\\TREES\\BarrensTree0400.skin")
	{
		int k;
		k=10;
	}
	skin_path=skin_path.erase(skin_path.length()-3,3)+"0"+to_string(view_index)+".skin";

	if (FileParser::FileExist(skin_path))
	{
		
		typedef struct SkinHeader {
		unsigned ID;
		unsigned nIndices;
		unsigned ofsIndices;
		unsigned nTriangles;
		unsigned ofsTriangles;
		unsigned nProperties;
		unsigned ofsProperties;
		unsigned nSubmeshes;
		unsigned ofsSubmeshes;
		unsigned nTextureUnits;
		unsigned ofsTextureUnits;
		unsigned LOD;
		};
	
		 
		skin_file_length=FileParser::Parse(skin_path,&skin_data);
		SkinHeader * h =(SkinHeader*)(skin_data);
		indices=0;
		triangles_count=0;
		index_count=h->nIndices;
		indices=new unsigned short[index_count];
		memcpy(indices,skin_data+h->ofsIndices,index_count*2);
		triangles_count=h->nTriangles;
		triangles=new Triangle[triangles_count];
		memcpy(triangles,skin_data+h->ofsTriangles,h->nTriangles*2);
		exist=true;
	}
	else
	{
		exist=false;
	}
}


M2::~M2(void)
{
	delete [] data;
	data=0;
	delete [] skin_data;
	skin_data=0;
	delete [] vertices;
	vertices=0;
	delete [] indices;
	indices=0;
	delete [] triangles;
	triangles=0;
	for (auto mesh:meshes)
	{
		delete mesh;
	}
	meshes.clear();
}
