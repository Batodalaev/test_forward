#pragma once
#include "AbstractTestBench.h"
#include "EngineOverheatingTestBench.h"
/*
 ласс - фабрика тестовых стендов
 аждый тестовый стенд, что будет произведен этой фабрикой, должен наследовать AbstractTestBench
“ип стендов - typeTest

÷ель класса:  производство тестовых стендов заданного типа.
*/
class TestBenchCreator
{
public:
	TestBenchCreator();
	~TestBenchCreator();

	enum typeTest { None, EngineOverheating };
	
	std::shared_ptr < AbstractTestBench> getTestBench(typeTest type);
};

