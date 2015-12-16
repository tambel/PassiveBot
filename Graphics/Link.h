#pragma once
#include "WowDataLib\Utils.h"
using  namespace Utils::Graphics;
class Link
{
public:
	virtual ~Link(){}
	virtual Vertice * GetVertices()=0;
	virtual unsigned long GetVerticeCount()=0;
	virtual unsigned long * GetIndices()=0;
	virtual unsigned long GetIndexCount()=0;
};

