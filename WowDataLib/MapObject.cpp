#include "MapObject.h"
#include "WMO.h"

MapObject::MapObject(string path,  WmoInfo wmo_info)
{
	name=path;
	position=wmo_info.position;
	root_wmo=new RootWMO(path);
	meshes=vector<Mesh*>();
	for (auto wmo:root_wmo->group)
	{
		Mesh * mesh=new Mesh(wmo->name);
		mesh->index_count=wmo->index_count;
		mesh->vertice_count=wmo->vertice_count;
		mesh->vertices=new Vertice[mesh->vertice_count];
		mesh->indices=new unsigned short[mesh->index_count];
		for (unsigned long i=0;i<mesh->vertice_count;i++)
		{
			if (i%2==0)
				mesh->vertices[i]=Vertice(wmo->vertices[i],Color(1.0f,1.0f,0.0f,1.0f));
			else 
				mesh->vertices[i]=Vertice(wmo->vertices[i],Color(0.0f,0.0f,0.0f,1.0f));
		}
		//memcpy(mesh->vertices,wmo->movt->vetices,wmo->movt->length);
		memcpy(mesh->indices,wmo->indices,wmo->index_count*2);
		mesh->position=wmo_info.position;
		mesh->rotation=wmo_info.rotation;
		meshes.push_back(mesh);
		/*
		old_vertices=new Vertice[vertice_count];
		old_indices=new unsigned short[index_count];
		old_ind_count=index_count;
		old_vert_count=vertice_count;
		memcpy(old_vertices,vertices,vertice_count*12);
		memcpy(old_indices,indices,index_count*2);
		index_count+=wmo->movi->length/2;
		vertice_count+=wmo->movt->length/12;
		delete [] indices;
		delete [] vertices;
		vertices=new Vertice[vertice_count];
		memcpy(vertices,old_vertices,old_vert_count*12);

		for (unsigned long  i=0;i<wmo->movt->length/12;i++)
		{
			vertices[vert_ind]=Vertice(wmo->movt->vetices[i],Color(1.0f,1.0f,1.0f,1.0f));
			vert_ind++;
		}
		for (unsigned long i=0;i<wmo->movi->length/2;i++)
		{
			wmo->movi->indices[i]+=old_vert_count;
		}
		indices=new unsigned short[index_count];
		memcpy(indices,old_indices,old_ind_count*2);
		memcpy((char*)indices+old_ind_count*2,wmo->movi->indices,wmo->movi->length);
		*/

	}
	
}


MapObject::~MapObject(void)
{
	delete root_wmo;
	for (auto mesh:meshes)
	{
		delete ((Renderable*)mesh);
	}
	meshes.clear();
	
}
