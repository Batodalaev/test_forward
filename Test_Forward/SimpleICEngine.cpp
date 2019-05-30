#include "pch.h"
#include "SimpleICEngine.h"


SimpleICEngine::SimpleICEngine():
	SimpleICEngine(
		std::vector<int>{ 20,75,100,105,75,0 },
		std::vector<int>{ 0,75,150,200,250,300 },
		10,0.01,0.0001,0.1,110)
{
}
SimpleICEngine::SimpleICEngine(std::vector<int>& arrayM, std::vector<int>& arrayV, 
	int I, double Hm, double Hv, double C, int Toverheat, int Toutside)
{
	setMfromV(arrayM,arrayV);
	setI(I);
	setHm(Hm);
	setHv(Hv);
	setC(C);
	setToverheat(Toverheat);
	setToutside(Toutside);
}

SimpleICEngine::SimpleICEngine(SimpleICEngine & val) :
	SimpleICEngine(val.arrayM,val.arrayV, val.I, val.Hm, val.Hv, val.C, val.Toverheat, val.Toutside)
{
}

SimpleICEngine::~SimpleICEngine()
{
	arrayM.clear();
	arrayV.clear();
}


void SimpleICEngine::setMfromV(std::vector<int> &arrayM, std::vector<int> &arrayV)
{
	this->arrayM.clear();
	this->arrayV.clear();
	this->arrayM = arrayM;
	this->arrayV = arrayV;
}

void SimpleICEngine::setI(int val)
{
	I = val;
}

void SimpleICEngine::setHm(double val)
{
	Hm = val;
}

void SimpleICEngine::setHv(double val)
{
	Hv = val;
}

void SimpleICEngine::setC(double val)
{
	C = val;
}

void SimpleICEngine::setToverheat(int val)
{
	Toverheat = val;
}

void SimpleICEngine::setToutside(int val)
{
	Toutside = val;
}

int SimpleICEngine::getI()
{
	return I;
}

double SimpleICEngine::getHm()
{
	return Hm;
}

double SimpleICEngine::getHv()
{
	return Hv;
}

double SimpleICEngine::getC()
{
	return C;
}

int SimpleICEngine::getToverheat()
{
	return Toverheat;
}

int SimpleICEngine::getToutside()
{
	return Toutside;
}

double SimpleICEngine::getV()
{
	return V;
}

double SimpleICEngine::getM()
{
	return M;
}

double SimpleICEngine::geta()
{
	return a;
}

double SimpleICEngine::getVn()
{
	return Vn;
}

double SimpleICEngine::getVc()
{
	return Vc;
}

double SimpleICEngine::getTcurRaw()
{
	return Tcur;
}

long long SimpleICEngine::getSimulationTimeinSeconds()
{
	return Count;
}

int SimpleICEngine::getTcur()
{
	//округлить в большую сторону - std::ceil
	//в меньшую сторону - std::floor
	return std::floor(Tcur);
}

bool SimpleICEngine::isOverheated()
{
	return getTcur() >= getToverheat();
}

bool SimpleICEngine::start()
{
	if (I == 0)
		return false;

	Count = 0;
	Tcur = Toutside;
	V = 0;
	M = computeM(V, arrayM, arrayV);
	a = computea(M, I);
	Vn = computeVn(M, Hm, V, Hv);
	Vc = 0;// computeVc(C, Toutside, Tcur);
	return true;
}

void SimpleICEngine::updatePerSecond()
{
	//ѕор€док рассчета
	Count++;
	Tcur = computeTcur(Tcur, Vn, Vc);
	V = computeV(V, a);
	M = computeM(V, arrayM, arrayV);
	a = computea(M, I);
	Vn = computeVn(M, Hm, V, Hv);
	Vc = computeVc(C, Toutside, Tcur);
}


double SimpleICEngine::computeV(double V0, double a)
{
	return V0 + a;
}

double SimpleICEngine::computeM(double V, std::vector<int> &arrayM, std::vector<int> &arrayV)
{
	if (arrayV.size() != arrayM.size())return 0;
	//TODO проверить алгоритм на правильность
	for (int i = 1; i < arrayM.size(); i++) {
		if (V < arrayV[i])
		{
			double V0 = arrayV[i - 1];
			double V1 = arrayV[i];

			double M0 = arrayM[i - 1];
			double M1 = arrayM[i];

			double M = M0 + (M1 - M0) * (V - V0) / (V1 - V0);
			return M;
		}
	}
	//≈сли V>max_V(MfromV)
	return arrayM[arrayM.size() - 1];
}

double SimpleICEngine::computea(double M, double I)
{
	return M / I;
}

double SimpleICEngine::computeVn(double M, double Hm, double V, double Hv)
{
	return M * Hm + V * V*Hv;
}

double SimpleICEngine::computeVc(double C, double Toutside, double Tcur)
{
	return C * (Toutside - Tcur);
}

double SimpleICEngine::computeTcur(double Tcur0, double Vn, double Vc)
{
	return Tcur0 + (Vn - Vc);
}
