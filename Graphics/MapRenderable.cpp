#include "MapRenderable.h"
#include "MapObjectRenderable.h"
#include "OgreManualObject.h"
#include "Utils.h"
#include <string>
using namespace std;





void BlockRenderable::CreateEntity(Ogre::SceneNode * parent_scene,bool flat)
{
	string parent_name=parent_scene->getName();
	string maual_name=to_string(uid)+"_"+parent_name+"_"+to_string(mcnk->coords.X)+"_"+to_string(mcnk->coords.Y);
	Ogre::ManualObject *manual=parent_scene->getCreator()->createManualObject(maual_name);
	manual->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
	for (int i=0;i<vertice_count;i++)
	{
		manual->position(Vector3ToOgreVector(vertices[i].position));
		manual->colour(ColorToOgreColor(vertices[i].color));
	}
	for (int i=0;i<index_count;i++)
	{
		manual->index(indices[i]);
	}
	manual->end();
	Ogre::MeshPtr mesh= manual->convertToMesh(maual_name+"_mesh");

	Ogre::Entity* entity = parent_scene->getCreator()->createEntity(maual_name+"_entity", mesh->getName());
	parent_scene->attachObject(entity);
}
void TileRenderable::CreateScene(Ogre::SceneNode * parent_scene)
{

	string name="tile_"+to_string(coords.X)+" "+to_string(coords.Y); 
	Ogre::SceneNode *scene_node=parent_scene->createChildSceneNode(name);
		for (int i=0;i<16;i++)
		{
			for (int j=0;j<16;j++)
			{
				((BlockRenderable*)blocks[i][j])->CreateEntity(scene_node,!exists);
			}
		}
}
void MapRenderable::CreateScene(Ogre::SceneNode * parent_scene)
{
	Ogre::SceneNode *scene_node=parent_scene->getCreator()->getRootSceneNode()->createChildSceneNode("map");
//	((TileRenderable*)tiles[0][0])->CreateScene(scene_node);
	//((TileRenderable*)tiles[0][1])->CreateScene(scene_node);
	//((TileRenderable*)tiles[0][2])->CreateScene(scene_node);
	//((TileRenderable*)tiles[1][0])->CreateScene(scene_node);
	((TileRenderable*)tiles[1][1])->CreateScene(scene_node);
	//((TileRenderable*)tiles[1][2])->CreateScene(scene_node);
	//((TileRenderable*)tiles[2][0])->CreateScene(scene_node);
	//((TileRenderable*)tiles[2][1])->CreateScene(scene_node);
	//((TileRenderable*)tiles[2][2])->CreateScene(scene_node);
	for (auto map_object:tiles[1][1]->map_objects)
	{

		((MapObjectRenderable*)map_object)->CreateScene(scene_node);

	}
}