#pragma once

#include <vector>
#include <array>
#include "EngineOverheatingTest.h"
/*
Simple internal combustion engine
����� - ���������� ������ ���������.
��������� ������� ��� ����� ��������� ����� �� ��������� �������.

���������:����������� ���������� ����� �� ��������� ����� 0.

���� ������: ������������ ��������� ���������� � ����� �������������� �������
*/
class SimpleICEngine: public virtual EngineOverheatingTest
{
public:
	//����������� �� ���������
	SimpleICEngine();
	//����������� � �����������
	SimpleICEngine(std::vector<int>& arrayM, std::vector<int>& arrayV, int I,
		double Hm, double Hv, double C, int Toverheat, int Toutside=0);
	//����������� �����������
	SimpleICEngine(SimpleICEngine& val);

	~SimpleICEngine() override;

	//only setter
	
	void setMfromV(std::vector<int> &arrayM, std::vector<int> &arrayV);
	//setter and getter
	
	void setI(int val);
	void setHm(double val);
	void setHv(double val);

	void setC(double val);
	void setToverheat(int val);
	void setToutside(int val) override;

	int getI();
	double getHm();
	double getHv();
	double getC();
	int getToverheat();
	int getToutside() override;

	//only getter

	double getV();
	double getM();
	double geta();
	double getVn();
	double getVc();
	double getTcurRaw();
	long long getSimulationTimeinSeconds() override;
	//�������� ������� ����������� ��������� ����������� � ������� ������� � ����� ������
	int getTcur() override;

	bool isOverheated() override;

	/*
	������� ��� ���������� ���������
	������+(set all parameters with V=0, Tcur=Toutside)
	*/
	bool start() override;
	//increaseCount = Update
	void updatePerSecond() override;

protected:
	static double computeV(double V0, double a);
	static double computeM(double V, std::vector<int> &arrayM, std::vector<int> &arrayV);
	static double computea(double M, double I);
	static double computeVn(double M, double Hm, double V, double Hv);
	static double computeVc(double C, double Toutside, double Tcur);
	static double computeTcur(double Tcur0, double Vn, double Vc);
private:
	//������ ������� ��������� I(��*�2)
	int I;
	/*�������-�������� ����������� ��������� ������� M-[1], ��������������� ����������,
	  �� �������� �������� ��������� V-[0](�������� ������ � �*�, �������� �������� � ������/���):
	  */
	std::vector<int> arrayM;
	std::vector<int> arrayV;
	//����������� ��������� Toverheat(� �������� �� �������)
	int Toverheat;
	//����������� ����������� �������� ������� �� ��������� ������� Hm
	double Hm;
	//����������� ����������� �������� ������� �� �������� �������� ��������� Hv
	double Hv;
	//����������� ����������� �������� ���������� �� ����������� ��������� � ���������� ����� C
	double C;
	//����������� ���������� �����(� �������� �� �������) (����� �� ��� ����������?)
	int Toutside;

	//������� �������� �������� ��������� V
	double V;
	//������� �������� ������ M
	double M;
	//������� ��������� a=M/I
	double a;
	//�������� ������� ��������� Vn
	double Vn;
	//�������� ���������� ��������� Vc
	double Vc;

	//������� ����������� ��������� Tcur
	double Tcur;
	//������� �����, ��������� �� ������ � �������� Count
	long long Count;
};

