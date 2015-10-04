#pragma once
struct Point2D
{
	int X;
	int Y;
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
	Vector3 operator+(const Vector3 &right)
	{
		return Vector3(this->x+ right.x,this->y+right.y,this->z+right.z);
	}

};
struct Vertice
{
	Vector3 position;
	Color color;
	Vertice(){};
	Vertice(Vector3 pos,Color color): position(pos), color(color){}
};