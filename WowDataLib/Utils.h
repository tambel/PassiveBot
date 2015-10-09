#pragma once
#include "WowLib\Utils.h"
using namespace Utils::WowTypes;
namespace Utils
{
	namespace Graphics
	{
		struct Triangle
		{
			unsigned short indices[3];
		};
		struct Point2D
		{
			float X;
			float Y;
		};
		struct Color
		{
			float r;
			float g;
			float b;
			float a;
			Color(){};
			Color(float r,float g, float b, float a) :r(r),a(a),g(g),b(b){}
		};

		struct Vertice
		{
			Vector3 position;
			Color color;
			Vertice(){};
			Vertice(Vector3 pos,Color color): position(pos), color(color){}
		};
	}
}