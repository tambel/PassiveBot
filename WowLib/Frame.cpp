#include "Frame.h"
#include "MemLib.h"
#include "offsets.h"
#include "FrameManager.h"
using namespace ProcessLib;
namespace Wow
{
	Frame::Frame(unsigned base)
	{
		this->base=base;
		parent=0;
		name=0;
		bottom=-0xFFFF;
		top=-0xFFFF;
		left=-0xFFFF;
		right=-0xFFFF;
	}


	Frame::~Frame(void)
	{
		if (name)
		{
			delete name;
		}
	}
	char * Frame::GetName(bool refresh)
	{
		if (!name || refresh)
		{
			name?name:delete name;
			name=Process::ReadASCII(Process::ReadUInt(base+WowOffsets::FrameManager::Name),0);
		}
		if (name)
		{
			return name;
		}
		else
		{
			return "NONE";
		}
	}
	unsigned Frame::GetBase()
	{
		return base;
	}
	void  Frame::SetParent(Frame * parent)
	{
		this->parent=parent;
	}
	float Frame::GetBottom(bool refresh)
	{
		if (bottom==-0xFFFF || refresh)
		{
			bottom=Process::ReadFloat(base+WowOffsets::FrameManager::FrameBottom);
		}
		return bottom;
	}
	float Frame::GetTop(bool refresh)
	{
		if (top==-0xFFFF || refresh)
		{
			top=Process::ReadFloat(base+WowOffsets::FrameManager::FrameTop);
		}
		return top;
	}
	float Frame::GetLeft(bool refresh)
	{
		if (left==-0xFFFF || refresh)
		{
			left=Process::ReadFloat(base+WowOffsets::FrameManager::FrameLeft);
		}
		return left;
	}
	float Frame::GetRight(bool refresh)
	{
		if (right==-0xFFFF || refresh)
		{
			right=Process::ReadFloat(base+WowOffsets::FrameManager::FrameRight);
		}
		return right;
	}
	Frame * Frame::GetParent()
	{
		if (!parent)
		{
			unsigned parent_ptr=Process::ReadUInt(base+WowOffsets::FrameManager::ParentFrame);
			parent= FrameManager::FindFrameByAddress(parent_ptr);
		}
		return parent;
	}
	void Frame::MoveMoseToFrame()
	{
		int sw=65536;
		int sh= 65536;
		float b=GetBottom()*sh/FrameManager::GetScreenHeigth();
		float t=GetTop()*sh/FrameManager::GetScreenHeigth();
		float l=GetLeft()*sw/FrameManager::GetScreenWidth();
		float r=GetRight()*sw/FrameManager::GetScreenWidth();
		float w=r-l;
		float h=t-b;
		float x=l+w/2;
		float y=sh-t+h/2;
		//cout<<"bottom "<<b<<endl<<"top "<<t<<endl<<"left "<<l<<endl<<"right"<<r<<endl;
		//cout<<"x "<<x<<endl<<"y "<<y<<endl;
		Process::MoveMouse((unsigned)x,(unsigned)y);
	}
	bool Frame::IsVisible()
	{
		char result;
		result= Process::ReadByte(base+WowOffsets::FrameManager::Visible);
		if (result==1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}