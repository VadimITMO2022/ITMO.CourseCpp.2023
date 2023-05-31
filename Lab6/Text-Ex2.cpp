
#include <iostream>
#include <fstream>
#include <windows.h>
#include <algorithm>
using namespace std;

int* max_vect(int, int[], int[]);


int main()
{
    int a[] = { 1,2,3,4,5,6,7,2 };
    int b[] = { 7,6,5,4,3,2,1,3 };
    int kc = sizeof(a) / sizeof(a[0]); //Количество элементов массива
    int* c; //Указатель на результирующий массив

    c = max_vect(kc, a, b); //вызов функции для создания массива
    for (int i = 0;i < kc; i++) //Вывод результата.
        cout << c[i] << " ";
    cout << endl;

    // запись в файл массива с
    ofstream file("TwoArrays.txt");
    for (int i = 0; i < kc; i++) {
        file << c[i] << " ";
    }
    file << "\n";
 
    // отсортированный массив
    sort(c, c + kc);

    // запись в файл отсортированного массива с
    for (int i = 0; i < kc; i++) {
        cout << c[i] << " ";
        file << c[i] << " ";
    }

    file.close();


    delete[]c; //Возврат памяти.
}


int* max_vect(int kc, int a[], int b[]) {
    int* c = new int[kc];

    for (int i = 0; i < kc; i++) {
        if (a[i] > b[i]) {
            c[i] = a[i];
        }
        else {
            c[i] = b[i];
        }
    }

    return c;
}





