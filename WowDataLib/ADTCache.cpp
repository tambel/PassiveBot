#include "ADTCache.h"
/*
vector<ADT*> ADTCache::adt_list=vector<ADT*>();
unsigned long ADTCache::size_limit=100;

void ADTCache::Add(ADT * adt)
{
	if (Find(adt)) return;
	if (std::find(adt_list.begin(), adt_list.end(), adt) != adt_list.end())
	{
		return;
	}
	if (adt_list.size()>=size_limit)
	{
		delete adt_list[0];
		adt_list.erase(adt_list.begin());
		adt_list.push_back(adt);
		
	}
	else
	{
		adt_list.push_back(adt);
	}
}
ADT * ADTCache::Find(string location, Point2D<int> coordinates)
{
	for (auto adt:adt_list)
	{
		if (adt->GetLocation()==location && adt->GetCoordinates()==coordinates)
		{
			return adt;
		}
	}
	return 0;
}
*/

ADT * ADTCache::Find(Location * location, Point2D<int> coordinates)
{
	
	for (auto adt:item_list)
	{
		if (adt->GetLocation()->id==location->id && adt->GetCoordinates()==coordinates)
		{
			return adt;
		}
	}
	return 0;
}