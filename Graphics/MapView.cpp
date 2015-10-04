#include "MapView.h"
#include <FileParser.h>
#include <Adt.h>
#include "Renderable.h"
#include <OgreManualObject.h>
#include "MapRenderable.h"
#include "OgreRenderable.h"
MapView::MapView(void)
{

}
MapView::~MapView(void)
{
}
void MapView::InitMap()
{
	OgreRenderable::ClearCouner();
	map=new WowMap(Vector3(0,0,0));
	((MapRenderable*)map)->CreateScene(mSceneMgr->getRootSceneNode());

	//mSceneMgr->getRootSceneNode()->addChild(((MapRenderable*)map)->CreateScene(mSceneMgr))
	/*
			string n="name"+to_string(b);
			manual[b] = mSceneMgr->createManualObject(n);
			manual[b]->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
			for (int i=0;i<145;i++)
			{
				manual[b]->position(map->tile->blocks[b]->vertices[i].position.x,map->tile->blocks[b]->vertices[i].position.y,map->tile->blocks[b]->vertices[i].position.z);
				manual[b]->colour(Ogre::ColourValue(map->tile->blocks[b]->vertices[i].color.r,map->tile->blocks[b]->vertices[i].color.g,map->tile->blocks[b]->vertices[i].color.b,map->tile->blocks[b]->vertices[i].color.a));

			}

			for (int i=0;i<768;i++)
			{
				manual[b]->index(map->tile->blocks[b]->indices[i]);
			}
			manual[b]->end();
			Ogre::MeshPtr mesh= manual[b]->convertToMesh(n+"_mesh");
			
			Ogre::Entity* m_pGraphicEntity = mSceneMgr->createEntity(n+"_ent", mesh->getName());

			Ogre::SceneNode * node=mSceneMgr->getRootSceneNode()->createChildSceneNode();

			

			node->attachObject(m_pGraphicEntity);
			//node->rotate(Ogre::Vector3(0,1,0),Ogre::Radian(Ogre::Math::PI/2),Ogre::Node::TransformSpace::TS_WORLD);
			//Ogre::SceneNode * node= (Ogre::SceneNode*)mSceneMgr->getRootSceneNode()->getChild(n+"_ent");
			*/
			
			
		
	

	mCamera->setPosition(-9600.0f,-1066.66602f,72.7356796f);
}
void MapView::createScene(void)
{
	InitMap();
}