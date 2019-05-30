#pragma once
#include "SimpleICEngine.h"
/*
 ласс - фабрика, по созданию двигателей.
 аждый двигатель, что будет произведен этим Creator-ом, должен наследовать EngineInterface.
“ип двигателей - typeEngine

÷ель класса: производство моделей двигателей заданного типа.
*/
class EngineCreator
{
public:
	EngineCreator();
	~EngineCreator();
	
	enum typeEngine :int { None, SimpleICE };

	std::shared_ptr<EngineInterface> getEngineInterface(typeEngine type);

};

