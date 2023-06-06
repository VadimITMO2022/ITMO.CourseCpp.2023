#include <iostream>
#include <windows.h>
#include "dot.h"
#include "triangle.h"

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Triangle triangle;

    triangle.showSides();
    cout << "Периметр треугольника: " << triangle.getPerimeter() << endl;
    cout << "Площадь треугольника: " << triangle.getArea() << endl;

}