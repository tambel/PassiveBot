#include "MapObjectRenderable.h"
#include "OgreManualObject.h"
#include "Utils.h"

void MeshRenderable::CreateScene(Ogre::SceneNode * parent_scene)
{
	string maual_name=to_string(GetUIDAndIncrement())+"_"+name;
	Ogre::SceneNode * scene =parent_scene->createChildSceneNode();
	Ogre::ManualObject * manual=scene->getCreator()->createManualObject(maual_name);
	manual->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
	for (unsigned long i=0;i<vertice_count;i++)
	{
		manual->position(Vector3ToOgreVector(vertices[i].position));
		if (i%2==0)
		{
			manual->colour(Ogre::ColourValue::Green);
		}
		else if (i%3==0)
		{
			manual->colour(Ogre::ColourValue::Black);
		}
		else
		{
			manual->colour(Ogre::ColourValue::White);
		}
	}
	for (unsigned long i=0;i<index_count;i++)
	{
		manual->index(indices[i]);
	}
	manual->end();
	Ogre::MeshPtr mesh= manual->convertToMesh(maual_name+"_mesh");
	Ogre::Entity* entity = parent_scene->getCreator()->createEntity(maual_name+"_entity", mesh->getName());
	scene->attachObject(entity);
	//scene->setPosition(Vector3ToOgreVector(position));
}
void MapObjectRenderable::CreateScene(Ogre::SceneNode * parent_scene)
{

	Ogre::SceneNode * scene =parent_scene->createChildSceneNode(to_string(GetUIDAndIncrement())+"_"+name);
	for (auto mesh:meshes)
	{
		((MeshRenderable*)mesh)->CreateScene(scene);
	}
	float tmp=position.x;
	position.x=-position.z;
	position.z=tmp;
	position.y=-position.y;
	scene->setPosition(Vector3ToOgreVector(position));

	/*
	string maual_name=to_string(GetUIDAndIncrement())+"_"+name;
	Ogre::SceneNode * scene =parent_scene->createChildSceneNode();
	Ogre::ManualObject * manual=scene->getCreator()->createManualObject(maual_name);
	manual->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
	for (unsigned long i=0;i<vertice_count;i++)
	{
	manual->position(Vector3ToOgreVector(vertices[i].position));
	if (i%2==0)
	{
	manual->colour(Ogre::ColourValue::Green);
	}
	else if (i%3==0)
	{
	manual->colour(Ogre::ColourValue::Black);
	}
	else
	{
	manual->colour(Ogre::ColourValue::White);
	}
	}
	for (unsigned long i=0;i<index_count;i++)
	{
	manual->index(indices[i]);
	}
	manual->end();
	Ogre::MeshPtr mesh= manual->convertToMesh(maual_name+"_mesh");
	Ogre::Entity* entity = parent_scene->getCreator()->createEntity(maual_name+"_entity", mesh->getName());
	scene->attachObject(entity);
	float tmp=position.x;
	position.x=-position.z;
	position.z=tmp;
	position.y=-position.y;
	scene->setPosition(Vector3ToOgreVector(position));
	*/



}
