#include <iostream>
#include <ctime>
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    using namespace std;

    char op;

    cout << "Сделай свой выбор, собери авто свой мечты: ";
    cin >> op;

    switch (op)
    {
    case 'S':
        cout << "Радио играть должно\n";
     /*   cout << "Колеса круглые\n";
        cout << "Мощный двигатель\n";
        break;
        */
    case 'V':
        cout << "Кондиционер хочу\n";
        /*  cout << "Радио играть должно\n";
        cout << "Колеса круглые\n";
        cout << "Мощный двигатель\n";
        break;
        */
    default:
        cout << "Колеса круглые\n";
        cout << "Мощный двигатель\n";
    }
}