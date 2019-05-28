#include "pch.h"
#include "FileReader.h"

FileReader::FileReader(std::string filename)
{
	fin.open(filename);
}

FileReader::~FileReader()
{
	fin.close();
}

bool FileReader::isOpen()
{
	return fin.is_open();
}
