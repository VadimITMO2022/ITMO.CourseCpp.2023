#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
  
        const int n = 10;

        int mas[n];

 // заполнение массива с клавиатуры :
        for (int i = 0; i < n; i++)
        {
            cout << "mas[" << i << "]=";
            cin >> mas[i];
        }

       
// Определите сумму элементов массива :
        int s = 0, sPos = 0, sNeg=0, sEven=0, sOdd=0;
        for (int i = 0; i < n; i++)
        {
            s += mas[i];

            if (mas[i] > 0) {
                sPos += mas[i];
            }
            else if (mas[i] < 0) {
                sNeg += mas[i];
            }

            if (i % 2 == 0) {
                sEven += mas[i];
            }
            else {
                sOdd += mas[i];
            }
        }

       

// среднее значение элементов массива
        int av = s / n;


 // минимальный элемент массива
        int imin = 0;
        for (int i = 1; i < n; i++)
        {
            if (mas[i] < mas[imin]) { 
                imin = i;
            };
            
        }

       

        // минимальный элемент массива
        int imax = 0;
        for (int i = 1; i < n; i++)
        {
            if (mas[i] > mas[imax]) {
                imax = i;
            };

        }

        // произведение элементов массива, расположенных 
        // между максимальным и минимальным элементами
        int mult=1;
        for (int i = imin; i < imax+1; i++)
        {
            mult = mult * mas[i];

        }

        cout << "\nTotal Summ = " << s;   
        cout << "\nAverage Value = " << av;
        cout << "\nPositive Summ  = " << sPos;
        cout << "\nNegative Summ  = " << sNeg;
        cout << "\nOdd Summ  = " << sOdd;
        cout << "\nEven Summ  = " << sEven;
        cout << "\nMinimum array element  = " << mas[imin];
        cout << "\nMaximum array element  = " << mas[imax];
        cout << "\nMultiplication  = " << mult;

}