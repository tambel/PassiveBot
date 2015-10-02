#pragma once
struct Point2D
{
	unsigned X;
	unsigned Y;
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
struct Vector3
{
	float x;
	float y;
	float z;
	Vector3()
	{
		x=0;
		y=0;
		z=0;
	}
	Vector3(float x,float y,float z):x(x),y(y),z(z){}

};
struct Vertice
{
	Vector3 position;
	Color color;
	Vertice(){};
	Vertice(Vector3 pos,Color color): position(pos), color(color){}
};