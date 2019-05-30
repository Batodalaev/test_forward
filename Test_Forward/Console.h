#pragma once

#include <iostream>
#include <string>
/*
����� - �������, ��������� ����� ���������� ������-������� � ����� ���������.

���� ������:  ������������� �������������� ������������ � ����������
*/
class Console
{
public:
	Console();
	~Console();

	template<class T>
	T& read();
	template<class T>
	void write(T& data);
	template<class T>
	void writeln(T& data);
	void writeln();

	void clear();
	void pause();
private:
	std::istream* in = nullptr;;
	std::ostream* out = nullptr;;
};

template<class T>
inline T & Console::read()
{
	T buf;
	*in >> buf;
	in->clear();
	in->ignore(10000, '\n');

	return buf;
}

template<class T>
inline void Console::write(T & data)
{
	*out << data;
}

template<class T>
inline void Console::writeln(T & data)
{
	*out << data << std::endl;
}
