#include <iostream>
#include<cmath>
#include <windows.h>
using namespace std;

double cubeRoot(double);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    double a;

    cout << "Введите число: ";
    cin >> a;
    cout << "Стандартная функция:  " << pow(a, 1.0 / 3) << endl;
    cout << "Итерационная метод:  " << cubeRoot(a) << endl;
}

double cubeRoot(double a) {
    double iter1 = 0.;
    double iter2 = a;

    while (abs(iter1 - iter2) > 1.e-10) {
        iter1 = iter2;
        iter2 = 1. / 3. * (a / (iter1 * iter1) + 2 * iter1);
    } ;

    return iter2;
}