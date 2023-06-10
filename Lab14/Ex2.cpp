#include <iostream>
#include <windows.h>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

template<class Tuple>
void printTupleOfFive(Tuple t)	
{
	cout << "("
		<< std::get<0>(t) << ", "
		<< std::get<1>(t) << ", "
		<< std::get<2>(t) << ", "
		<< std::get<3>(t) << ", "
		<< std::get<4>(t) << ")" << endl;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	vector<string> v1={ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

	auto t0 = make_tuple(v1[0], v2[2], v3[4], v1[3], v3[4]);
	printTupleOfFive(t0);

	auto t3 = make_tuple(v1[0], v1[1], v2[5], v3[4], v2[2]);
	printTupleOfFive(t3);

	return 0;
}
