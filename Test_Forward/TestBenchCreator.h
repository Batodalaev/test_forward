#pragma once
#include "AbstractTestBench.h"
#include "EngineOverheatingTestBench.h"
class TestBenchCreator
{
public:
	TestBenchCreator();
	~TestBenchCreator();

	enum typeTestBench { None, EngineOverheating };
	
	std::shared_ptr < AbstractTestBench> getTestBench(typeTestBench type);
};

