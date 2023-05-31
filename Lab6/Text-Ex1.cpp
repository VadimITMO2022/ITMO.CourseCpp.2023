#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    char verses[1000];

    cout << "Input verses (not more than 1000 symbols). When you have done put symbol *" << endl;

    cin.getline(verses, 1000, '*');
    cout << endl;

    cout << "Вы ввели: \n" << verses << endl;

    ofstream fileVerses("verses.txt");
    fileVerses << verses << endl;
    fileVerses.close();

    return 0;
}