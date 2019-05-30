#pragma once

#include "EngineInterface.h"

/*
����� - ��������� �������������� ��������� � �������� �������.
��� �����: ����� ������� ������ ��������� �� �������� ���� �� ���������
	��� ��������� ����������� ���������� �����

���� ������: �������������� �������������� ��������� ������ � ����������.
*/
class EngineOverheatingTest:public virtual EngineInterface
{
public:
	//EngineOverheatingTest();
	~EngineOverheatingTest() {};

	//���������:����������� ���������� ����� �� ��������� ����� 0.
	static const int defaultToutside = 0;
	//������� ������������� ������� � ������� �����
	//������ ��������������� ����������� ������(�����������)


	/*
	���������� ����������� ���������� �����
	*/
	virtual void setToutside(int val = defaultToutside) = 0;
	/*
	�������� ����������� ���������� �����
	*/
	virtual int getToutside() = 0;

	/*
	��������� ����� � ������������� �������� � ������� ������ ���������
	*/
	virtual long long getSimulationTimeinSeconds() = 0;

	/*
	������� ����������� ��������� � ����� ������
	*/
	virtual int getTcur() = 0;

	/*
	�������� �� �������� ���������
	*/
	virtual bool isOverheated() = 0;

	/*
	������� ��� ���������� ���������
	������+(set all parameters with V=0, Tcur=Toutside)
	*/
	virtual bool start() = 0;
	/*
	������ ������ ���� ������� ���������� 1 ������� ���������, � ��������� ���������
	*/
	virtual void updatePerSecond() = 0;
};

