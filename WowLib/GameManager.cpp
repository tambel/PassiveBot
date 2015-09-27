#include "GameManager.h"
#include "MemLib.h"
#include "offsets.h"
#include <d3d11.h>
#include <d3dx11.h>
#include <DirectXMath.h>
#include <math.h>
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
		float * matr=cam->GetMatrix(true);
		size.width=GetSystemMetrics(SM_CXSCREEN);
		size.heigth=GetSystemMetrics(SM_CYSCREEN);
		/*
		size.width=GetSystemMetrics(SM_CXSCREEN);
		size.heigth=GetSystemMetrics(SM_CYSCREEN);
		

		FXMVECTOR returnVector = XMVectorZero();
		unsigned X;
		unsigned Y;
		float w = matr[6] * pos.coords.x + matr[7] * pos.coords.y + matr[8] * pos.coords.z + 0;
		if (w >= 0.01f)
		{
			float inverseX = 1.0f / w;
			X =
				(size.width / 2.0f) +
				(0.5f * (
				(matr[0] * pos.coords.x + matr[1] * pos.coords.y + matr[2] * pos.coords.z + 0)
				* inverseX)
				* size.width + 0.5f);
			Y =
				(size.heigth / 2.0f) -
				(0.5f * (
				(matr[3] * pos.coords.x + matr[4] * pos.coords.y + matr[5] * pos.coords.z + 0)
				* inverseX)
				* size.heigth + 0.5f);
		}
		Process::MoveMouse(X*((float)65536/GetSystemMetrics(SM_CXSCREEN)),Y*((float)65536*(size.width/size.heigth)/GetSystemMetrics(SM_CYSCREEN)));
		*/
		
		
		FXMVECTOR vEye=XMVectorSet( cam->GetPosition(true).coords.x, cam->GetPosition(true).coords.y, cam->GetPosition(true).coords.z, 0.0f );
		FXMVECTOR vLookat=vEye+XMVectorSet(matr[0],matr[1],matr[2],0.0f);
		FXMVECTOR vUpVec =XMVectorSet(0.0f,0.0f,1.0f,0.0f);

		XMMATRIX proj= XMMatrixPerspectiveFovRH(cam->GetFOV(true)* 0.94f,size.width/size.heigth,cam->GetNearClip(true),cam->GetFarClip(true));
		XMMATRIX view= XMMatrixLookAtRH(vEye,vLookat,vUpVec);
		XMMATRIX world=XMMatrixIdentity();
		FXMVECTOR objPos=XMVectorSet(pos.coords.x,pos.coords.y,pos.coords.z,0.0f);
		FXMVECTOR result=XMVector3Project(objPos,0,0,size.width,size.heigth,cam->GetNearClip(true),cam->GetFarClip(true),proj,view,world);
		int h=GetSystemMetrics(SM_CYSCREEN);
		Process::MoveMouse(result.m128_f32[0]*((float)65536/GetSystemMetrics(SM_CXSCREEN)),result.m128_f32[1]*((float)65536/GetSystemMetrics(SM_CYSCREEN)));
		
		/*
		FXMVECTOR pseudoVec = XMVectorSet(pos.coords.x, pos.coords.y, pos.coords.z,0.0f);
		FXMVECTOR Pos=XMVectorSet( cam->GetPosition(true).coords.x, cam->GetPosition(true).coords.y, cam->GetPosition(true).coords.z, 0.0f );
		FXMVECTOR diff = pseudoVec - Pos;
		float * matr=cam->GetMatrix(true);
		XMMATRIX matrix= XMMATRIX(matr[0],matr[1],matr[2],0.0f,matr[3],matr[4],matr[5],0.0f,matr[6],matr[7],matr[8],0.0f,0.0f,0.0f,0.0f,1.0f);
		FXMVECTOR view = XMVector3Transform(diff , XMMatrixInverse(0,matrix));
		FXMVECTOR camm = XMVectorSet(-view.m128_f32[1], -view.m128_f32[2], view.m128_f32[0],0.0f);

		float WowWidth = (float)((unsigned)size.width);
		float WowHeight = (float)((unsigned)size.heigth);
		float fHorizontalAdjust = ((WowWidth / WowHeight >= 1.6f) ? 55.0f : 44.0f);


		float fScreenX = WowWidth / 2.0f;
		float fScreenY = WowHeight / 2.0f;
		RECT rect;
		GetClientRect(Process::GetWindow(),&rect);
		float modifier = 1.0f;
		float modifier2 = 1.08f;
		if (1.0 * rect.right / rect.bottom > 1.5)
		{
		modifier *= 1.15f;
		modifier2 = 1.0f;
		}
		float Deg2Rad = (float)XM_PI / 180;
		float fTmpX = fScreenX / (float)tan((((WowWidth / WowHeight) * fHorizontalAdjust) * modifier2 * modifier / 2.0f) * Deg2Rad);
		float fTmpY = fScreenY / (float)tan((((WowWidth / WowHeight) * 35) / 2.0f) * Deg2Rad);

		float X = (int)(fScreenX + camm.m128_f32[0] * fTmpX / camm.m128_f32[2]);
		float Y = (int)(fScreenY + camm.m128_f32[1] * fTmpY / camm.m128_f32[2]);
		if (X < 0 || Y < 0)
		{
		X = 0;
		Y = 0;
		}
		else
		{
		if (1)
		{

		unsigned xx;
		unsigned yy;
		POINT p={0};
		ScreenToClient(Process::GetWindow(), &p);
		int err=GetLastError();
		X += abs(p.x);
		Y += abs(p.y);

		}
		Y -= 20;
		}
		Process::MoveMouse(X*((float)65536/GetSystemMetrics(SM_CXSCREEN)),Y*((float)65536/GetSystemMetrics(SM_CYSCREEN)));
		*/
		return 0;
	}
}
