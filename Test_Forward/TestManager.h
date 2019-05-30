#pragma once

#include <string>

#include "Console.h"
#include "FileReader.h"
#include "EngineCreator.h"
#include "TestBenchCreator.h"

/*
Точка входа программы и управляющая логика программы
Отвечает за взаимодействие с тестами и их запусками
*/
class TestManager
{
	/*
	Структура - отвечает за связку стенда, двигателя, и исходных данных.

	Цель: хранение данных о тесте.
	*/
	struct TestData
	{
	public:
		std::string testname;
		EngineCreator::typeEngine idEngine;
		TestBenchCreator::typeTest idTypeTest;
		std::string filename;

		TestData(std::string testname, EngineCreator::typeEngine idEngine, TestBenchCreator::typeTest idTypeTest, std::string filename) {
			this->testname = testname;
			this->idEngine = idEngine;
			this->idTypeTest = idTypeTest;
			this->filename = filename;
		}
	};
public:
	TestManager();
	~TestManager();

	void chooseTest();
private:
	void runTest(TestData test);
	void fillEngine(std::shared_ptr<EngineInterface>& engine, EngineCreator::typeEngine type, std::string filename);
	
	Console console;
	EngineCreator engineCreator;
	TestBenchCreator testBenchCreator;

	std::vector<TestData> tests{
		TestData(
			"Simple ICE overheating test",
			EngineCreator::typeEngine::SimpleICE,
			TestBenchCreator::typeTest::EngineOverheating,
			"SimpleICETestOverheating.txt")
	};

};
