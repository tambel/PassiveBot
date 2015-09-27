#include "GameManager.h"
#include "MemLib.h"
#include "offsets.h"
#include <d3d11.h>
#include <d3dx11.h>
#include <DirectXMath.h>
using namespace DirectX;
using namespace ProcessLib;
namespace Wow
{
	GameManager::GameManager(void)
	{
	}


	GameManager::~GameManager(void)
	{
	}
	Camera * GameManager::GetCamera()
	{
		return new Camera(Process::ReadUInt(Process::ReadRelUInt(WowOffsets::Camera::CameraPointer)+WowOffsets::Camera::CameraOffset));
	}
	bool GameManager::WorldToScreen(Position pos)
	{
		Camera * cam=GameManager::GetCamera();
		Rect size=Process::GetClientSize();
		FXMVECTOR vEye=XMVectorSet( cam->GetPosition(true).coords.x, cam->GetPosition(true).coords.y, cam->GetPosition(true).coords.z, 0.0f );
		FXMVECTOR vLookat=vEye+XMVectorSet(cam->GetMatrix(true)[0],cam->GetMatrix(true)[1],cam->GetMatrix(true)[2],0.0f);
		FXMVECTOR vUpVec =XMVectorSet(0.0f,0.0f,1.0f,0.0f);

		XMMATRIX proj= XMMatrixPerspectiveFovRH(cam->GetFOV(true),size.width/size.heigth,cam->GetNearClip(true),cam->GetFarClip(true));
		XMMATRIX view= XMMatrixLookAtRH(vEye,vLookat,vUpVec);
		XMMATRIX world=XMMatrixIdentity();
		FXMVECTOR v=XMVectorSet(3.0f,5.0f,8.0f,77.0f);
		FXMVECTOR objPos=XMVectorSet(pos.coords.x,pos.coords.y,pos.coords.z,0.0f);
		FXMVECTOR result=XMVector3Project(objPos,0,0,size.width,size.heigth,0.0f,1.0f,proj,view,world);
		Process::MoveMouse(result.m128_f32[0]*(65536/GetSystemMetrics(SM_CXSCREEN)),result.m128_f32[1]*(65536/GetSystemMetrics(SM_CYSCREEN)));
		return 0;
	}
}
