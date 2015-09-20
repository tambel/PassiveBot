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
		if (!bottom || refresh)
		{
			bottom=Process::ReadFloat(base+WowOffsets::FrameManager::FrameBottom);
		}
		return bottom;
	}
	float Frame::GetTop(bool refresh)
	{
		if (!top || refresh)
		{
			top=Process::ReadFloat(base+WowOffsets::FrameManager::FrameTop);
		}
		return top;
	}
	float Frame::GetLeft(bool refresh)
	{
		if (!left || refresh)
		{
			left=Process::ReadFloat(base+WowOffsets::FrameManager::FrameLeft);
		}
		return left;
	}
	float Frame::GetRight(bool refresh)
	{
		if (!right || refresh)
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

}