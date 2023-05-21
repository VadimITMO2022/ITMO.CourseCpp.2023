#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    double x, y;

    cout << "Введите координаты точки (x,y):\n";
    cin >> x >> y;

    if (x * x + y * y < 9 && y > 0)
        cout << "внутри" << endl;
    else if (x * x + y * y > 9 || y < 0)
        cout << "снаружи" << endl;
    else cout << "на границе" << endl;

}