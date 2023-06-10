#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void sorting(int arr[], int size) {
	int j = 0;
	for (int i = 0; i < size; i++) {
		int x = arr[i];
		for (j = i - 1; j >= 0 && x < arr[j]; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = x;
	}
}



int main()
{
	SetConsoleOutputCP(1251);
	int arr[] = {9,3,17,6,5,4,31,2,12};
	int k1 = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < k1; i++) cout << arr[i] << ";";
	cout << endl;
	sorting(arr, k1);
	for (int i = 0; i < k1; i++) cout << arr[i] << ";";
		
}