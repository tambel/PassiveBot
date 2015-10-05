#include <string>
#include "Adt.h"
#include "FileParser.h"


using namespace std;
Adt::Adt(string path)
{

	char * root=0;
	unsigned long root_length;
	char *obj=0;
	unsigned long obj_length;
	char * tex=0;
	unsigned long tex_length;
	char *tmp;
	root_length=FileParser::Parse((path+".adt").c_str(),&root);
	obj_length=FileParser::Parse((path+"_obj0.adt").c_str(),&obj);
	tex_length=FileParser::Parse((path+"_tex0.adt").c_str(),&tex);
	if (!root_length)
	{
		is_file_exists=false;
		return;
	}
	else
	{
		is_file_exists=true;
	}
	MCNK * mcnk;
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
	}
	for (unsigned long i=0;i<obj_length;i++)
	{
		tmp=obj+i;
		if (memcmp(tmp,"OMWM",4)==0)
		{
			mwmo=new MWMO;
			*mwmo=*(MWMO*)(tmp+4);
			mwmo->names=new char[mwmo->length];
			memcpy(mwmo->names,tmp+8,mwmo->length);
		}
		if (memcmp(tmp,"DIWM",4)==0)
		{
			mwid=new MWID;
			*mwid=*(MWID*)(tmp+4);
			mwid->offsets=new unsigned long[mwid->length/4];
			memcpy(mwid->offsets,tmp+8,mwid->length);
		}
		if (memcmp(tmp,"FDOM",4)==0)
		{
			unsigned long length=*(unsigned long *)(tmp+4);
			MODF * m=new MODF[length/sizeof(MODF)];
			memcpy(m,tmp+8,length);
			for (unsigned i=0;i<length/sizeof(MODF);i++)
			{
				WmoInfo info;
				m[i].position.x-=17066.6656;
				m[i].position.z-=17066.6656;
				info.position=m[i].position;
				info.rotation=m[i].rotation;
				info.id=m[i].uniqueId;
				info.name=mwmo->names+mwid->offsets[m[i].mwidEntry];
				wmo_infos.push_back(info);
			}
	
			
		}
	}
	if (mwmo && mwid)
	{
		for (int i=0;i<mwid->length/4;i++)
		{
			//WmoInfo info;
			//info.name=mwmo->names+mwid->offsets[i];
			//info.position=modf
			//wmo_infos.push_back(mwmo->names+mwid->offsets[i]);

		}
	}
	

}
bool Adt::IsExist()
{
	return is_file_exists;
}

Adt::~Adt(void)
{
	delete [] mwmo->names;
	delete [] mwmo;
	delete [] mwid->offsets;
	delete [] mwid;
	for (auto mcnk:mcnk_list)
	{
		delete mcnk;
	}
	mcnk_list.clear();
}
unsigned Adt::GetVersion()
{
	return mver.version;
}