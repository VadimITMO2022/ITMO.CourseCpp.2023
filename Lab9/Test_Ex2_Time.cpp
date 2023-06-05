#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Time
{

private:
	string name; // название момента времени
	int hours; // часы
	int minutes; // минуты
	int seconds; // секунды


public:

	class ExTime {    //класс исключений
	public:
		string iName; //для имени момента времени
		int iHrs, iMin, iSec;    //для хранения неправильного значения

		ExTime(string nam, int hrs, int min, int sec) {
			iName = nam; //строка с именем момента времени
			iHrs = hrs; //сохраненное неправильное значение 
			iMin = min; //сохраненное неправильное значение 
			iSec = sec; //сохраненное неправильное значение 
		}
	};
	
	void set_name(string name1) // Установка имени момента времени
	{
		name = name1;
	}

	string get_name() // Получение имени момента времени
	{
		return name;
	}


	void set_hours(int hours1) // Установка количества часов
	{
		hours = hours1;
	}
	
	int get_hours() // Получение количества часов
	{
		return hours;
	}
	
	void set_minutes(int minutes1)  // Установка количества минут
	{
		minutes = minutes1;
	}
	
	int get_minutes()  // Получение количества минут
	{
		return minutes;
	}

	void set_seconds(int seconds1)  	// Установка количества секунд
	{
		seconds = seconds1;
	}
	
	int get_seconds()  // Получение количества секунд
	{
		return seconds;
	}

	Time()  // Конструктор с нулевым значением
	{
		name = "t3";
		hours = 0;
		minutes = 0;
		seconds = 0;
	}

	Time(string name1, int hours1, int minutes1, int seconds1)  // Конструктор 
	{
		// задание времени в правильном формате 11:59:59
		bool check = hours1 >= 0 && hours1 < 12  
			&& minutes1 >= 0 && minutes1 < 60
			&& seconds1 >= 0 && seconds1 < 60;

		if (!check) {
			throw ExTime(name1, hours1, minutes1, seconds1);

			std::cout << "Вы ввели время в неверном формате: " << hours1 << ":"
				<< minutes1 << ":" << seconds1 << endl;

			// total number of seconds
			int stot = 3600 * hours1 + 60 * minutes1 + seconds1;


			// number of hrs, min and sec in stot
			int hours1 = stot / 3600;

			if (hours1 >= 12) {
				int n = hours1 / 12;
				hours1 = hours1 - 12 * n;
			}
			int minsec = stot % 3600;
			int minutes1 = minsec / 60;
			int seconds1 = minsec % 60;

			std::cout << "Правильный формат: " << hours1 << ":"
				<< minutes1 << ":" << seconds1 << endl;

			name = name1;
			hours = hours1;
			minutes = minutes1;
			seconds = seconds1;

		}
		else {
			name = name1;
			hours = hours1;
			minutes = minutes1;
			seconds = seconds1;
		}

	}


	void print_Time()  // Вывод времени на консоль
	{
		std::cout << "Время " << name << " = " << hours << ":" << minutes << ":" << seconds << endl;
	}


	Time addTime(Time t) {   // сложение 2-х объектов класса Time

		string name = "t3";

		int hourstot = hours + t.hours;
		int minutestot = minutes + t.minutes;
		int secondstot = seconds + t.seconds;

		// total number of seconds
		int stot = 3600 * hourstot + 60 * minutestot + secondstot;


		// number of hrs, min and sec in stot
		int hrs = stot / 3600;
		int minsec = stot % 3600;
		int min = minsec / 60;
		int sec = minsec % 60;

		// создание объекта time = сумме 2-х объектов времени
		Time time(name, hrs, min, sec);

		return time;
	};
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	

	string str1 = "t1";
	int hours1 = 9;
	int minutes1 = 24;
	int seconds1 = 55;

	

	string str2 ="t2";
	int hours2 = 11;
	int minutes2 = 47;
	int seconds2 = 5;

	try {
		// Создание 1-го объекта класса Time

		Time time1(str1, hours1, minutes1, seconds1);
		time1.print_Time();
		cout << endl;

		// Создание 2-го объекта класса Time

		Time time2(str2, hours2, minutes2, seconds2);
		time2.print_Time();
		cout << endl;

		// Создание 3-го объекта класса Time c нулевым значением

		Time time3;
		time3.print_Time();
		cout << endl;

		// Cложение 1-го и 2-го объектов и запись результата в 3-ий объект

		cout << "Cложение: " << time3.get_name() << " = " << time1.get_name() << " + " << time2.get_name() << endl;

		time3 = time1.addTime(time2);
		time3.print_Time();
		// cout << "время: " << time3.get_hours() << ":" << time3.get_minutes() << ":" << time3.get_seconds() << endl;

	}
	catch (Time::ExTime& ex)
	{
	//	std::cout << "\nОшибка инициализации " << ex.origin;
		std::cout << "\nЗначение времени " << ex.iName << " = "<< ex.iHrs << ":" << ex.iMin << ":" << ex.iSec << " является недопустимым\n";
	}

	return 0;
}









