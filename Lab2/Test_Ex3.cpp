#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int Coins[4] = { 1, 2, 5, 10 };
    int n, coin, number;

    cout << "Введите денежную сумму: ";
    cin >> n;
    cout << "\n";

    cout << "Монеты: "  << endl;
    while (n > 0) {
        for (int i = 3; i >= 0; i--) {
            coin = Coins[i];
            number = n / coin;
            cout << coin << " руб - " << number << " шт." << endl;
            n -= number * coin;
        }
    }
}