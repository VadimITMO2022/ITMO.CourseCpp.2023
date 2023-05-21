#include <iostream>
#include <windows.h>
#include <math.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    using namespace std;

        srand(time(NULL)); 
        int a, b, c; 
            int k = 0, n = 10; 
        for (int i = 1;i <= n;i++) { // инициализация операндов случайными числами от 1 до 101
            a = rand() % 10 + 1;
            b = rand() % 10 + 1;

            cout << a << " * " << b << " = ";
            cin >> c;
            if (a * b != c)
            {
                k++; // операция «инкремент», аналогично: k = k + 1
                cout << "Error! ";
                cout << a << " * " << b << " = " << a * b << endl;
            }
        }
        cout << "Count error: " << k << endl;
        return 0;
    }




