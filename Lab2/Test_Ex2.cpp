#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int sum = 0;
    int Number1, Number2;
    int num, rem;

    cout << "Введите СНИЛС (9 цифр, каждая цифра на новой строке): " << endl;
    for (int i = 9; i > 0; i--) {
        cin >> num;
        sum += num * i;
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
    if (Number1 == Number2) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}