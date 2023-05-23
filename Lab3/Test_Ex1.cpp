#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    //Формат ввода СНИЛС: 1 2 3 4 5 6 7 8 9 00

 //   int num;
    int sum = 0;
    int inputCheckNum, checkNum;
    int remainder;
    int numb;
    char str;

    cout << "Введите СНИЛС (9 цифр): " << endl;

    int i = 9;
    while (i >0 ) {
        cin >> str;
        if (str == '1' || str == '2' || str == '3' ||
            str == '4' || str == '5' || str == '6' ||
            str == '7' || str == '8' || str == '9')
        {
            numb = str - '0';
            sum += numb * i;
            cout << numb << "  "  << numb*i << "  " << sum<< endl;
            i = i - 1;
        }
        else if(str == ' ' || str == '-') {
            continue;
        }
        else {
            cout << "The SNILS number you input is false" << endl;
            return 0;
        } 
    }

    cout << "\nВведите контрольное число (двузначное число): " << endl;
    cin >> inputCheckNum;

    if (sum < 100) { checkNum = sum; }
    else if (sum == 100 || sum == 101) { checkNum = 0; }
    else {
        remainder = sum % 101;
        if (remainder < 100) { checkNum = remainder; }
        else { checkNum = 0; }
    }

    cout << "\nКонтрольное число для этого СНИЛСа должно быть: " << checkNum << "\n" << endl;


    cout << "Результат проверки: " << endl;
    if (checkNum == inputCheckNum) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}