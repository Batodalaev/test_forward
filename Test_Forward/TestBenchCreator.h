#pragma once
#include "AbstractTestBench.h"
#include "EngineOverheatingTestBench.h"
/*
����� - ������� �������� �������
������ �������� �����, ��� ����� ���������� ���� ��������, ������ ����������� AbstractTestBench
��� ������� - typeTest

���� ������:  ������������ �������� ������� ��������� ����.
*/
class TestBenchCreator
{
public:
	TestBenchCreator();
	~TestBenchCreator();

	enum typeTest { None, EngineOverheating };
	
	std::shared_ptr < AbstractTestBench> getTestBench(typeTest type);
};

