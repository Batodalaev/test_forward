#pragma once
#include "SimpleICEngine.h"
/*
Класс - фабрика, по созданию двигателей

Цель класса: создавать объекты - модели двигателей.
*/
class EngineCreator
{
public:
	EngineCreator();
	~EngineCreator();
	

	std::shared_ptr<SimpleICEngine> getSimpleICEngine();
	std::shared_ptr<SimpleICEngine> getSimpleICEngine(std::vector<int>& arrayM, std::vector<int>& arrayV, int I,
		double Hm, double Hv, double C, int Toverheat, int Toutside = 0);


};

