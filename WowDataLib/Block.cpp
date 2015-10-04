#include "Block.h"

Block::Block(MCNK * mcnk,bool exist):mcnk(mcnk)
{

	vertices=new Vertice[145];
	coords=mcnk->coords;
	position=mcnk->position;
	int count=0;
	float sx;
	int xc=0;
	int yc=0;
	for (float x=position.x;x<position.x+BLOCK_LENGTH+1;x+=CHUNK_LENGTH)
	{
		for (float y=position.y;y<position.y+BLOCK_LENGTH+1;y+=CHUNK_LENGTH) 
		{
			if (exist)
			{
				vertices[count]=Vertice(Vector3(x,y,position.z+mcnk->mcvt.height[145-count-1]),Color(1.0f,1.0f,1.0f,1.0f));
			}
			else
			{
				vertices[count]=Vertice(Vector3(x,y,position.z),Color(1.0f,1.0f,1.0f,1.0f));
			}
			count++;
		}
		sx=x+(HALF_CHUNK_LENGTH);
		if (count<145)
		{

			for (float sy=position.y+(HALF_CHUNK_LENGTH);sy<position.y+BLOCK_LENGTH-(HALF_CHUNK_LENGTH)+1;sy+=CHUNK_LENGTH)
			{
				if (exist)
				{
					vertices[count]=Vertice(Vector3(sx,sy,position.z+mcnk->mcvt.height[145-count-1]),Color(0.0f,0.0f,0.0f,1.0f));
				}
				else
				{
					vertices[count]=Vertice(Vector3(sx,sy,position.z),Color(0.0f,0.0f,0.0f,1.0f));
				}

				count++;
			}
		}
	}
	vertice_count=count;
	indices=new unsigned short[768];
	unsigned long ind_count=0;
	int off=0;
	for (int i=0;i<127;i++)
	{

		if (i==8||i==25 ||i==42||i==59||i==76||i==93||i==110||i==127)
		{
			i+=9;
		}
		if (ind_count>=768)
			break;
		indices[ind_count]=i;
		indices[ind_count+1]=i+17;
		indices[ind_count+2]=i+9;

		indices[ind_count+3]=i;
		indices[ind_count+4]=i+9;
		indices[ind_count+5]=i+1;

		indices[ind_count+6]=i+18;
		indices[ind_count+7]=i+9;
		indices[ind_count+8]=i+17;

		indices[ind_count+9]=i+1;
		indices[ind_count+10]=i+9;
		indices[ind_count+11]=i+18;
		ind_count+=12;
	}
	index_count=ind_count;
}
Block::Block()
{

}
Block::~Block()
{
}