#include <iostream>
#include <string>
using namespace std;


long double firBinSearch(double a, int n)
{
	double L = 0;
	double R = a;
	while (R - L > 1e-10)
	{
		double M = (L + R) / 2;
		if (pow(M, n) < a)
		{
			L = M;
		}
		else
		{
			R = M;
		}
	}
	return R;
}

int main()
{
	double a, R, T;
	int n;
	cout << "Input a:" << endl;
	cin >> a;
	
	cout << "Input n:" << endl;
	cin >> n;
 	R  = firBinSearch(a, n);
	cout << "R =" << R << endl;
	T = pow(R,n) ;
	cout << "a= " << T << endl;
	
	return 0;
}

