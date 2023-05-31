#include <iostream>
#include <windows.h>
using namespace std;

int* transp(int, int[], int);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int a[] = {2, 5, 9, -4, 3, -8, -2, -3, 1, 10, -11 }; // заданный массив элементов
    int kc = sizeof(a) / sizeof(a[0]);  // размерность массива
 
    for (int i = 0; i < kc; i++)
        cout << a[i] << " ";
       cout << endl;

    int b = -8; // выбрали элемент b

    int* c; //Указатель на результирующий массив
    c = transp(kc, a, b); //вызов функции для транспозиции элемента b в массиве a

    for (int i = 0; i < kc; i++)
        cout << c[i] << " ";
    cout << endl;

    delete[]c; //Возврат памяти.
}



int* transp(int kc, int a[], int b) {
    int in;
    int* c = new int[kc];

    // найти индекс элемента массива b
    for (int i = 0; i < kc; i++) {
        if (a[i] == b) {
            in = i;
            break;
        }
    }

    // поместить величину b в начало массива c
    c[0] = b;

    // определить все элементы в массиве c
    for (int i = 1; i< kc; i++) {
        if (i <= in) {
            c[i] = a[i - 1];
        }
        else {
            c[i] = a[i];
        }   
    }

    return c;
}