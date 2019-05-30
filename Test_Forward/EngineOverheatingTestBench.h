#pragma once
#include <string>

#include "AbstractTestBench.h"
#include "EngineOverheatingTest.h"

/*
����� - �������� ����� �� ��������
��� �����: ����� ������� ������ ��������� �� �������� ���� �� ��������� 
	��� ��������� ����������� ���������� �����.

���� ������: ������������ ���������, ������� ��������� EngineOverheatingTest.
*/
class EngineOverheatingTestBench:public AbstractTestBench
{
public:
	EngineOverheatingTestBench();
	~EngineOverheatingTestBench();


	std::shared_ptr<EngineOverheatingTest > getEngineOverheatingTest();

	void runEngine() override;
	std::string getResult() override;

	void setToutside(int Toutside);
	int getToutside();
};

