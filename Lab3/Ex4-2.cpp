#include <iostream>
#include <string>
using namespace std;

// алгоритм Евклида определения наибольшего общего делителя

int gcd(int m, int n)
{
	if (n == 0) return m;
	return gcd(n, m % n);
}


int main()
{	
	int m, n, k;
	cout << "Input m:" << endl;
	cin >> m ;
	cout << "Input n:" << endl;
	cin >> n;

	k = gcd(m, n);
	cout << "k=" << k << endl;
		
	return 0;
}

