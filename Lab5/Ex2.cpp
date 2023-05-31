#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    const int N = 10;
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };
    int min = 0; // для записи минимального значения
    int buf = 0; // для обмена значениями

    cout << "\n";
    for (int i : a)
        cout << i << " ";
    cout << "\n";

        for (int i = 0; i < N; i++)
        {
            min = i; // номер текущей ячейки, как ячейки с минимальным значением
            // в цикле найдем реальный номер ячейки с минимальным значением
            for (int j = i + 1; j < N; j++)
                min = (a[j] < a[min]) ? j : min;
            // перестановка этого элемента, поменяв его местами с текущим
            if (i != min)
            {
                buf = a[i];
                a[i] = a[min];
                a[min] = buf;
            }
        }

        cout << "\n";
        for (int i : a)
            cout << i << " ";
        cout << "\n";
  
}