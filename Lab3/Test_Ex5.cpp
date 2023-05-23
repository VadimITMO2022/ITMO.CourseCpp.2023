#include <iostream>
#include <string> 
#include <windows.h>
using namespace std;

string binaryNumber(int);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n;
    string str;
    cout << "Введите десятичное число: ";
    cin >> n;
    str = binaryNumber(n);
    cout << "Двоичная форма числа: " << str << endl;
}

string binaryNumber(int n) {
    if (n < 2) {
        return to_string(n);
    }
    else {
        return binaryNumber(n / 2) + to_string(n % 2);
    }
}