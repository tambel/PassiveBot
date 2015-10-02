#include <string>
#include "Adt.h"
#include "FileParser.h"

using namespace std;
float f[313480/4];
Adt::Adt(wstring path)
{
	char * root;
	unsigned long root_length;
	char *obj;
	unsigned long obj_length;
	char * tex;
	unsigned long tex_length;
	char *tmp;
	root_length=FileParser::Parse((path+L".adt").c_str(),&root);
	obj_length=FileParser::Parse((path+L"_obj0.adt").c_str(),&obj);
	tex_length=FileParser::Parse((path+L"_tex0.adt").c_str(),&tex);
	if (!root_length)
	{
		is_file_exists=false;
	}
	else
	{
		is_file_exists=true;
	}
	//root_length=FileParser::Parse(L"C:\\Users\\laptop\\Desktop\\Extracted\\World\\Maps\\Kalimdor\\Kalimdor_34_50.adt",&root);
	//obj_length=FileParser::Parse(L"C:\\Users\\laptop\\Desktop\\Extracted\\World\\Maps\\Kalimdor\\Kalimdor_19_13_obj0.adt",&obj);
	//tex_length=FileParser::Parse(L"C:\\Users\\laptop\\Desktop\\Extracted\\World\\Maps\\Kalimdor\\Kalimdor_0_0.adt",&tex);
	MCNK * mcnk;
	mcvt_list=vector<MCVT>(); 
	for (unsigned long i=0;i<root_length;i++)
	{
		tmp=root+i;
		if (memcmp(tmp,"REVM",4)==0)
		{
			mver=*(MVER*)(tmp+8);
		}
		if (memcmp(tmp,"KNCM",4)==0)
		{
			mcnk=new MCNK;
			*mcnk=*(MCNK*)(tmp+4);
			mcnk->position=*(Vector3*)(tmp+0x70);
			mcnk->mcvt=*(MCVT*)(tmp+0x90);
			mcnk->coords.Y=*(unsigned*)(tmp+0xC);
			mcnk->coords.X=*(unsigned*)(tmp+0x10);
			mcnk_list.push_back(mcnk);
		}
		/*
		if (memcmp(tmp,"TVCM",4)==0)
		{
			mcvt=*(MCVT*)(tmp+8);
			mcvt_list.push_back(mcvt);
		}*/
	}
	

}
bool Adt::IsExist()
{
	return is_file_exists;
}

Adt::~Adt(void)
{
}
unsigned Adt::GetVersion()
{
	return mver.version;
}