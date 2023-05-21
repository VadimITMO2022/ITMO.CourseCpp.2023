#include <iostream>
#include <windows.h>
using namespace std;

bool isPrimeNumber(int n) {
    bool prime = true;

    if (n < 2) {
        prime = false;
    } 
    else {
        for (int num = 2; num <= n / 2; num++) {
            if (n % num == 0) {
                prime = false;
            }
        }
    }

    return prime;
}

int getNumber(int n) {
    int j = 0;

    for (int i = 2; i <= n; i++) {
        if (isPrimeNumber(i)) {
            j++;
        }
    }

    return j;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n;

    cout << "Введите число: \n";
    cin >> n;

    if (!isPrimeNumber(n)) {
        cout << "Число не является простым";
    }
    else {
        int nNumb = getNumber(n);

        if (isPrimeNumber(nNumb)) {
            cout << "Число является суперпростым";
        }
        else {
            cout << "Число является простым, но не является суперпростым";
        }
    }
}