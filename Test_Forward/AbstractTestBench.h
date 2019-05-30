#pragma once

#include "EngineInterface.h"
/*
Класс - абстрактный класс тестового стенда

Цель класса: Использование TestBenchCreator-ом в качестве базового класса производимых стендов.
*/
class AbstractTestBench
{
public:
	virtual ~AbstractTestBench();

	void setEngineInterface(std::shared_ptr<EngineInterface>& ptr);
	std::shared_ptr<EngineInterface>& getEngineInterface();

	virtual void runEngine() = 0;
	virtual std::string getResult() = 0;

protected:
	std::shared_ptr<EngineInterface> ptr;
};

