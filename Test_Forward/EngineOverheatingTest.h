#pragma once


/*
Класс - интерфейс взаимодействия двигателя с тестовым стендом.
Тип теста: Замер времени работы двигателя на холостом ходе до перегрева.

Цель класса: Централизовать взаимодействие тестового стенда с двигателем.
*/
class EngineOverheatingTest
{
public:
	//EngineOverheatingTest();
	//~EngineOverheatingTest();

	//никаких реализованных методов и никаких полей
	//только нереализованные виртуальные методы(абстрактные)


	/*
	Установить температуру окружающей среды
	*/
	virtual void setToutside(int val) = 0;
	/*
	Получить температуру окружающей среды
	*/
	virtual int getToutside() = 0;

	/*
	Прошедшее время в симуляционных секундах с момента старта симуляции
	*/
	virtual long long getSimulationTimeinSeconds() = 0;

	/*
	Текущая температура двигателя в целых числах
	*/
	virtual int getTcur() = 0;

	/*
	Проверка на перегрев двигателя
	*/
	virtual bool isOverheated() = 0;

	/*
	Очищает все изменяемые параметры
	Запуск+(set all parameters with V=0, Tcur=Toutside)
	*/
	virtual bool start() = 0;
	/*
	Каждый запуск этой функции прибавляет 1 секунду симуляции, и обновляет параметры
	*/
	virtual void updatePerSecond() = 0;
};

