#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int* Sorting(int*, int);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    const int N = 10;
    int a[N] = { 1, 25, 6, 32, 43, 5, 96, 23, 4, 55 };

    cout << "\n";
    for (int i : a)
        cout << i << " ";
    cout << "\n";

        int* a1 = Sorting(a, N);

        cout << "\n";
        for (int i=0; i<N; i++)
            cout << a1[i] << " ";
        cout << "\n";

        return 0;
  
}



int* Sorting(int* a, int N) {
    int min=0; 
    int buf = 0; 


    for (int i = 0; i < N; i++)
    {
        min = i; 
        for (int j = i + 1; j < N; j++)
            min = (a[j] < a[min]) ? j : min;
        if (i != min)
        {
            buf = a[i];
            a[i] = a[min];
            a[min] = buf;
        }
    }


    return a;
}