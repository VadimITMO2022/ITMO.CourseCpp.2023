#include <iostream>
#include <windows.h>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

// typedef tuple<string, int, double> Tuple;
using Tuple = tuple<string, int, double>;
using Tuple1 = tuple<string, int>;

Tuple1 newfunc1(string s, int a, double d)
{
	string s1 = s + " Привет";
	return make_tuple(s1, a - 18);
}

Tuple newfunc(string s, int a, double d)
{
	string s1 = s + " Привет";
	return make_tuple(s1, a-18, d * 10+88.76);
}

Tuple funtup(string s, int a, double d)
{
	s.append("!");
	return make_tuple(s, a, d * 10);
}

void printTupleOfTwo(Tuple1 t)
// void printTupleOfThree(tuple<string, int, double> t)
{
	cout << "("
		<< std::get<0>(t) << ", "
		<< std::get<1>(t) <<  ")" << endl;
}

void printTupleOfThree(Tuple t)
// void printTupleOfThree(tuple<string, int, double> t)
{
	cout << "("
		<< std::get<0>(t) << ", "
		<< std::get<1>(t) << ", "
		<< std::get<2>(t) << ")" << endl;
}

int main()
{
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);

		vector<string> v1{ "one", "two", "three", "four", "five", "six" };
		vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
		vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

		auto t0 = make_tuple(v1[0], v2[0], v3[0]);
		printTupleOfThree(t0);

		auto t1 = funtup(v1[1], v2[1], v3[1]);
		printTupleOfThree(t1);

		auto t2 = newfunc(v1[2], v2[2], v3[2]);
		printTupleOfThree(t2);

		auto t3 = newfunc1(v1[3], v2[3], v3[3]);
		printTupleOfTwo(t3);

		return 0;
	}
