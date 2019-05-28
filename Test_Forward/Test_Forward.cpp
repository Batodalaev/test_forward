// Test_Forward.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <array>
#include "EngineOverheatingTest.h"

double computeV(double V0, double a)
{
	return V0 + a;
}

double computeM(double V, std::vector<std::array<int, 2>> MfromV)
{
	for (unsigned int i = 1; i < MfromV.size(); i++) {
		if (V < MfromV[i][0])
		{
			double V0 = MfromV[i - 1][0];
			double V1 = MfromV[i][0];

			double M0 = MfromV[i - 1][1];
			double M1 = MfromV[i][1];

			double M = M0 + (M1 - M0) * (V - V0) / (V1 - V0);
			return M;
		}
	}
	//Если V>max_V(MfromV)
	return MfromV[MfromV.size() - 1][1];
}

double computea(double M, double I)
{
	return M / I;
}

double computeVn(double M, double Hm, double V, double Hv)
{
	return M * Hm + V * V*Hv;
}

double computeVc(double C, double Toutside, double Tcur)
{
	return C * (Toutside - Tcur);
}

double computeTcur(double Tcur0, double Vn, double Vc)
{
	return Tcur0 + (Vn - Vc);
}

int main()
{
    
	//Запуск менеджера тестов


	std::vector<std::array<int, 2>> MfromV { {0, 20}, { 75,75 }, { 150,100 }, { 200,105 }, { 250,75 }, { 300,0 } };
	int I =(10);
	double Hm=(0.01);
	double Hv=(0.0001);
	double C=(0.1);
	int Toverheat=(110);
	int Toutside;

	while (true) {

		std::cout << "Input Toutside: ";
		std::cin >> Toutside;

		long long Count = 0;
		double Tcur = Toutside;
		double V = 0;
		double M = computeM(V, MfromV);
		double a = computea(M, I);
		double Vn = computeVn(M, Hm, V, Hv);
		double Vc = 0;// computeVc(C, Toutside, Tcur);

		while (Tcur < Toverheat) {
			Count++;
			Tcur = computeTcur(Tcur, Vn, Vc);
			V = computeV(V, a);
			M = computeM(V, MfromV);
			a = computea(M, I);
			Vn = computeVn(M, Hm, V, Hv);
			Vc = computeVc(C, Toutside, Tcur);
			std::cout << Tcur << std::endl;
		}
		std::cout << Count << " seconds" << std::endl << std::endl;

	}
	system("pause");
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
