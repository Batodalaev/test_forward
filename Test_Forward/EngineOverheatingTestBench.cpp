#include "pch.h"
#include "EngineOverheatingTestBench.h"


EngineOverheatingTestBench::EngineOverheatingTestBench()
{
}


EngineOverheatingTestBench::~EngineOverheatingTestBench()
{
}

std::shared_ptr<EngineOverheatingTest> EngineOverheatingTestBench::getEngineOverheatingTest()
{
	return std::dynamic_pointer_cast<EngineOverheatingTest>(ptr);
}

void EngineOverheatingTestBench::runEngine()
{
	std::shared_ptr<EngineOverheatingTest> ptr = getEngineOverheatingTest();

	ptr->start();
	while (!ptr->isOverheated())
		ptr->updatePerSecond();

}

std::string EngineOverheatingTestBench::getResult()
{
	return "Simulation time: "+std::to_string(getEngineOverheatingTest()->getSimulationTimeinSeconds()) + " seconds.";
}

void EngineOverheatingTestBench::setToutside(int Toutside)
{
	getEngineOverheatingTest()->setToutside(Toutside);
}

int EngineOverheatingTestBench::getToutside()
{
	return getEngineOverheatingTest()->getToutside();
}
