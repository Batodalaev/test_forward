#include "pch.h"
#include "FileReader.h"

FileReader::FileReader(std::string filename)
{
	fin.open(filename);
}

FileReader::~FileReader()
{
	fin.close();
}

bool FileReader::isOpen()
{
	return fin.is_open();
}

void FileReader::fillSimpleICEngine(std::shared_ptr<EngineInterface>& engine)
{
	std::shared_ptr<SimpleICEngine> sice = std::reinterpret_pointer_cast<SimpleICEngine, EngineInterface>(engine);
	try {
		int I = read<int>("I");
		std::vector<int> arrayM = read<std::vector<int>>("M");
		std::vector<int> arrayV = read<std::vector<int>>("V");
		int Toverheat = read<int>("Toverheat");
		double Hm = read<double>("Hm");
		double Hv = read<double>("Hv");
		double C = read<double>("C");


		sice->setI(I);

		sice->setMfromV(arrayM, arrayV);

		sice->setHm(Hm);
		sice->setHv(Hv);
		sice->setC(C);

	}
	catch (std::exception e) {
		throw e;
	}

}
