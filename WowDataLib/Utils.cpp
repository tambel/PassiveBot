#include "Utils.h"
namespace Utils
{
	Point2D<int> WorldPositionToMapBlockCoords(Vector3 position)
	{
		return Point2D<int>(floor((32 - (position.x / (Metrics::BlockSize)))),floor((32 - (position.y / (Metrics::BlockSize)))));
	}
	namespace Game
	{
		vector<Location*> LocationBase::locations=vector<Location*>();
		bool LocationBase::initialized=false;
		void LocationBase::Add(Location * loc)
		{
			locations.push_back(loc);
		}
		void LocationBase::Clear()
		{
			for (auto loc:locations)
			{
				delete loc;
			}
			locations.clear();
		}
		void LocationBase::Init()
		{
			locations.push_back(new Location("Kalimdor",1));
			initialized=true;
		}
		bool LocationBase::IsInitialized()
		{
			return initialized;
		}
		Location * LocationBase::Get(string name)
		{
			for (auto loc:locations)
			{
				if (loc->name==name)
				{
					return loc;
				}
			}
			return 0;
		}
		Location * LocationBase::Get(unsigned id)
		{
			for (auto loc:locations)
			{
				if (loc->id==id)
				{
					return loc;
				}
			}
			return 0;
		}

	}
}