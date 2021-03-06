#include "Camera.h"
#include "MemLib.h"
#include "offsets.h"
using namespace ProcessLib; 
namespace Wow
{
	Camera::Camera(unsigned base)
	{
		this->base=base;
		matrix=new float[9];
	}


	Camera::~Camera(void)
	{
		delete [] matrix;
		matrix=0;
	}
	unsigned Camera::GetBase()
	{
		return base;
	}
	Position Camera::GetPosition(bool refresh)
	{
		if (refresh)
		{
			Process::ReadRaw(base+WowOffsets::Camera::CameraPosition,&position.coords,16);
		}
		return position;
	}
	float * Camera::GetMatrix(bool refresh)
	{
		if (refresh)
		{
			Process::ReadRaw(base+WowOffsets::Camera::CameraMatrix,matrix,36);
		}
		return matrix;
	}
	float Camera::GetFOV(bool refresh)
	{
		if (refresh)
		{
			FOV=Process::ReadFloat(base+WowOffsets::Camera::CameraFOV);
		}
		return FOV;
	}
	float Camera::GetNearClip(bool refresh)
	{
		if (refresh)
		{
			near_clip=Process::ReadRelFloat(WowOffsets::Camera::NearClip);
		}
		return near_clip;
	}
	float Camera::GetFarClip(bool refresh)
	{
		if (refresh)
		{
			far_clip=Process::ReadRelFloat(WowOffsets::Camera::FarClip);
		}
		return far_clip;
	}
	float Camera::GetAspect(bool refresh)
	{
		if (refresh)
		{
			aspect=Process::ReadRelFloat(WowOffsets::Camera::FarClip);
		}
		return far_clip;
	}
}
