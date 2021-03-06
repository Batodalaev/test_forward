
# Тестовое задание от компании Forward
### Выполнил:
	Батодалаев Саян Александрович
	Срок выполнения: 25.05.2019 - 30.05.2019

## О программе
	Программа представляет собой консольное приложение, ориентированное на 
	тестирование двигателей
	В задании указан только один тип тестов: тест на перегрев, однако реализована 
	возможность расширения
	В задании указан только один тип двигателей: упрощенная модель двигателя 
	внутреннего сгорания, однако реализована возможность расширения

	3 части программы:
	1. упрощенная модель двигателя
	2. тестовый стенд
	3. менеджер тестов

### Упрощенная модель двигателя
#### Описание:
	Выполняет дискретную симуляцию работы двигателя.	
#### Отношение с другими частями	
	Взаимодействует с тестовым стендом через интерфейсы.
	Хранится в менеджере тестов.
#### Отношение с тестами		
	Для каждого типа теста отдельный интерфейс.
#### О интерфейсах
	В С++ интерфейсы определяются при помощи абстрактных классов, а реализация 
	интерфейса производится путём наследования этих классов. 
#### Зачем нужен интерфейс двигателю
	Чтобы четко выделить, какие методы потребуются двигателю для взаимодействия
	с тестовым стендом.

### Тестовый стенд
#### Описание:
	Рассчитывает симуляцию двигателя.
	Останавливает симуляцию при выполнении требуемых для остановки условий.
#### Отношение с другими частями
	Принимает на вход интерфейс двигателя от менеджера тестов.
	Получаемые результаты отдает менеджеру тестов.
#### Отношение с тестами		
	Для каждого типа теста свой тестовый стенд.

### Менеджер тестов
#### Описание:
	Точка входа программы.
	Читает исходные данные и вводит в симуляцию двигателя.
	Получает температуру окружающей среды с клавиатуры от пользователя.
	Запускает тесты из списка тестов.
#### Отношение с другими частями
	Получает результаты от тестового стенда и отображает пользователю через 
	консольный ввод-вывод
#### Отношение с тестами		
	Для каждого теста свой конфигурационный файл с исходными данными. 
	Тесты могут быть одинаковы по типам, но отличаться в моделях тестируемых
	двигателях.

## Расширение
	Чтобы добавить новый двигатель, тип теста, или тест, требуется изменить 
	исходный код
	Для замены исходных данных к тестам, нужно изменить конфигурационный файл
	Что нужно сделать чтобы добавить новый:		
### Двигатель
	Создать новый класс с двигателем и реализовать необходимые интерфейсы, 
	создать файлы для исходных данных, добавить тесты с этим двигателем, 
	двигатель в менеджер тестов, 
### Тип теста(Интерфейс/Стенд)
	Создать новый тестовый стенд, создать для него интерфейс, реализовать в 
	требуемых моделях двигателей, создать файлы для исходных данных, добавить 
	тесты этого типа,стенд, интерфейс в менеджер тестов
### Тест
	Выбрать тип теста, модель двигателя, файл с исходными данными, добавить 
	новый тест в менеджер тестов
### Исходные данные		
	Выбрать файл с исходными данными для требуемого теста, заменить в нем 
	данные на новые
