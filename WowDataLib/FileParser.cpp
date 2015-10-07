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
	unsigned long  length=0;
	ifstream file(path, ios::binary | ios::ate);
	if (file) {
		// get length of file:
		file.seekg (0, file.end);
		length = file.tellg();
		file.seekg (0, file.beg);
		*buff = new char [length];
		file.read (*buff,length);
	}
	return length;
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