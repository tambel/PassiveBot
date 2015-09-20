#include "Player.h"
#include "MemLib.h"
#include "offsets.h"
using namespace ProcessLib;
namespace Wow
{
	Player::Player(unsigned base):Unit(base)
	{
	}


	Player::~Player(void)
	{
	}
	wchar_t * Player::GetName(bool refresh)
	{
		if (!name || refresh)
		{
			Guid128 tmp_guid=Guid128();
			unsigned current=Process::ReadRelUInt(WowOffsets::Player::PlayerNameCache);
			Process::ReadRaw(current+WowOffsets::PlayerNameCacheGuid,&tmp_guid,16);
			name=Process::ReadString_UTF8(current+WowOffsets::PlayerNameCacheName,0);
			while(*GetGuid()!=tmp_guid)
			{
				current=Process::ReadUInt(current+WowOffsets::Player::PlayerNameCacheNext);
				Process::ReadRaw(current+WowOffsets::PlayerNameCacheGuid,&tmp_guid,16);
				name=Process::ReadString_UTF8(Process::ReadUInt(current+WowOffsets::PlayerNameCacheName),0);
			}
			name=Process::ReadString_UTF8(current+WowOffsets::PlayerNameCacheName,0);

		}
		return name;
	}
}