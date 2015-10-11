#include <string>
#include "Adt.h"
#include "FileParser.h"


using namespace std;
Adt::Adt(string path)
{
	root=0;
	root_length=0;
	obj=0;
	obj_length=0;
	tex=0;
	tex_length=0;
	char *tmp;
	root_length=FileParser::Parse(path+".adt",&root);
	obj_length=FileParser::Parse(path+"_obj0.adt",&obj);
	tex_length=FileParser::Parse(path+"_tex0.adt",&tex);
	wmo_infos=vector<WmoInfo>();
	m2_infos=vector<M2Info>();
	if (!root_length)
	{
		is_file_exists=false;
		return;
	}
	else
	{
		is_file_exists=true;
	}
	MCNK * mcnk=0;
	MWMO * mwmo=0;
	MWID * mwid=0;
	MMDX * mmdx=0;
	MMID * mmid=0;
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
				info.position.coords=m[i].position;
				info.position.rotation=m[i].rotation;
				info.id=m[i].uniqueId;
				info.name=mwmo->names+mwid->offsets[m[i].mwidEntry];
				wmo_infos.push_back(info);
			}
			delete [] m;
		}
		if (memcmp(tmp,"XDMM",4)==0)
		{

			mmdx=new MMDX;
			*mmdx=*(MMDX*)(tmp+4);
			mmdx->names=new char[mmdx->length];
			memcpy(mmdx->names,tmp+8,mmdx->length);

		}
		if (memcmp(tmp,"DIMM",4)==0)
		{

			mmid=new MMID;
			*mmid=*(MMID*)(tmp+4);
			mmid->offsets=new unsigned long[mmid->length/4];
			memcpy(mmid->offsets,tmp+8,mmid->length);

		}
		if (memcmp(tmp,"FDDM",4)==0)
		{
			unsigned long length=*(unsigned long *)(tmp+4);
			MDDF * m=new MDDF[length/sizeof(MDDF)];
			memcpy(m,tmp+8,length);
			for (unsigned i=0;i<length/sizeof(MDDF);i++)
			{
				M2Info info;
				m[i].position.x-=17066.6656;
				m[i].position.z-=17066.6656;
				info.position.coords=m[i].position;
				info.position.rotation=m[i].rotation;
				info.scale=(float)m[i].scale/1024;
				info.id=m[i].uniqueId;
				info.name=mmdx->names+mmid->offsets[m[i].mwidEntry];
				m2_infos.push_back(info);
			}
			delete [] m;
		}
	}
	delete [] mwmo->names;
	delete [] mwmo;
	delete [] mwid->offsets;
	delete [] mwid;
	delete [] mmdx->names;
	delete [] mmdx;
	delete [] mmid->offsets;
	delete [] mmid;
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
	delete [] root;
	delete [] obj;
	delete [] tex;

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