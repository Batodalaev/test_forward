#include "pch.h"
#include "TestManager.h"


TestManager::TestManager()
{
	console = Console();
	engineCreator = EngineCreator();
	testBenchCreator = TestBenchCreator();
}


TestManager::~TestManager()
{
}

void TestManager::chooseTest()
{
	for (int i = 0; i != tests.size(); ++i) {
		console.writeln(std::string("Test " + std::to_string(i) + " - " + tests[i].testname));
	}
	console.write(">Please input test: ");
	int n = console.read<int>();
	console.writeln(" ");
	console.clear();
	if (n < tests.size() && n >= 0) {
		console.writeln(std::string("Test " + std::to_string(n) + " - " + tests[n].testname+ " choosed"));
		runTest(tests[n]);
	}
	else {
		console.writeln("Wrong test number");
	}
	console.pause();
	console.clear();
}

void TestManager::runTest(Test test)
{
	console.writeln<std::string>(std::string(">Find engine " + test.idEngine));
	std::shared_ptr<EngineInterface> engine = engineCreator.getEngineInterface(test.idEngine);
	console.writeln<std::string>(std::string(">Find test bench " + test.idTypeTest));
	std::shared_ptr<AbstractTestBench> testBench = testBenchCreator.getTestBench(test.idTypeTest);

	console.writeln(">Open config file");
	try
	{
		fillEngine(engine, test.idEngine, test.filename);
	}
	catch (std::exception e)
	{
		console.writeln<std::string>(std::string(e.what()));
		return;
	}
	console.writeln(">Config file loaded");

	testBench->setEngineInterface(engine);
	console.writeln(">Engine placed on test bench");
	switch (test.idTypeTest)
	{
	case TestBenchCreator::None:
		break;
	case TestBenchCreator::EngineOverheating:
		console.write(">Please input Toutside: ");
		//one line
		std::reinterpret_pointer_cast<EngineOverheatingTestBench, AbstractTestBench>(testBench)->
			setToutside(console.read<int>());
		console.writeln(" Celsius");
		break;
	default:

		break;
	}
	console.writeln(">Start simulation");
	console.writeln("...");
	testBench->runEngine();
	console.writeln(">Stop simulation");

	console.writeln(testBench->getResult());
}
void TestManager::fillEngine(std::shared_ptr<EngineInterface>& engine, EngineCreator::typeEngine type, std::string filename)
{
	FileReader reader("Configuration file/"+filename);
	if (!reader.isOpen()) {
		throw std::exception("Файл не открывается");
	}
	switch (type)
	{
	case EngineCreator::None:
		throw std::exception("Некорректный тип двигателя");
		break;
	case EngineCreator::SimpleICE:
		reader.fillSimpleICEngine(engine);
		break;
	default:
		throw std::exception("Тип двигателя не найден");
		break;
	}

}
