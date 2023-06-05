#include <iostream> 
#include <string>
#include <windows.h>
using namespace std;

class DivideByZeroError { 

private:

	string message;

public: 
	
DivideByZeroError() : message("Деление на нуль") 
{
} 

void printMessage() const { 
	cout << message << endl; 
} 

};


float quotient(int numl, int num2) 
{
	if (num2 == 0) throw DivideByZeroError(); 
	return (float)numl / num2; 
}



int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

//	cout << "Введите два целых числа для расчета их частного:\n"; 
	cout << "Введите числитель дроби для расчета частного:\n";
	int number1, number2; 
	cin >> number1; 
//	cin >> number2; 

	for (int i = -10; i < 10; i++) {
		number2 = i;
		try {
			float result = quotient(number1, number2);
			cout << "числитель=" << number1 <<" знаменатель=" << number2 << " частное " << result << endl;
		}

		catch (DivideByZeroError& error)

		{
			cout << "ОШИБКА: ";
			error.printMessage();
			return 1; // завершение программы при ошибке 
		}
	}
		return 0; // нормальное завершение программы 
}