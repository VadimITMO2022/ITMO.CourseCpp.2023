#include <iostream>
#include <windows.h>
#include <string>
using namespace std;



struct Square {
    double S1;
    double S2;
};

Square Myroot(double, double, double, int&);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    double a, b, c;
    Square square;
    int type;

    cout << "Input the coefficients of squired equation " << "ax^2 + bx + c = 0" << endl;
    cout << "Coefficient a: "; 
    cin >> a;
    cout << "Coefficient b: ";
    cin >> b;
    cout << "Coefficient c: ";
    cin >> c;

    square = Myroot(a, b, c, type);
    if (type == -1) {
        cout << "There are no roots of equation" << endl;
    }
    else if (type == 0) {cout << "One root of the equation x1 = x2 = " << square.S1 << endl;
    }
    else {     
        cout << "The roots of equation are " << "x1 = " << square.S1 << ", x2 = " << square.S2 << endl;
    }
}

Square Myroot(double a, double b, double c, int& types) {
    Square square;

    double D = b * b - 4. * a * c;

    if (D < 0) {     
        types = -1;
    }
    else if (D == 0) {
        square.S1 = (-b + sqrt(D)) / (2 * a);
        types = 0;
    }
    else {
        square.S1 = (-b + sqrt(D)) / (2 * a);
        square.S2 = (-b - sqrt(D)) / (2 * a);
        types = 1;
    }

    return square;
}