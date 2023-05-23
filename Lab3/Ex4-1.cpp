#include <iostream>
#include <string>
using namespace std;



int addNumders(int n)
{
	if (n == 1) return 1; // выход из рекурсии
	else return (n + addNumders(n - 1));
}




int main()
{	
	int n;
	int k;
	cout << "Input n:" << endl;
	cin >> n;

	k = addNumders(n);
	cout << "k=" << k << endl;
		
	return 0;
}

