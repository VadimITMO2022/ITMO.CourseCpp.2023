#include <iostream>
#include <windows.h>
using namespace std;

int addNumders(int);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n, k;

    cout << "Введите число n: ";
    cin >> n;
    k =  addNumders(n);
    cout << "Сумма ряда: " << k << endl;
}



int addNumders(int n)
{
    if (n == 1) return 5; // выход из рекурсии
    else return (5*n + addNumders(n - 1));
}