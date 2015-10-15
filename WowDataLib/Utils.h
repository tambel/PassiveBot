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
		template<class T>
		struct Point2D
		{
			T X;
			T Y;
			Point2D():X(0),Y(0){}
			Point2D(T x,T y):X(x),Y(y){}
			bool operator==(const Point2D & right)
			{
				return (this->X==right.X && this->Y==right.Y);
			}
			Point2D operator -(const Point2D & right)
			{
				return Point2D(this->X-right.X,this->Y-right.Y);
			}
		};
		/*
		struct Point2DI
		{
			int X;
			int Y;
		};
		*/
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