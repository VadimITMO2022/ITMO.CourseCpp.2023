#include <iostream>
#include<cmath>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "Введите координаты пятиугольника (x,y) \n\n";

    double x1, x2, x3, x4, x5;
    double y1, y2, y3, y4, y5;
    double a, b, area;


    cout << "Введите координаты 1-ой вершины:\n";
    cin >> x1 >> y1;
    cout << "Введите координаты 2-ой вершины:\n";
    cin >> x2 >> y2;
    cout << "Введите координаты 3-ей вершины:\n";
    cin >> x3 >> y3;
    cout << "Введите координаты 4-ой вершины:\n";
    cin >> x4 >> y4;
    cout << "Введите координаты 5-ой вершины:\n";
    cin >> x5 >> y5;


    a = x1 * y2 + x2 * y3 + x3 * y4 + x4 * y5;
    b = x5 * y4 + x4 * y3 + x3 * y2 + x2 * y1;
    area = 0.5 * abs(a - b);

    cout << "Площадь пятиугольника по формуле Гаусса: " << area << endl;
}