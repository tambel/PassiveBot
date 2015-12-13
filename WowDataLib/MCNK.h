#pragma once
struct MCNK_Header
{
	char unk1[4];//0
	unsigned int IndexX;
	unsigned int IndexY;
	unsigned nDoodadRefs;
	unsigned ofsHeight;
	unsigned ofsNormal;
	unsigned ofsLayer;
	unsigned ofsRefs;
	unsigned ofsAlpha;

	unsigned int u2;
	unsigned int u3;//10
	unsigned int u4;
	unsigned int u5;
	unsigned int u6;
	unsigned int u7;
	unsigned int u8;
	unsigned int u9;
	unsigned int u10;
	unsigned int u11;
	unsigned int u12;
	unsigned int u13;//20
	unsigned int u14;
	unsigned int u15;
	unsigned int u16;
	unsigned int u17;
	unsigned int u18;
	Vector3 position;//26
	unsigned int unk2[3];
};
struct MCVT
{
	float height[145];
};