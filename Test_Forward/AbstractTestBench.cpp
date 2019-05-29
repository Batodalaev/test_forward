#include "pch.h"
#include "AbstractTestBench.h"

AbstractTestBench::~AbstractTestBench()
{
}

void AbstractTestBench::setEngineInterface(std::shared_ptr<EngineInterface>& ptr)
{
	this->ptr = ptr;
}

std::shared_ptr<EngineInterface>& AbstractTestBench::getEngineInterface()
{
	return ptr;
}
