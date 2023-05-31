 #include <iostream>
#include <cstring> 
using namespace std;


int main()
{
    string str1, str2, str3, str4;
    long a, b;

    std::cin >> str1 >> str2 >> a >> b;


    if (str2 == "-a") {
        cout << "sum=" << a + b;
    }
    else if (str2 == "-m") {
        cout << "multiplication=" << a * b;
    }
    else {
        cout << "введен неверный флаг";
    }
}

