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

    cout << "Введите СНИЛС (9 цифр, каждая цифра на новой строке): " << endl;
    for (int i = 9; i > 0; i--) {
        cin >> numb;
        sum += numb * i;
    }

    cout << "\nВведите контрольное число (двузначное число): " << endl;
    cin >> inputCheckNum;

    if (sum < 100) { checkNum = sum;}
    else if (sum == 100 || sum == 101) { checkNum = 0;}
    else {remainder = sum % 101;
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