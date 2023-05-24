#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

double triangleArea(double);
double triangleArea(double, double, double);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int type;
    double a, a1, a2, a3, area;

    cout << "Введите тип треугольника" << endl;
    cout << "равносторонний: 1 " << endl;
    cout << "разносторонний: 2 " << endl;

    cin >> type;

    if (type == 1)
    {
        cout << "Введите длину стороны равностороннего треугольника" << endl;
        cin >> a;
        area = triangleArea(a);
        cout << "Площадь: " << area << endl;
    }
    else if (type == 2)
    {
        cout << "Введите длины сторон разностороннего треугольника" << endl;
        cin >> a1 >> a2 >> a3;
        area = triangleArea(a1, a2, a3);
        cout << "Площадь: " << area << endl;
    }
    else {
        cout << "Введите цифру 1 или 2" << endl;
    };
}
   


double triangleArea(double a) {
    double area = sqrt(3) / 4. * pow(a, 2);
    return area;
}

double triangleArea(double a1, double a2, double a3) {
    double perim = a1 + a2 + a3;
    double p = perim / 2.;
    double area = sqrt(p * (p - a1) * (p - a2) * (p - a3));
    return area;
}
