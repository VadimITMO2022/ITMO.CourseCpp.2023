#include <iostream>
#include <windows.h>
using namespace std;


void swap(int*, int*);
void swap(int&, int&);
void print(int, int);


int main()
{

	int x = 5, y = 10;
	print(x, y);
	swap(&x, &y);
	print(x, y);
	swap(x, y);
	print(x, y);

}


void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void swap(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void print(int x, int y)
{
	cout << "x = " << x << "; y = " << y << endl;
}