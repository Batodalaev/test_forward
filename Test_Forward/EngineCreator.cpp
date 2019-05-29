#include "pch.h"
#include "EngineCreator.h"


EngineCreator::EngineCreator()
{
}


EngineCreator::~EngineCreator()
{
}

std::shared_ptr<SimpleICEngine> EngineCreator::getSimpleICEngine()
{
	return std::shared_ptr<SimpleICEngine>(new SimpleICEngine);
}

std::shared_ptr<SimpleICEngine> EngineCreator::getSimpleICEngine(std::vector<int>& arrayM, std::vector<int>& arrayV, int I, double Hm, double Hv, double C, int Toverheat, int Toutside)
{
	return std::shared_ptr<SimpleICEngine>(new SimpleICEngine(arrayM,arrayV,I,Hm,Hv,C,Toverheat, Toutside));
}
