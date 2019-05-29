#pragma once

#include "EngineInterface.h"
class AbstractTestBench
{
public:
	virtual ~AbstractTestBench();

	void setEngineInterface(std::shared_ptr<EngineInterface>& ptr);
	std::shared_ptr<EngineInterface>& getEngineInterface();

	virtual void runEngine() = 0;
	virtual std::string getResult() = 0;

private:
	std::shared_ptr<EngineInterface> ptr;
};

