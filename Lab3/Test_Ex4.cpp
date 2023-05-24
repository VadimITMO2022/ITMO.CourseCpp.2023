#include <iostream>
#include <windows.h>
using namespace std;

int series(int);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n, k;

    cout << "Введите число n: ";
    cin >> n;
    k = series(n);
    cout << "Сумма ряда: " << k << endl;
}



int series(int n)
{
    if (n == 1) return 5; // выход из рекурсии
    else return (5 * n + series(n - 1));
}
