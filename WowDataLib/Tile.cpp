#include "Tile.h"
#include <string>
using namespace std;
Tile::Tile(int x,int y)
{

	wstring path=TERRAIN_PATH;
	path+=L"Kalimdor\\Kalimdor_"+to_wstring(x)+L"_"+to_wstring(y);

	//Adt * adt=new Adt(L"C:\\Users\\laptop\\Desktop\\Extracted\\World\\Maps\\Kalimdor\\Kalimdor_36_51");
	coords.X=x;
	coords.Y=y;
	Adt * adt=new Adt(path);
	if (adt->IsExist())
	{
		for (unsigned i=0;i<16;i++)
		{
			for (unsigned j=0;j<16;j++)
			{
				//for (unsigned i=0;i<adt->mcnk_list.size();i++)
				for (auto mcnk:adt->mcnk_list)
				{
					if (mcnk->coords.X==i && mcnk->coords.Y==j)
					{
						blocks[i][j]=new Block(mcnk);
					}
				}
			}
		}

	}



	int k;
	k=0;
}
Tile::Tile(void)
{
}
Tile::~Tile(void)
{
}
void Tile::SetPosition(Vector3 position)
{
	this->position=position;
}