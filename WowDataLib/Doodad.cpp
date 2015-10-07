#include "Doodad.h"
unsigned ii=0;
#include <iostream>
using namespace std;
Doodad::Doodad(string path, M2Info info)
{
	
	name=path;
	if (name=="E:\\Extracted\\WORLD\\AZEROTH\\DEADWINDPASS\\PASSIVEDOODADS\\ROCKTREES\\DEADWINDPASSROCKTREE04.M2")
	{
		int k;
		k=10;
	}
	meshes=vector<Mesh*>();
	m2=new M2(path);
	Mesh * mesh=new Mesh(name);
	mesh->triangles_count=m2->triangles_count;
	mesh->triangles=new Triangle[mesh->triangles_count];
	mesh->vertice_count=m2->vert_count;
	mesh->vertices=new Vertice[mesh->vertice_count];
	mesh->index_count=m2->index_count;
	mesh->indices=new unsigned short[mesh->index_count];
	unsigned iia=(unsigned)&ii;
	//cout<<name;
	
	for (unsigned long i=0;i<m2->vert_count;i++)
	{
		if (i%2==0)
			mesh->vertices[i]=Vertice(m2->vertices[i].position,Color(1.0f,1.0f,0.0f,1.0f));
		else 
			mesh->vertices[i]=Vertice(m2->vertices[i].position,Color(0.0f,0.0f,0.0f,1.0f));
		ii++;
		//cout<<ii<<endl;
	}
	memcpy(mesh->indices,m2->indices,mesh->index_count*2);
	memcpy(mesh->triangles,m2->triangles,mesh->triangles_count*6);
	mesh->position=info.position;
	mesh->rotation=info.rotation;
	if(m2->exist)
	meshes.push_back(mesh);
}


Doodad::~Doodad(void)
{
	delete m2;
	for (auto mesh:meshes)
	{
		delete mesh;
	}
	meshes.clear();
}
