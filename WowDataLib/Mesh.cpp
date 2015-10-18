#include "Mesh.h"
#include <iostream>
#include <fstream>

using namespace std;

Mesh::Mesh(string name):Renderable()
{
}
Mesh::Mesh():Renderable()
{
}

Mesh::~Mesh()
{
}

void Mesh::ToFile()
{
	ofstream myfile;
	myfile.open ("example.obj");
	for (unsigned long i =0; i<vertice_count;i++)
	{
		myfile<<"v "<<vertices[i].position.x<<" "<<vertices[i].position.y<<" "<<vertices[i].position.z<<endl;
	}
	for (unsigned long i =0; i<index_count;i+=3)
	{
		myfile<<"f "<<l_indices[i]+1<<" "<<l_indices[i+1]+1<<" "<<l_indices[i+2]+1<<endl;
	}

	myfile.close();
}

