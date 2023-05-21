#include <iostream>
#include <windows.h>
#include <math.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    using namespace std;

    int k = 40, m = 60, s=0;

    for (int i = 1;i <= 100;i++)
    {
        if ((i > k) && (i < m))
            continue;
        s += i;
    }

    cout << "s= " << s << endl;
}




