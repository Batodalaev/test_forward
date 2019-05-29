#include "pch.h"
#include "EngineCreator.h"


EngineCreator::EngineCreator()
{
}


EngineCreator::~EngineCreator()
{
}

std::shared_ptr<EngineInterface> EngineCreator::getEngineInterface(typeEngine type)
{
	switch (type)
	{
	case EngineCreator::None:
		return nullptr;
		break;
	case EngineCreator::SimpleICE:
		return std::shared_ptr<EngineInterface>(new SimpleICEngine);
		break;
	default:
		return nullptr;
		break;
	}
	return nullptr;
}