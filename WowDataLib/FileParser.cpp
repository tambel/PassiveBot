#include "FileParser.h"
//#include <iostream>
#include<fstream>
#include <string>
using  namespace std;

FileParser::FileParser(void)
{
}


FileParser::~FileParser(void)
{
}
unsigned long FileParser::Parse(const char * path, char ** buff)
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