#pragma once
#include <string>

#include "AbstractTestBench.h"
#include "EngineOverheatingTest.h"

/*
Класс - тестовый стенд на перегрве
Тип теста: Замер времени работы двигателя на холостом ходе до перегрева 
	при требуемой температуре окружающей среды.

Цель класса: Тестирование двигателя, который наследует EngineOverheatingTest.
*/
class EngineOverheatingTestBench:public AbstractTestBench
{
public:
	EngineOverheatingTestBench();
	~EngineOverheatingTestBench();


	std::shared_ptr<EngineOverheatingTest > getEngineOverheatingTest();

	void runEngine() override;
	std::string getResult() override;

	void setToutside(int Toutside);
	int getToutside();
};

