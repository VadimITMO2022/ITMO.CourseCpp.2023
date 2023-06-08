#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <sstream>
using namespace std;

class human {

private:
	std::string name; 
	std::string second_name; 
	std::string last_name; 
	
public:

	virtual void getdata()
	{
		cout << "Input given name: ";
		cin >> name;
		cout << "Input second name: ";
		cin >> second_name;
		cout << "Input family name: ";
		cin >> last_name;
	}

	virtual void putdata()
	{
		cout << name << " " << second_name << " " << name << ",  ";
	}

};


class student : public human {

private:	
	vector<int>scores;  // scores
	int numScores;
	int score;

public:
	
	virtual void getdata()
	{
		human::getdata();
		cout << "Input number of scores: ";
		cin >> numScores;
		cout << "Input scores: ";
		for (int i = 0; i < numScores; ++i) {
			cin >> this->score; 
			scores.push_back(score);
		}
	}

	virtual void putdata()
	{
		human::putdata();
		cout << "student, average score: " << get_average_score() << endl;
	}


	float get_average_score()
	{
		// Общее количество оценок
		unsigned int count_scores = this->scores.size();
		// Сумма всех оценок студента
		unsigned int sum_scores = 0;
		// Средний балл
		float average_score;
		for (unsigned int i = 0; i < count_scores; ++i) {
			sum_scores += this->scores[i];
		}
		average_score = (float)sum_scores / (float)count_scores;
		return average_score;
	}


};


class teacher : public human {

private:
	unsigned int work_time; // work time

public:
	void getdata()
	{
		human::getdata();
		cout << "Input number of work hours : ";
		cin >> this->work_time;

	}
	void putdata()
	{
		human::putdata();
		cout << "teacher, number of work hours: " << this->work_time << endl;
	}
};



int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

human* pubarr[100];
int n = 0;
char choice;
do
{
	cout << "Input data for student or teacher  (s / t) ? ";
	cin >> choice;
	if (choice == 's')
		pubarr[n] = new student;
	else
		pubarr[n] = new teacher;
	pubarr[n++]->getdata();
	cout << "Continue(y / n) ? ";
	cin >> choice;
} while (choice == 'y');
for (int j = 0; j < n; j++)
{
	cout << j+1 << " ";
	pubarr[j]->putdata(); //Otput data
}
cout << endl;
return 0;
}
