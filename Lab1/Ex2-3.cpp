#include <iostream>
#include <windows.h>
#include<cmath>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    double perim, p, c;

    cout << "Введите периметр равностороннего треугольника: " << endl;
    cin >> perim;

    // полупериметр
    p = perim / 2.;

    // сторона равностороннего треугольника
    c = perim / 3.;

   // вычисление площади по формуле Герона
    double S =p*(p -c)*(p-c)*(p-c);
    S = sqrt(S);
   
    cout << "Cторона = " << c << " Площадь = " << S << endl;

  
}