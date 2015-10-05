#include "FileParser.h"
//#include <iostream>
#include<fstream>


FileParser::FileParser(void)
{
}


FileParser::~FileParser(void)
{
}
unsigned long FileParser::Parse(string path, char ** buff)
{
	ifstream file(path, ios::binary | ios::ate);
	if (file) {
		// get length of file:
		file.seekg (0, file.end);
		unsigned long  length = file.tellg();
		file.seekg (0, file.beg);
		*buff = new char [length];
		file.read (*buff,length);

		return length;
	}
	return 0;
}
bool FileParser::FileExist(string path)
{
	ifstream file(path, ios::binary | ios::ate);
	if (file) 
	{
		file.close();
		return true;
	}
	else
	{
		file.close();
		return false;
	}

}