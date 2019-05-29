#include "pch.h"
#include "TestBenchCreator.h"


TestBenchCreator::TestBenchCreator()
{
}


TestBenchCreator::~TestBenchCreator()
{
}

std::shared_ptr<AbstractTestBench> TestBenchCreator::getTestBench(typeTestBench type)
{
	switch (type)
	{
	case TestBenchCreator::Abstract:
		return nullptr;
		break;
	case TestBenchCreator::EngineOverheating:
		//return std::shared_ptr<AbstractTestBench>(new EngineOverheatingTestBench);
		break;
	default:
		return nullptr;
		break;
	}
	return nullptr;
}
