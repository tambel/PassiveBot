#pragma once
#include <string>
using  namespace std;
class FileParser
{

public:
	FileParser(void);
	~FileParser(void);
	static unsigned long Parse(string path, char ** buff);
	static bool FileExist(string path);

};

