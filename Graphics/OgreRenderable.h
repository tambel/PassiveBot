#pragma once
class OgreRenderable 
{
protected:
	static unsigned long current_uid;
		unsigned long uid;
public:
	static unsigned long GetUIDAndIncrement();
	static void ClearCouner();
};

