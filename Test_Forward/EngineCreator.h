#pragma once
#include "SimpleICEngine.h"
/*
����� - �������, �� �������� ����������.
������ ���������, ��� ����� ���������� ���� Creator-��, ������ ����������� EngineInterface.
��� ���������� - typeEngine

���� ������: ������������ ������� ���������� ��������� ����.
*/
class EngineCreator
{
public:
	EngineCreator();
	~EngineCreator();
	
	enum typeEngine :int { None, SimpleICE };

	std::shared_ptr<EngineInterface> getEngineInterface(typeEngine type);

};

