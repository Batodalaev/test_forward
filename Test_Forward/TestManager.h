#pragma once

#include <string>

#include "Console.h"
#include "FileReader.h"
#include "EngineCreator.h"
#include "TestBenchCreator.h"

/*

*/
class TestManager
{
	struct Test
	{
	public:
		std::string testname;
		EngineCreator::typeEngine idEngine;
		TestBenchCreator::typeTest idTypeTest;
		std::string filename;

		Test(std::string testname, EngineCreator::typeEngine idEngine, TestBenchCreator::typeTest idTypeTest, std::string filename) {
			this->testname = testname;
			this->idEngine = idEngine;
			this->idTypeTest = idTypeTest;
			this->filename = filename;
		}
	};
public:
	

	TestManager();
	~TestManager();

	/*
	Console
	FileReader
	EngineCreator
	TestBenchCreator
	*/
	void chooseTest();
private:
	void runTest(Test test);
	void fillEngine(std::shared_ptr<EngineInterface>& engine, EngineCreator::typeEngine type, std::string filename);
	

	

	Console console;
	EngineCreator engineCreator;
	TestBenchCreator testBenchCreator;

	std::vector<Test> tests{
		Test(
			"Simple ICE overheating test",
			EngineCreator::typeEngine::SimpleICE,
			TestBenchCreator::typeTest::EngineOverheating,
			"SimpleICETestOverheating.txt")
	};

};
