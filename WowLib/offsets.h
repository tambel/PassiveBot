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
		NamePtr=0x274,
		NameOffset=0xB4
	};
	enum Item
	{
		CachePtr=0xD701D0,
		CacheOffset=0x4C,
		RowOffset=0x1D8,
		Nameoffset=0x198
	};
}