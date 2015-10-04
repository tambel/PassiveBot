#include "WMO.h"
#include "FileParser.h"
WMO::WMO(string path)
{
	unsigned long group_length;
	char * group;
	char * tmp;
	exist=true;
	name=path;
	group_length=FileParser::Parse((path).c_str(),&group);
	if (group_length==0)
	{
		exist=false;
		return;
	}
	for (unsigned long  i=0;i<group_length;i++)
	{
		tmp=group+i;
		if (memcmp(tmp,"PGOM",4)==0)
		{
			MOGP * mogp=new MOGP;
			*mogp=*(MOGP*)(tmp+4);
		}
		if (memcmp(tmp,"IVOM",4)==0)
		{
			movi=new MOVI;
			*movi=*(MOVI*)(tmp+4);
			movi->indices=new unsigned short[movi->length/2];
			memcpy(movi->indices,tmp+8,movi->length);
		}
		if (memcmp(tmp,"TVOM",4)==0)
		{
			movt=new MOVT;
			*movt=*(MOVT*)(tmp+4);
			movt->vetices=new Vector3[movt->length/12];
			memcpy(movt->vetices,tmp+8,movt->length);
		}
	}
}
WMO::~WMO()
{

}
RootWMO::RootWMO(string path)
{
	name=path;
	char * root=0;
	unsigned long  root_length=FileParser::Parse(path.c_str(),&root);
	char * tmp;

	for (unsigned long  i=0;i<root_length;i++)
	{
		tmp=root+i;
		if (memcmp(tmp,"NGOM",4)==0)
		{
			mogn=new MOGN();
			*mogn=*(MOGN*)(tmp+4);
			mogn->group_names=new char[mogn->length];
			memcpy(mogn->group_names,tmp+10,mogn->length);
			mogn=mogn;

		}
		if (memcmp(tmp,"IGOM",4)==0)
		{
			mogi=new MOGI();
			mogi=(MOGI*)(tmp+4);
			//memcpy(mogi->offset,tmp+8,30*4);

		}
	}
	groups=vector<WMO*>();
	int counter=0;
	string tmp_path;
	WMO * wmo;
	while(true)
	{
		tmp_path=path;
		string sub_name=to_string(counter);
		tmp_path.erase(tmp_path.length()-4,4);
		while (sub_name.length()<3)
		{
			sub_name="0"+sub_name;
		}
		wmo =new WMO((tmp_path+"_"+sub_name+".wmo").c_str());
		if (wmo->exist)
		{
			groups.push_back(wmo);
			counter++;
			continue;
		}
		else
		{
			break;
		}

	}



}


RootWMO::~RootWMO(void)
{
}
