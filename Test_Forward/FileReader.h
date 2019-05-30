#pragma once

#include<iostream>
#include<sstream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>

#include "SimpleICEngine.h"

/*
����� - ����������� ������, ��������� ����� �������� �������� � ����������.

���� ������:  ������������� �������������� ��������� � �������
*/
class FileReader
{
public:
	FileReader(std::string filename);
	~FileReader();

	bool isOpen();

	template<class T>
	T read(std::string nameValue);
	template<>
	std::vector<int> read<std::vector<int>>(std::string nameValue);

	void fillSimpleICEngine(std::shared_ptr<EngineInterface>& engine);
private:
	std::ifstream fin;
	//https://stackoverflow.com/questions/8116808/read-integers-from-a-text-file-with-c-ifstream
	template <class T> inline T & stay(T && t) { return t; }
	
};

template<class T>
inline T FileReader::read(std::string nameValue)
{
	if (!isOpen())
		throw std::exception("���� �� ������");
	std::string name;
	fin >> name;
	if(name!=nameValue)
		throw std::exception("��� ���������� �� ��������");

	T value;
	fin >> value;
	return value;
}

template<>
inline std::vector<int> FileReader::read(std::string nameValue)
{
	if (!isOpen())
		throw std::exception("���� �� ������");
	std::string name;
	fin >> name;
	if (name != nameValue)
		throw std::exception("��� ���������� �� ��������");

	std::string line;
	std::getline(fin,line);
	return std::vector<int>(std::istream_iterator<int>(stay(std::istringstream(line))),
		std::istream_iterator<int>());
}
