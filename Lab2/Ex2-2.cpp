#include <iostream>
#include <windows.h>
#include <math.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    using namespace std;

    int a, b, temp;
   
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
 // С помощью цикла с предусловием реализуйте алгоритм Евклида :
    while (a != b)
    {
        if (a > b)
            a -= b; // аналогично выражению a = a - b
        else
            b -= a;
        cout << "a = " << a << " b = " << b << endl;
    }
   
        cout << "НОД = " << a << endl;


}

