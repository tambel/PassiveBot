#pragma once
#include <fstream>
#include <string>
using namespace std;
class BinaryReader
{
	ifstream * stream;
public:
	BinaryReader(ifstream * stream);
	BinaryReader(string path);
	~BinaryReader(void);
	//Data reading
	unsigned int ReadUInt();
	unsigned int ReadUInt(unsigned long abs_position);
	void ReadBytes(char * buff,unsigned long abs_position,unsigned long length);
	//
	void MoveToBegining();
	void MoveForward(unsigned long offset);
	void MoveBackward(unsigned long offset);
	unsigned long GetPosition();
	ifstream * GetStream();
};

