#include <string>
#include <fstream>
#include "student.h"

//Конструктор
Student::Student(string name, string last_name, IdCard *id)
{
	Student::set_name(name);
	Student::set_last_name(last_name);
	Student::setIdCard(id);
}


void Student::set_name(std::string student_name) {  // Установка имени студента
	Student::name = student_name;
}

std::string Student::get_name() {  // Получение имени студента
	return Student::name;
}


void Student::set_last_name(std::string student_last_name) {  // Установка фамилии студента
	Student::last_name = student_last_name;
}

// Получение фамилии студента
std::string Student::get_last_name() { 

	return Student::last_name;
}

// Установка промежуточных оценок
void Student::set_scores(int scores[]) {
	for (int i = 0; i < 5; ++i) {
		Student::scores[i] = scores[i];
	}
}

// Установка среднего балла
void Student::set_average_score(double ball) {
	Student::average_score = ball;
}

// Получение среднего балла
double Student::get_average_score() {
	return Student::average_score;
}

// Установка ID карты

void Student::setIdCard(IdCard* c) {
	Student::iCard = c;
}

// Получение ID карты

IdCard Student::getIdCard() {
	return *Student::iCard;
}