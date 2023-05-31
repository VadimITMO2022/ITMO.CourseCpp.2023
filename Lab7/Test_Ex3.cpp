#include <iostream>
#include <windows.h>
#include <tuple>
using namespace std;


using Tuple = tuple<int,double, double>;

Tuple Myroot(double,double, double);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    double a, b, c;
 

    cout << "Input the coefficients of squired equation " << "ax^2 + bx + c = 0" << endl;
    cout << "Coefficient a: ";
    cin >> a;
    cout << "Coefficient b: ";
    cin >> b;
    cout << "Coefficient c: ";
    cin >> c;

    Tuple root = Myroot(a, b, c);
    if (get<0>(root) == -1) {
        cout << "There are no roots of equation" << endl;
    }
    else if (get<0>(root) == 0) {cout << "One root of the equation x1 = x2 = " << get<1>(root) << endl;
    }
    else {     
        cout << "The roots of equation are " << "x1 = " << get<1>(root) << ", x2 = " << get<2>(root) << endl;
    }
}


Tuple Myroot(double a, double b, double c) {
    double S1, S2;
    int type;

    double D = b * b - 4. * a * c;

    if (D < 0) {
        type = -1;
    }
    else if (D == 0) {
        S1 = (-b + sqrt(D)) / (2 * a);
        type = 0;
    }
    else {
        S1 = (-b + sqrt(D)) / (2 * a);
        S2 = (-b - sqrt(D)) / (2 * a);
        type = 1;
    }

    return make_tuple(type,S1, S2);
}

