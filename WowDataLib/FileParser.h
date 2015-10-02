#pragma once
class FileParser
{

public:
	FileParser(void);
	~FileParser(void);
	static unsigned long Parse(const wchar_t * path, char ** buff);

};

