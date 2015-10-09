#pragma once
#include <string>
#include <vector>
#include "Mesh.h"
using namespace Utils::WowTypes; 
using namespace Utils::Graphics;
using namespace std;


struct M2Vertice
{
	Vector3 position;
	unsigned char bone_weights[4];
	unsigned char bone_indices[4];
	Vector3	normal_vector;
	struct Vector2
	{
		float X;
		float Y;
	}tex_coords[2];
};
struct View
{
	unsigned index_count;
	unsigned indices_offset;
	unsigned triangles_count;
	unsigned triangles_offset;

};
struct M2Info
{
	string name;
	Vector3 position;
	Vector3 rotation;
	unsigned long id;
};
struct M2Header_s {
	char id[4];
	char version[4];
	unsigned int  nameLength;
	unsigned int  nameOff;
	unsigned int  flags;
private:
	unsigned int  pad0[10];
public:
	unsigned int  numVertices;
	unsigned int  verticesOff;
private:
	unsigned int  pad1[37];
public:
	unsigned int  numBoundingTriangles;
	unsigned int  boundingTriangleOff;
	unsigned int  numBoundingVertices;
	unsigned int  boundingVerticesOff;
	unsigned int  numBoundingNormals;
	unsigned int  boundingNormalsOff;
};
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
class M2
{

public:
	bool exist;
	unsigned long vert_count;
	M2Vertice * vertices;
	unsigned short * indices;
	unsigned long index_count;
	Triangle * triangles;
	unsigned long triangles_count;
	char * data;
	unsigned long file_length;
	char * skin_data;
	unsigned long skin_file_length;
	vector<Mesh*> meshes;
	M2(string path);
	~M2(void);
};

