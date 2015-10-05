#include "OgreRenderable.h"
#include <OgreManualObject.h>
#include "Utils.h"
#include <string>
using namespace std;
unsigned long OgreRenderable::current_uid=0;

unsigned long OgreRenderable::GetUIDAndIncrement()
{
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
	for (unsigned long i=0;i<vertice_count;i++)
	{
		manual->position(Vector3ToOgreVector(vertices[i].position));
		manual->colour(ColorToOgreColor(vertices[i].color));
	}
	for (unsigned long i=0;i<index_count;i++)
	{
		manual->index(indices[i]);
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