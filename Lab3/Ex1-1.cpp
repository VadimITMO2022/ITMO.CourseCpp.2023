#include <iostream>
#include <string>
using namespace std;

void privet(string name)

{
	cout << name << ", " << "hello!" << endl;
}



int main()
{
	string name;
	cout << "What is your name?" << endl;
	cin >> name;
	privet(name);
//	cout << name << ", " << "hello!" << endl;
	return 0;
}

