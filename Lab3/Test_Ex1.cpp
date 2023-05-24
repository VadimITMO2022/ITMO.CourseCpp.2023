#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    int sum = 0;
    int Number1, Number2;
    int rem, num;
    char str;

    cout << "Введите СНИЛС (9 цифр): " << endl;

    int i = 9;
    while (i > 0) {
        cin >> str;
        if (str == '1' || str == '2' || str == '3' ||
            str == '4' || str == '5' || str == '6' ||
            str == '7' || str == '8' || str == '9')
        {
            num = str - '0';
            sum += num * i;
            i = i - 1;
        }
        else if (str == ' ' || str == '-') {
            continue;
        }
        else {
            cout << "The SNILS number you input is false" << endl;
            return 0;
        }
    }

    cout << "\nВведите контрольное (двузначное) число: " << endl;
    cin >> Number1;

    if (sum < 100) { Number2 = sum; }
    else if (sum == 100 || sum == 101) { Number2 = 0; }
    else {
        rem = sum % 101;
        if (rem < 100) { Number2 = rem; }
        else { Number2 = 0; }
    }

    cout << "\nКонтрольное число для этого СНИЛСа должно быть: " << Number2 << "\n" << endl;


    cout << "Результат проверки: " << endl;
    if (Number2 == Number1) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}