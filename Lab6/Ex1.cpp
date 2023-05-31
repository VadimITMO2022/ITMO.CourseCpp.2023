#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    double sum = 0;
    int const n = 100;
    double nums[n];

    for (int i = 0; i < n; i++)
    {
        nums[i] = (rand() % 100);
    }

    ofstream out("test.txt", ios::out | ios::binary);
    if (!out) {
        cout << "Файл открыть невозможно\n";
        return 1;
    }
    out.write((char*)nums, sizeof(nums));
    out.close();
   
    ifstream in("test", ios::in | ios::binary);
    if (!in) {
        cout << "Файл открыть невозможно";
        return 1;
    }

    in.read((char*)&nums, sizeof(nums));
    int k = sizeof(nums) / sizeof(double);
    for (int i = 0; i < k; i++)
    {
        sum = sum + nums[i];
        cout << i << "  " << nums[i] << endl;
    }
    cout << "\nsum = " << sum << endl;

    in.close();

    return 0;
}