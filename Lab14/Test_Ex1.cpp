#include <iostream>
using namespace std;


template<typename T> T getMean(T arr[], int size) {
    
        T sum = arr[0];
    for (int i = 1; i < size; i++) {
        sum += arr[i];
    }

    T mean = sum / size;
    return mean;
}

int main()
{
    // integer
    int mass1[] = {-3, 4, -2, -8, 11};
    int size1 = sizeof(mass1) / sizeof(int);
    int mean1 = getMean(mass1, size1);
    cout << "int Mean: " <<  mean1 << endl;

    // long
    long mass2[] = { 12367L, 69876L, 98765L, 65434L, 50098L };
    int size2 = sizeof(mass2) / sizeof(long);
    long mean2 = getMean(mass2, size2);
    cout << "long Mean: " << mean2 << endl;

    // double
    double mass3[] = { 1.5, 2.5, 3.5, 4.5, 5.5, 6.67, -9.43 };
    int size3 = sizeof(mass3) / sizeof(double);
    double mean3= getMean(mass3, size3);
    cout << "double Mean: " << mean3 << endl;
    

    // char
    char mass4[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int size4 = sizeof(mass4) / sizeof(char);
    char mean4 = getMean(mass4, size4);
    cout << "char Mean: " << mean4 << endl;
    cout <<  endl;

}
