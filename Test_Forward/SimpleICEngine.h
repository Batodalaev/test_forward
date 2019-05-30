#pragma once

#include <vector>
#include <array>
#include "EngineOverheatingTest.h"
/*
Simple internal combustion engine
Класс - упрощенная модель двигателя.
Расчетные формулы для этого двигателя взяты из тестового задания.

Допущение:Температура окружающей среды по умолчанию равна 0.

Цель класса: рассчитывать изменение параметров с ходом симуляционного времени
*/
class SimpleICEngine: public virtual EngineOverheatingTest
{
public:
	//Конструктор по умолчанию
	SimpleICEngine();
	//Конструктор с параметрами
	SimpleICEngine(std::vector<int>& arrayM, std::vector<int>& arrayV, int I,
		double Hm, double Hv, double C, int Toverheat, int Toutside=0);
	//Конструктор копирования
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
	//Получить текущую температуру двигателя округленную в меньшую сторону в целых числах
	int getTcur() override;

	bool isOverheated() override;

	/*
	Очищает все изменяемые параметры
	Запуск+(set all parameters with V=0, Tcur=Toutside)
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
	//Момент инерции двигателя I(кг*м2)
	int I;
	/*Кусочно-линейная зависимость крутящего момента M-[1], вырабатываемого двигателем,
	  от скорости вращения коленвала V-[0](крутящий момент в Н*м, скорость вращения в радиан/сек):
	  */
	std::vector<int> arrayM;
	std::vector<int> arrayV;
	//Температура перегрева Toverheat(в градусах по Цельсию)
	int Toverheat;
	//Коэффициент зависимости скорости нагрева от крутящего момента Hm
	double Hm;
	//Коэффициент зависимости скорости нагрева от скорости вращения коленвала Hv
	double Hv;
	//Коэффициент зависимости скорости охлаждения от температуры двигателя и окружающей среды C
	double C;
	//Температура окружающей среды(В градусах по Цельсию) (может ли она изменяться?)
	int Toutside;

	//Текущая скорость вращения коленвала V
	double V;
	//Текущий крутящий момент M
	double M;
	//Текущее ускорение a=M/I
	double a;
	//Скорость нагрева двигателя Vn
	double Vn;
	//Скорость охлаждения двигателя Vc
	double Vc;

	//Текущая температура двигателя Tcur
	double Tcur;
	//Текущее время, прошедшее со старта в секундах Count
	long long Count;
};

