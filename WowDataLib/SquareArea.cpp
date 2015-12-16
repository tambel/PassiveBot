#include "SquareArea.h"


SquareArea::SquareArea(Location * location, Point2D<int> block_coordinates,Point2D<int> coordinates,int radius):location(location), block_coordinates(block_coordinates),coordinates(coordinates),radius(radius)
{
	Chunk *** tmp_chunks;
	int array_size=radius*2+1;
	tmp_chunks=new Chunk**[array_size];
	//chunks=new Chunk * [array_size*array_size];
	chunks=vector<Chunk*>();
	for (int i=0;i<array_size;i++)
	{
		tmp_chunks[i]=new Chunk * [array_size];
	}
	//Point2D<int> abs_center_pos=Point2D<int>(coordinates+Point2D<int>(16,16));
	//Point2D<int> abs_center_pos=coordinates+Point2D<int>(16,16);
	Point2D<int> area_position=(coordinates+Point2D<int>(16,16))-Point2D<int>(radius,radius);
	unsigned counter=0;
	for (int i=0;i<array_size;i++)
	{
		for (int j=0;j<array_size;j++)
		{
			Point2D<int> abs_pos=area_position+Point2D<int>(i,j);
			tmp_chunks[i][j]=ADTWorker::GetChunk(location,block_coordinates+=(Point2D<int>(abs_pos.X/16,abs_pos.Y/16)-Point2D<int>(1,1)),Point2D<int>(abs_pos.X%16,abs_pos.Y%16));
			
			//chunks[chunk_number]=tmp_chunks[i][j];
			if (tmp_chunks[i][j])
			{
				tmp_chunks[i][j]->SetRelativePosition(Vector3(j*Metrics::ChunkSize,-i*Metrics::ChunkSize,tmp_chunks[i][j]->GetGamePosition().z));
				chunks.push_back(tmp_chunks[i][j]);

			}
			if (i==0)
			{
				for (int v=0;v<145;v++)
				{
					if (j<10)
					tmp_chunks[i][j]->GetVertices()[v].color=Utils::Graphics::Color(1.0f,0.0f,1.0f,0.0f);
					if (j>10)
					tmp_chunks[i][j]->GetVertices()[v].color=Utils::Graphics::Color(0.0f,1.0f,1.0f,0.0f);
				}
			}
			counter++;
		}
	}
	
}


SquareArea::~SquareArea(void)
{
}
