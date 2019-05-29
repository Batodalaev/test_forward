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
	
	enum typeEngine :int { None, SimpleICE };

	std::shared_ptr<EngineInterface> getEngineInterface(typeEngine type);

};

