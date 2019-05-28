#include "pch.h"
#include "Console.h"


Console::Console()
{
	in = &std::cin;
	out = &std::cout;
}


Console::~Console()
{
	in = nullptr;
	out = nullptr;
}