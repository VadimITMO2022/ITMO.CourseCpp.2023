#include <iostream>
#include <windows.h>
#include "dot.h"
#include "triangle.h"

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Dot* dot1 = new Dot(-4.76, 5.65);
    Dot* dot2 = new Dot(0.5, 3.24);
    Dot* dot3 = new Dot(-2.4, 4.87);
  
    Triangle triangle(dot1, dot2, dot3);

    triangle.showSides();
    cout << "Периметр треугольника: " << triangle.getPerimeter() << endl;
    cout << "Площадь треугольника: " << triangle.getArea() << endl;

}