#pragma once
class FileParser
{

public:
	FileParser(void);
	~FileParser(void);
	static unsigned long Parse(const char * path, char ** buff);

};

