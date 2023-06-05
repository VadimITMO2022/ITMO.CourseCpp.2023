#include <iostream>
#include <string>
#include <windows.h>
#include "student.h"

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	string name;
	string last_name;
	IdCard* idc = new IdCard(123, "Базовый");

	
	cout << "Name: ";  // Ввод имени с клавиатуры
	getline(cin, name);
	
	cout << "Last name: ";  // Ввод фамилии
	getline(cin, last_name);

	Student* student02 = new Student(name, last_name, idc);

	
	int scores[5];  // Оценки	
	int sum = 0;  // Сумма всех оценок
	
	// Ввод промежуточных оценок
	for (int i = 0; i < 5; ++i) {  
		cout << "Score " << i + 1 << ": ";
		cin >> scores[i];
		sum += scores[i];  // суммирование
	}

	student02 -> set_scores(scores);  // Сохраняем промежуточные оценки в объект класса Student
	double average_score = sum / 5.0;  	// Считаем средний балл
	student02 -> set_average_score(average_score);  // Сохраняем средний балл в объект класса Student

	// Выводим данные по студенту
	cout << "Average score for " << student02 -> get_name() << " "
		<< student02 -> get_last_name() << " is "
		<< student02 -> get_average_score() << endl;
	cout << "IdCard: " << student02->getIdCard().getNumber() << endl;
	cout << "Category: " << student02->getIdCard().getCategory() << endl;

	delete student02;
	delete idc;

	return 0;
}