namespace WowOffsets
{
	enum ObjectManager
	{
		ObjectPanagerPtr=0xFF0248,
		ObjectManagerOffset=0x62C,
		FirstObject=0xD8,
		NextObject=0x3C


	};
	enum Object
	{
		Type=0xC,
		Descriptors=0x4,
		GUID=0x0,
		EntityID=0x24

	};
	enum GameObject
	{
		GameObjectNameCache=0x274,
		GameObjectNameOffset=0xB4
	};
	enum Item
	{
		CachePtr=0xD701D0,
		ItemNameoffset=0x198
	};
	enum Unit
	{
		UnitNameCache	= 0xC38,
		UnitNameOffset	= 0x7C
	};
	enum Player
	{
		PlayerNameCache=0xD7BF14,
		PlayerNameCacheNext	= 0x00,
		PlayerNameCacheGuid	= 0x10,
		PlayerNameCacheName	= 0x21,
		PlayerNameCacheRace	= 0x70,
		PlayerNameCacheClass= 0x78
	};
}