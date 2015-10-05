#include "WMO.h"
#include "FileParser.h"
WMO::WMO(string path)
{
	
	unsigned long group_length;
	char * group=0;
	char * tmp;
	exist=true;
	indices=0;
	vertices=0;
	group_length=FileParser::Parse(path,&group);
	if (group_length==0)
	{
		exist=false;
		return;
	}
	if (exist)
	{
		for (unsigned long  i=0;i<group_length;i++)
		{
			tmp=group+i;
			if (memcmp(tmp,"IVOM",4)==0)
			{
				//movi=new MOVI;
				//movi=*(MOVI*)(tmp+4);
				MOVI * movi=(MOVI*)(tmp+4);
				index_count=movi->length/2;
				indices=new unsigned short[index_count];
				memcpy(indices,tmp+8,movi->length);
			}
			if (memcmp(tmp,"TVOM",4)==0)
			{
				//movt=new MOVT;
				MOVT *movt=(MOVT*)(tmp+4);
				vertice_count=movt->length/12;
				vertices=new Vector3[vertice_count];
				memcpy(vertices,tmp+8,movt->length);
			}
		}
	}
	delete [] group;
}
WMO::~WMO()
{
	delete [] vertices;
	vertices=0;
	delete [] indices;
	indices=0;
	vertice_count=0;
	index_count=0;
	
}
RootWMO::RootWMO(string path)
{
	name=path;
	char * root=0;
	unsigned long  root_length=FileParser::Parse(path,&root);
	char * tmp;

	for (unsigned long  i=0;i<root_length;i++)
	{
		tmp=root+i;
		if (memcmp(tmp,"NGOM",4)==0)
		{
			//mogn=new MOGN();
			//*mogn=*(MOGN*)(tmp+4);
			//mogn->group_names=new char[mogn->length];
			//memcpy(mogn->group_names,tmp+10,mogn->length);
			//mogn=mogn;

		}
		if (memcmp(tmp,"IGOM",4)==0)
		{
			//mogi=new MOGI();
			//mogi=(MOGI*)(tmp+4);
			//memcpy(mogi->offset,tmp+8,30*4);

		}
	}
	group=vector<WMO*>();
	int counter=0;
	string tmp_path;
	
	while(true)
	{
		tmp_path=path;
		string sub_name=to_string(counter);
		tmp_path.erase(tmp_path.length()-4,4);
		while (sub_name.length()<3)
		{
			sub_name="0"+sub_name;
		}
		tmp_path=tmp_path+"_"+sub_name+".wmo";
		if (FileParser::FileExist(tmp_path))
		{
			group.push_back(new WMO(tmp_path));
			counter++;
			continue;
		}
		else
		{
			break;
		}

	}

	delete [] root;

}


RootWMO::~RootWMO(void)
{
	for (auto wmo:group)
	{
		delete wmo;
	}
	group.clear();
}
