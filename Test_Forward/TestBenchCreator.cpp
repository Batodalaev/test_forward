#include "pch.h"
#include "TestBenchCreator.h"


TestBenchCreator::TestBenchCreator()
{
}

TestBenchCreator::~TestBenchCreator()
{
}

std::shared_ptr<AbstractTestBench> TestBenchCreator::getTestBench(typeTest type)
{
	switch (type)
	{
	case TestBenchCreator::None:
		return nullptr;
		break;
	case TestBenchCreator::EngineOverheating:
		return std::shared_ptr<AbstractTestBench>(new EngineOverheatingTestBench);
		break;
	default:
		return nullptr;
		break;
	}
	return nullptr;
}
