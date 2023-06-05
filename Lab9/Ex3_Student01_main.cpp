#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Student
{

private:
	string name; // Имя
	string last_name; // Фамилия
	int scores[5]; // Промежуточные оценки
	double average_score; // Средний балл

public:

	class ExScore {    //класс исключений
	public:
		string origin; //для имени функции
		int iValue;    //для хранения ошибочного значения

		ExScore(string or1, int sc) {
			origin = or1; //строка с именем виновника ошибки
			iValue = sc; //сохраненное неправильное значение 
		}
	};


	// Установка имени студента
	void set_name(string student_name)
	{
		name = student_name;
	}
	// Получение имени студента
	string get_name()
	{
		return name;
	}
	// Установка фамилии студента
	void set_last_name(string student_last_name)
	{
		last_name = student_last_name;
	}
	// Получение фамилии студента
	string get_last_name()
	{
		return last_name;
	}
	// Установка промежуточных оценок

	void set_scores(int student_scores[])
	{
		for (int i = 0; i < 5; ++i) {
			if (student_scores[i] > 5)
				throw ExScore("в функции set_scores()", student_scores[i]);
			scores[i] = student_scores[i];
		}
	}


	// Установка промежуточных оценок
	int get_scores()
	{	
		for (int i = 0; i < 5; ++i) {
		return	scores[i];
		}

	}


	// Установка среднего балла
	void set_average_score(double ball)
	{
		average_score = ball;
	}
	// Получение среднего балла
	double get_average_score()
	{
		return average_score;
	}


};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	// Создание объекта класса Student
	Student student01;

	string name;
	string last_name;
	int scores[5];

	// Ввод имени с клавиатуры
	std::cout << "Name: ";
	getline(cin, name);
	// Ввод фамилии
	std::cout << "Last name: ";
	getline(cin, last_name);

	// Сумма всех оценок
	int sum = 0;
	// Ввод промежуточных оценок
	for (int i = 0; i < 5; ++i) {
		std::cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		// суммирование
		sum += scores[i];
	}

	// Сохранение имени и фамилии в объект класса Student
	student01.set_name(name);
	student01.set_last_name(last_name);
	// Сохранение промежуточных оценок в объект класса Student
	try {
		student01.set_scores(scores);
	}
	catch (Student::ExScore& ex)
	{
		std::cout << "\nОшибка инициализации " << ex.origin;
		std::cout << "\nВведенное значение оценки " << ex.iValue << " является недопустимым\n";
	}

	double average_score = sum / 5.0;
	// Сохранение среднего балла в объект класса Student
	student01.set_average_score(average_score);
	std::cout << "Average score for " << student01.get_name() << " "
		<< student01.get_last_name() << " is "
		<< student01.get_average_score() << endl;




	// Создание 2-го объекта класса Student
	Student student02;

	string name2 = "Peter";
	string last_name2 = "Monson";
	int scores2[5] = { 2, 3, 5, 6, 6 };

	int sum2 = 0;
	for (int i = 0; i < 5; ++i) {	
			sum2 += scores2[i];
	}
	double average_score2 = sum2 / 5.0;


	// Сохранение имени и фамилии в объект класса Student
	student02.set_name(name2);
	student02.set_last_name(last_name2);
	// Сохранение промежуточных оценок в объект класса Student
	try {
		student02.set_scores(scores2);
	}
	catch (Student::ExScore& ex)
	{
		std::cout << "\nОшибка инициализации " << ex.origin;
		std::cout << "\nВведенное значение оценки " << ex.iValue << " является недопустимым\n";
	}
	// Сохранение среднего балла в объект класса Student
	student02.set_average_score(average_score2);

	std::cout << "Average score for " << student02.get_name() << " "
		<< student02.get_last_name() << " is "
		<< student02.get_average_score() << endl;

	return 0;
}









