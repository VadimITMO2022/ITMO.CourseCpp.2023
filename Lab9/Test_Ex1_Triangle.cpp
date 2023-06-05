#include <iostream>
#include<cmath>
#include <windows.h>
using namespace std;

class WrongLengthsError {

private:

    string message;

public:

    WrongLengthsError() : message("The sum of the lengths of two sides is greater than the length of the third side")
    {
    }

    void printMessage() const {
        cout << message << endl;
    }

};


float HeronsFormula(float a, float b, float c)
{
    if (a + b < c || a + c < b || b + c < a) {
        throw WrongLengthsError();
    }
    else {
    float p = (a + b + c) / 2.;  // полупериметр 
    float A = p * (p - c) * (p - c) * (p - c);
    A = sqrt(A);
    return A;
}
}




int main() {
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);
   
   

    double a, b, c, p;

    cout << "Input lengths of the sides of triangle. " << endl;
    cout << endl;
    cout << "Input lengths of 1st side: " ;
    cin >> a;
 //   cout << endl;

    cout << "Input lengths of 2nd side: " ;
    cin >> b;
 //   cout << endl;

    cout << "Input lengths of 3rd side: " ;
    cin >> c;
    cout << endl;

// вычисление площади по формуле Герона

    try {
        float result = HeronsFormula(a, b, c);
        cout << "Area = " << result << endl;
    }

    catch (WrongLengthsError& error)

    {
        cout << "ERROR: ";
        error.printMessage();
        return 1; // завершение программы при ошибке 
    }

    return 0; // нормальное завершение программы 
}