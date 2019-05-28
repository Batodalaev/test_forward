#pragma once



#include<iostream>
#include<sstream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>



/*
Класс - просмотрщик файлов, прослойка между файловой системой и программой.

Цель класса:  централизация взаимодействия программы с файлами
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
private:
	std::ifstream fin;
	//https://stackoverflow.com/questions/8116808/read-integers-from-a-text-file-with-c-ifstream
	template <class T> inline T & stay(T && t) { return t; }
	
};

template<class T>
inline T FileReader::read(std::string nameValue)
{
	if (!isOpen())
		throw std::exception("Файл не открыт");
	std::string name;
	fin >> name;
	if(name!=nameValue)
		throw std::exception("Имя переменной не сходится");

	T value;
	fin >> value;
	return value;
}

template<>
inline std::vector<int> FileReader::read(std::string nameValue)
{
	if (!isOpen())
		throw std::exception("Файл не открыт");
	std::string name;
	fin >> name;
	if (name != nameValue)
		throw std::exception("Имя переменной не сходится");

	std::string line;
	std::getline(fin,line);
	return std::vector<int>(std::istream_iterator<int>(stay(std::istringstream(line))),
		std::istream_iterator<int>());

	/*int buf;//incorrect probably
	while (fin >> buf) {
		value.push_back(buf);
	}*/
	/*std::istringstream ss(line);
	std::istream_iterator<int> begin(ss), end;
	std::vector<int> value(begin, end);
	return value;
	*/
}
