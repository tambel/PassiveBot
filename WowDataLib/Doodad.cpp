#include "Doodad.h"
#include <iostream>
using namespace std;
Doodad::Doodad(string path, M2Info info)
{
	name=path;
	id=info.id;
	meshes=vector<Mesh*>();
	M2 * m2=new M2(path);
	Mesh * mesh=new Mesh(name);
	position=info.position;
	scale=info.scale;
	mesh->triangles_count=m2->triangles_count;
	mesh->triangles=new Triangle[mesh->triangles_count];
	mesh->vertice_count=m2->vert_count;
	mesh->vertices=new Vertice[mesh->vertice_count];
	mesh->index_count=m2->index_count;
	mesh->indices=new unsigned short[mesh->index_count];
	for (unsigned long i=0;i<m2->vert_count;i++)
	{
		if (i%2==0)
			mesh->vertices[i]=Vertice(m2->vertices[i].position*scale,Color(1.0f,1.0f,0.0f,1.0f));
		else 
			mesh->vertices[i]=Vertice(m2->vertices[i].position*scale,Color(0.0f,0.0f,0.0f,1.0f));
	}
	memcpy(mesh->indices,m2->indices,mesh->index_count*2);
	memcpy(mesh->triangles,m2->triangles,mesh->triangles_count*6);
	mesh->position=info.position;
	if(m2->exist)
		meshes.push_back(mesh);
	delete m2;
}


Doodad::~Doodad(void)
{
	for (auto mesh:meshes)
	{
		delete mesh;
	}
	meshes.clear();
}
