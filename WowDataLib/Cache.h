#pragma once
#include <vector>
using namespace std; 



template<class T>
class Cache
{
protected:
	static vector<T*> item_list;
	static unsigned long list_size_limit;
public:
	static void Add(T * t)
	{
		if (Find(t)) return;
		if (std::find(item_list.begin(), item_list.end(), t) != item_list.end())
		{
			return;
		}
		if (item_list.size()>=list_size_limit)
		{
			delete item_list[0];
			item_list.erase(item_list.begin());
			item_list.push_back(t);

		}
		else
		{
			item_list.push_back(t);
		}
	}
	static T * Find(T* t)
	{
		for (auto item:item_list)
		{
			if (*t==*item)
			{
				return item;
			}
		}
		return 0;
	}

};

template <class T>
vector<T*> Cache<T>::item_list=vector<T*>();
template <class T>
unsigned long Cache<T>::list_size_limit=100;
