#include <iostream>
#include <windows.h>
using namespace std;

bool Prime(int);
int Place(int);


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n;

    cout << "Введите число: \n";
    cin >> n;

    if (!Prime(n)) {
        cout << "Число не является простым";
    }
    else {
        int k = Place(n);

        if (Prime(k)) {
            cout << "Число является суперпростым";
        }
        else {
            cout << "Число является простым, но не является суперпростым";
        }
    }
}


bool Prime(int n) {
    bool prime = true;

    if (n < 2) {
        prime = false;
    }
    else {
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                prime = false;
            }
        }
    }

    return prime;
}

int Place(int n) {
    int j = 0;

    for (int i = 2; i <= n; i++) {
        if (Prime(i)) {
            j++;
        }
    }

    return j;
}

