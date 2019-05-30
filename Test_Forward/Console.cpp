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

void Console::writeln()
{
	*out << std::endl;
}

void Console::clear()
{
	{ system("cls"); }
}

void Console::pause()
{
	{ system("pause"); }
}
