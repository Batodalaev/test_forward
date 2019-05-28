#pragma once


/*
����� - ��������� �������������� ��������� � �������� �������.
��� �����: ����� ������� ������ ��������� �� �������� ���� �� ���������.

���� ������: �������������� �������������� ��������� ������ � ����������.
*/
class EngineOverheatingTest
{
public:
	//EngineOverheatingTest();
	//~EngineOverheatingTest();

	//������� ������������� ������� � ������� �����
	//������ ��������������� ����������� ������(�����������)


	/*
	���������� ����������� ���������� �����
	*/
	virtual void setToutside(int val) = 0;
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

