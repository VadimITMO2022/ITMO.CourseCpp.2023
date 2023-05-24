#include <iostream>
#include <windows.h>
using namespace std;

bool Input(int&, int&);

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int a, b;
    if (Input(a, b) == false) // if(!Input(a,b))
    {
        cerr << "error";
        return 1;
    }
    int s = a + b;
    return 0;
}


bool Input(int& a, int& b) {
    cout << "Введите два четных числа : ";
    cin >> a;
    cin >> b;

    if (a % 2 ==0 && b % 2==0) {
        return true;
    }
    else {
        return false;
    }
}


