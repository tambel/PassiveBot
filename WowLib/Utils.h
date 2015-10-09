#pragma once
namespace Utils
{
	namespace WowTypes
	{
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
		/*
		struct Vector3
		{
		float x;
		float y;
		float z;
		};
		*/
		struct Position
		{
			Vector3 coords;
			float rotation;
		};
	}
}