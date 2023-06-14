#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

// ������������ ����� Person

class Person
{
protected:
	int id;
	string name;
	string phone;
	string str;

public:
	Person() {
		id = 0;
		name = "anonimus";
		phone = "00-00";
	}

	Person(int id, string name, string phone) {
		this->id = id;
		this->name = name;	
		this->phone = phone;
	}

	virtual string getString() {

		str = to_string(id) + ", " + name + ", " + phone;
		return str;
	}

	virtual void show() = 0; 
	
};

// ����� ��������� Student


class Student : public Person
{
private:
	int group;
	string occupation = "student";
	string str;
	
public:
	Student() : Person()
	{
		group = 0;
	}

	Student(int id, string name, string phone, int group) : Person(id, name, phone)
	{
		this->group = group;
	}

	string getString() {

		str = occupation + ", " +  Person::getString() + ", " + to_string(group);
		return str;
	}

	string getStudentName() {
		return to_string(id) + ", " + name;
	}

	void show()
	{
		cout << getString() <<  endl;
	}
};


// ����� ��������� Teacher

class Teacher : public Person
{
private:
	string rank;
	string occupation = "teacher";
	string str;
	Student* student;

public:
	Teacher() : Person()
	{
		rank = "no rank";
	}

	Teacher(int id, string name, string phone, string rank) : Person(id, name, phone)
	{
		this->rank = rank;
	}

	// ����������� �������. ����������� ��������� ���������
	void addSupervisedStudent(Student* student) {
		this->student = student;
	}

	string getString() {

		str = occupation + ", " + Person::getString() + ", " + rank + ", " + student->getStudentName();
		return str;
	}

	void show()
	{
		cout << getString() << endl;
	}
};

// ����� ��������� Chancellor ���������� ��� ������ ������� Singleton

class Chancellor : public Person
{
private:
	string rank;
	string occupation = "dean";
	string str;
	string universityName;

	Chancellor() : Person()
	{
		universityName = "no name";
	}

	Chancellor(int id, string name, string phone, string universityName) : Person(id, name, phone)
	{
		this->universityName = universityName;
	}

public:

	static  Chancellor& setChancellor(int id, string name, string phone, string universityName) {

		static Chancellor chancellor(id, name, phone, universityName);

		return chancellor;
	}

	 string getString() {

		str = occupation + ", " + Person::getString() + ", "+ universityName;
		
		return str;
	}

	void show()
	{
		cout << getString() << endl;
	}
};


// ����� ��������� Colleague

class Colleague : public Person
{
private:
	string department;
	string occupation = "collegue";
	string str;

public:
	Colleague() : Person()
	{
		department = "no department";
	}

	Colleague(int id, string name, string phone, string department) : Person(id, name, phone)
	{
		this->department = department;
	}

	string getString() {

		str = occupation  +", " + Person::getString()+ ", " + department;
		return str;
	}

	void show()
	{
		cout << getString() << endl;
	}
};


// ��������� ��������������

class Interface {

private:
	vector<Person*> person;

public:

	// �������� ������ � ������-��������� person 
	void addPerson(Person* ps) {
		person.push_back(ps);
	}

	// ������� ������� �� ��������� person � �������
	void printConsole() {
		for (Person* ps : person)
		{
			ps->show();
		}
	};

	// ������� ������� �� ��������� person � ���� fileName

	void printFile(string fileName) {
		ofstream fileOut;
		fileOut.open(fileName);
		for (Person* ps : person)
		{
			fileOut << ps->getString() << endl;
		}
		fileOut.close();
	};
};



int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

// �������� ������� ������ ������ Person 
//	Person ps(45365, "Shon O'Relly", "47-29");

// ������� ���������

	Student st1(10355, "Tom Minsons", "27-23", 125);
	Student st2(10357, "Mary Taylor", "11-25", 128);
	Student st3(10364, "John Bradshow", "07-23", 134);

// ������� ��������������
	Teacher tr1(20356, "John Smith", "22-56", "Professor");
	Teacher tr2(20676, "Neel Sander", "11-25", "Lecturer");
	Teacher tr3(20623, "Rhonda O'Shely", "41-29", "Associate Professor");

//  ������ ������������� �������� ������� ������������� �������� - ��� ���������:
	tr1.addSupervisedStudent(&st1);
	tr2.addSupervisedStudent(&st2);
	tr3.addSupervisedStudent(&st3);

// c������ ������
	Colleague cg1(30356, "Susan McGee", "82-36", "Chemistry");
	Colleague cg2(30676, "Nancy Desham", "15-75", "Accounting");
	Colleague cg3(30623, "Mildred Gonsales", "43-99", "Human Resources");

// ������� 2-� ��������
	Chancellor ch1 = Chancellor:: setChancellor(30623, "Mildred Gonsales", "23-39", "MIT");
	Chancellor ch2 = Chancellor::setChancellor(50663, "Donald Moore", "43-29", "Harvard");

// ������� �� ������ ������ 1 �������	
	ch1.show();
	ch2.show();

// ������� ��������� �������������� inter
	Interface inter;

// ��������� ������� � ��������� person
	inter.addPerson(&st1);
	inter.addPerson(&st2);
	inter.addPerson(&st3);
	inter.addPerson(&tr1);
	inter.addPerson(&tr2);
	inter.addPerson(&tr3);
	inter.addPerson(&cg1);
	inter.addPerson(&cg2);
	inter.addPerson(&cg3);

// �������� ��������� person � �������
	inter.printConsole();

// �������� ��������� person � ����
	inter.printFile("addressbook.txt");
	
}