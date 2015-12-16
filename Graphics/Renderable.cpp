#include "Renderable.h"

unsigned long Renderable::counter=0;
Renderable::Renderable(Link * link):link(link)
{
	id=counter;
	counter++;
}


Renderable::~Renderable(void)
{
	delete link;
}
void Renderable::CreateScene(Ogre::SceneNode * parent)
{
	string name=to_string(GetID());
	scene=parent->createChildSceneNode();
	//Ogre::SceneNode * scene =parent_scene->createChildSceneNode();
	Ogre::ManualObject * manual = scene->getCreator()->createManualObject();
	manual->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
	for (unsigned i=0;i<link->GetVerticeCount();i++)
	{
		manual->position(Vector3ToOgreVector(link->GetVertices()[i].position));
		manual->colour(ColorToOgreColor(link->GetVertices()[i].color));
	}
	for (unsigned long i=0;i<link->GetIndexCount();i++)
	{
		manual->index(link->GetIndices()[i]);
	}
	manual->end();
	Ogre::MeshPtr mesh= manual->convertToMesh(name+"_mesh");

	Ogre::Entity* entity = scene->getCreator()->createEntity(name+"_entity", mesh->getName());
	scene->attachObject(entity);
	scene->getCreator()->destroyManualObject(manual);
}
