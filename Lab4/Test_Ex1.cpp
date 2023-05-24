#include <iostream>
#include <windows.h>
using namespace std;

int Myroot(double, double, double, double&, double&);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    double a, b, c;
    double R1, R2;
    int myroot;

    cout << "Введите коэффициенты квадратного уравнения " << "ax^2 + bx + c = 0" << endl;
    cout << "Коэффициент a: "; 
    cin >> a;
    cout << "Коэффициент b: ";
    cin >> b;
    cout << "Коэффициент c: ";
    cin >> c;

    myroot = Myroot(a, b, c, R1, R2);
    if (myroot == -1) {
        cout << "Корней уравнения нет" << endl;
    }
    else if (myroot == 0) {cout << "Корень уравнения один x1 = x2 = " << R1 << endl;
    }
    else {     
        cout << "Корни уравнения " << "x1 = " << R1 << ", x2 = " << R2 << endl;
    }
}

int Myroot(double a, double b, double c, double& R1, double& R2) {
    double D = b * b - 4. * a * c;

    if (D < 0) {     
        return -1;
    }
    else if (D == 0) {
        R1 = (-b + sqrt(D)) / (2 * a);
        return 0;
    }
    else {
        R1 = (-b + sqrt(D)) / (2 * a);
        R2 = (-b - sqrt(D)) / (2 * a);
        return 1;
    }
}