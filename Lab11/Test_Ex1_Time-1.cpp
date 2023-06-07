#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Time
{

private:
	string name; // имя момента времени
	int hours; // часы
	int minutes; // минуты
	int seconds; // секунды


public:
	
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

	void set_name(string name1)  	// Установка имени момента времени 
	{
		name = name1;
	}

	string get_name()  // Получение имени момента времени 
	{
		return name;
	}

	Time()  // Конструктор с нулевым значением
	{
		name = "t0";
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
		std::cout << name << " = " << hours << ":" << minutes << ":" << seconds << endl;
	}

// t3 = t1+t2

	Time operator+ (Time& t) {

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

	// t4 = t1 - t2

	Time operator- (Time& t) {

		// total number of seconds
		string name = "t4";
		int stot1 = 3600 * hours + 60 * minutes + seconds;
		int stot2 = 3600 * t.hours + 60 * t.minutes + t.seconds;
		int stot = stot1 - stot2;

		// number of hrs, min and sec in stot
		int hrs = stot / 3600;
		int minsec = stot % 3600;
		int min = minsec / 60;
		int sec = minsec % 60;

		// создание объекта time = сумме 2-х объектов времени
		Time time(name,hrs, min, sec);

		return time;
	};


	// t5 = t1 + h

	Time operator+(float h) {
	//	double hrs, min;
		string name = "t5";
		int stot = h*3600;  // число секунд в h часах 

		int hrs = stot / 3600;
		int minsec = stot % 3600;
		int min = minsec / 60;
		int sec = minsec % 60;

		int hrs1 = hours + hrs;
		int min1 = minutes + min;
		int sec1 = seconds + sec;

		Time time(name,hrs1,min1,sec1);

		return time;
	}


	// сравнение t1 и t2

	string operator< (Time& t) {

		int b;
		string str,str1,str2,str3;
		str1 = "t1 > t2";	
		str2 = "t1 < t2";
		str3 = "t1 = t2"; 

		if (hours > t.hours) {
		      str = str1;
		}
		else if (hours < t.hours) {
			  str = str2;
		}
		else {
			if (minutes > t.minutes) {
				str = str1;
			}
			else if (minutes < t.minutes) {
				str = str2;
			}
			else {
				if (seconds > t.seconds) {
					str = str1;
				}
				else if (seconds < t.seconds) {
					str = str2;
				}
				else {
					str = str3; 
				}
			}
		};


		return str;
	};



};


// t6 = h + t1

	Time operator+(float h, Time& t) {
		string name1 = "t6";
		
		int stot = h * 3600; // число секунд в h часах 

		int hrs = stot / 3600;
		int minsec = stot % 3600;
		int min = minsec / 60;
		int sec = minsec % 60;

		int hrs1 = hrs + t.get_hours();
		int min1 = min + t.get_minutes();
		int sec1 = sec + t.get_seconds();

		Time time(name1, hrs1, min1, sec1);

		return time;
	}




int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	// момент времени t1

	string name = "t1";
	int hours =8;
	int minutes = 45;
	int seconds = 35;	
	Time t1(name, hours, minutes, seconds);
	t1.print_Time();
	cout << endl;

	// момент времени t2

	name = "t2";
	hours = 8;
	minutes = 45;
	seconds = 35;
	Time t2(name, hours, minutes, seconds);
	t2.print_Time();
	cout << endl;


	// t3 = t1+t2	
    Time t3 = t1+t2;
	t3.print_Time();
	cout << endl;

	

	// t4 = t1 - t2
	Time t4 = t1 - t2;
	t4.print_Time();
	cout << endl;
	

	// t5 = t1 + h
	float h = 2.68;
	Time t5 =  t1 + h;
	t5.print_Time();
	cout << endl;


	// t6 = h + t1
	h = 2.68;
	Time t6 = h + t1;
	t6.print_Time();
	cout << endl;
	

	// сравнение t1 и t2
	string str = (t1 < t2);
	cout << str << endl;
	cout << endl;
//	

	return 0;
}









