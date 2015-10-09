#include "OgreRenderable.h"
#include <OgreManualObject.h>
#include "Utils.h"
#include <string>
#include <Mesh.h>
using namespace std;
using namespace Utils::Graphics;
unsigned long OgreRenderable::current_uid=0;

unsigned long OgreRenderable::GetUIDAndIncrement()
{
	Ogre::Node * n;
	return current_uid++;
}
void OgreRenderable::ClearCouner()
{
	current_uid=0;
}
Ogre::SceneNode * OgreRenderable::CreateScene(Ogre::SceneNode * parent_scene)
{
	string maual_name=to_string(GetUIDAndIncrement())+"_"+name;
	scene =parent_scene->createChildSceneNode();
	Ogre::ManualObject * manual=scene->getCreator()->createManualObject(maual_name);
	manual->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
	if (triangles==0)
	{
		for (unsigned long i=0;i<vertice_count;i++)
		{
			manual->position(Vector3ToOgreVector(vertices[i].position));
			manual->colour(ColorToOgreColor(vertices[i].color));
		}
		for (unsigned long i=0;i<index_count;i++)
		{
			manual->index(indices[i]);
		}
		
	}
	else
	{
		for (unsigned long i=0;i<vertice_count;i++)
		{
			manual->position(Vector3ToOgreVector(vertices[i].position));
			manual->colour(ColorToOgreColor(vertices[i].color));
		}
		for (unsigned long i=0;i<triangles_count/3;i++)
		{
			manual->index(triangles[i].indices[0]);
			manual->index(triangles[i].indices[1]);
			manual->index(triangles[i].indices[2]);
		}
		/*
		for (unsigned long i=0;i<triangles_count/2;i++)
		{
			manual->position(Vector3ToOgreVector(vertices[indices[triangles[i].indices[0]]].position));
			manual->colour(ColorToOgreColor(vertices[indices[triangles[i].indices[0]]].color));
			
			manual->position(Vector3ToOgreVector(vertices[indices[triangles[i].indices[1]]].position));
			manual->colour(ColorToOgreColor(vertices[indices[triangles[i].indices[1]]].color));
			
			manual->position(Vector3ToOgreVector(vertices[indices[triangles[i].indices[2]]].position));
			manual->colour(ColorToOgreColor(vertices[indices[triangles[i].indices[2]]].color));
			
			
		}
		for (unsigned long i=0;i<triangles_count/2;i++)
		{
			
			manual->index(indices[triangles[i].indices[0]]);
			manual->index(indices[triangles[i].indices[1]]);
			manual->index(indices[triangles[i].indices[2]]);
			
		}
		*/
		
	}
	manual->end();
	Ogre::MeshPtr mesh= manual->convertToMesh(maual_name+"_mesh");
	Ogre::Entity* entity = parent_scene->getCreator()->createEntity(maual_name+"_entity", mesh->getName());

	scene->attachObject(entity);
	return scene;
}
void OgreRenderable::SetPosition(Vector3 position)
{
	scene->setPosition(Vector3ToOgreVector(position));
}