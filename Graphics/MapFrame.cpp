#include "MapFrame.h"
#include "WowDataLib\ADTWorker.h"
#include <OgreSceneManager.h>
#include "Utils.h"
#include "WowDataLib\SquareArea.h"
#include "Renderable.h"
#include "ChunkLink.h"
MapFrame::MapFrame(void)
{
	area=new SquareArea(Game::LocationBase::Get("Kalimdor"),Point2D<int>(31,41),Point2D<int>(0,1),10);
}


MapFrame::~MapFrame(void)
{
	
}
void MapFrame::createScene()
{
	createTerrain();


	/*
	SquareArea * area=new SquareArea(Game::LocationBase::Get("Kalimdor"),Point2D<int>(31,41),Point2D<int>(0,1),10);
	area=new SquareArea(Game::LocationBase::Get("Kalimdor"),Point2D<int>(31,41),Point2D<int>(0,5),10);
	Chunk * c= ADTWorker::GetChunk(LocationBase::Get("Kalimdor"),Point2D<int>(31,41),Point2D<int>(10,12));
	SceneNode * root_scene= mSceneMgr->getRootSceneNode();
	//Ogre::SceneNode * scene =parent_scene->createChildSceneNode();
	ManualObject * manual=mSceneMgr->createManualObject("chunk");
	manual->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
	for (unsigned i=0;i<145;i++)
	{
		manual->position(Vector3ToOgreVector(c->GetVertices()[i].position));
		manual->colour(ColorToOgreColor(c->GetVertices()[i].color));
	}
	for (unsigned long i=0;i<768;i++)
	{
		manual->index(c->GetIndices()[i]);
	}
	manual->end();
	MeshPtr mesh= manual->convertToMesh("chunk_mesh");

	Ogre::Entity* entity = root_scene->getCreator()->createEntity("chunk_mesh_entity", mesh->getName());
	root_scene->attachObject(entity);
	
	root_scene->getCreator()->destroyManualObject(manual);
	*/
	//mCamera->setPosition(Vector3ToOgreVector(c->GetVertices()[0].position));
	mCamera->setPosition(Ogre::Vector3(0,0,0));
}

void MapFrame::createTerrain()
{
	for (auto chunk:*area->GetChunks())
	{
		Renderable * rend=new Renderable(new ChunkLink(chunk));
		rend->CreateScene(mSceneMgr->getRootSceneNode());
		rend->GetScene()->setPosition(Vector3ToOgreVector(chunk->GetRelativePosition()));
	}
}
