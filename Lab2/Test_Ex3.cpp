#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    constexpr double Coins[4] = { 1, 2, 5, 10 };
    int sum, coin, coinCount;

    cout << "Введите сумму в рублях: ";
    cin >> sum;

    while (sum > 0) {
        for (int i = 3; i >= 0; i--) {
            coin = Coins[i];
            coinCount = sum / coin;
            cout << "Монеты по " << coin << " руб - " << coinCount << " шт." << endl;
            sum -= coinCount * coin;
        }
    }
}