#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int* make_array(int);
int Summ(int*, int);
int SummPos(int*, int);
int SummNeg(int*, int);
int SummEven(int*, int);
int SummOdd(int*, int);
int minIndex(int*, int); 
int maxIndex(int*, int); 
int Multip(int*, int, int, int);


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
  
        const int n = 10;

       // int mas[n];

       int* mas;
       mas = make_array(n);   // заполнение массива с клавиатуры
       int s = Summ(mas, n);     // Cумма элементов массива         
       int sPos= SummPos(mas, n);    // Cумма положительных элементов массива 
       int sNeg=SummNeg(mas, n);    // Cумма отрицательных элементов массива 
       int sEven=SummEven(mas, n);   // Cумма четных элементов массива 
       int sOdd =SummOdd(mas, n);   // Cумма нечетных элементов массива 

       double av = (double)s / n;  // среднее значение элементов массива

       int imin = minIndex(mas, n);  // индекс минимального элемента массива
       int imax=maxIndex(mas, n);  // индекс максимального элемента массива
        // произведение элементов массива, расположенных между максимальным и минимальным элементами
       int mult = Multip(mas, n, imin, imax);
        

        std::cout << "\nTotal Summ = " << s;   
        std::cout << "\nAverage Value = " << av;
        std::cout << "\nSumm of Positive Elements  = " << sPos;
        std::cout << "\nSumm  of Negative Elements= " << sNeg;
        std::cout << "\nSumm  of Odd Elements= " << sOdd;
        std::cout << "\nSumm of Even Elements = " << sEven;
        std::cout << "\nMinimum array element  = " << mas[imin];
        std::cout << "\nMaximum array element  = " << mas[imax];
        std::cout << "\nMultiplication  = " << mult << endl;

          delete[] mas;
}


// заполнение массива с клавиатуры :

int* make_array(int n) {
    int* mas = new int[n];
    std::cout << "Enter array elements: \n";
    for (int i = 0; i < n; i++)
    {
        std::cout << "mas[" << i << "]=";
        cin >> mas[i];
    }
    return mas;
}



// Cумма элементов массива :

int Summ(int* mas, int n) {

    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += mas[i];
    }

    return s;
}


// Cумма положительных элементов массива :

int SummPos(int* mas, int n) {

    int sPos = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] > 0) {
            sPos += mas[i];
        }       
    }
    return sPos;
}



// Cумма отрицательных элементов массива :

int SummNeg(int* mas, int n) {

    int sNeg = 0;
    for (int i = 0; i < n; i++)
    {

       if (mas[i] < 0) {
            sNeg += mas[i];
        }
       
    }

    return sNeg;
}

// Cумма четных элементов массива :

int SummEven(int* mas, int n) {

    int sEven = 0;
    for (int i = 0; i < n; i++)
    {       
        if (i % 2 == 0) {
            sEven += mas[i];
        }      
    }
    return sEven;
}


// Cумма нечетных элементов массива :

int SummOdd(int* mas, int n) {

    int sOdd = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0) {        
            sOdd += mas[i];
        }
    }
    return sOdd;
}


// индекс минимального элемента массива

int minIndex(int* mas, int n) {

    int imin = 0;
    for (int i = 1; i < n; i++)
    {
        if (mas[i] < mas[imin]) {
            imin = i;
        };

    }
    return imin;
}


// индекс максимального элемента массива

int maxIndex(int* mas, int n) {

    int imax = 0;
    for (int i = 1; i < n; i++)
    {
        if (mas[i] > mas[imax]) {
            imax = i;
        };

    }
    return imax;
}



// произведение элементов массива, расположенных между максимальным и минимальным элементами

int Multip(int* mas, int n, int imin, int imax)  {

    int mult = 1;
    for (int i = min(imin, imax); i <= max(imin, imax); i++)
    {
        mult = mult * mas[i];

    }

    return mult;
}

