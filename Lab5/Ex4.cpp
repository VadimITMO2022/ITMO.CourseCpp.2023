#include <iostream>
#include <windows.h>

using namespace std;

void show_array(const int Arr[],const int N)
{
	for (int i = 0; i < N; i++)
		cout << Arr[i] << " ";
	cout << "\n";
}

bool from_min(const int a, const int b)
{
	return a > b;

}

bool from_max(const int a, const int b)
{
	return a < b;
}

void bubble_sort(int Arr[], const int N, bool (*compare)(int a, int b))
{
	for (int i = 1;i < N;i++)
	{
		for (int j = 0;j < N - 1;j++)
		{
			if ((*compare)(Arr[j], Arr[j + 1])) swap(Arr[j], Arr[j + 1]);
		}
	}
}


int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int my_choose = 0;
	int N;

	cout << "Введите размерность массива:" << endl;
	cin >> N;
	int* myArray = new int[N];

	cout << "Введите элементы массива:"  << endl;


	for (int i = 0; i < N; i++) {
		cin >> myArray[i];	// Заполнение массива	
	}
	cout << endl;


	cout << "Начальные данные: ";
	show_array(myArray, N);
	cout << "\n";

	cout  << "1. Sort by increase\n";
	cout << "2. Sort by decrease\n";
	cin >> my_choose;
	

	switch (my_choose)
	{
	case 1: bubble_sort(myArray, N, from_min); break;
	case 2: bubble_sort(myArray, N, from_max); break;
	default: cout << "\rUnknown action ";
	}

	show_array(myArray, N);

	delete[] myArray;

	return 0;
}



