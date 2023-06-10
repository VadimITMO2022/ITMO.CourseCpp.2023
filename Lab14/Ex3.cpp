#include <iostream>
#include <tuple>
#include <vector>
#include <windows.h>
using namespace std;

// два варианта объ€влени€ шаблонного класса TuplePrinter, 
// в котором определите одну статическую функцию с именем print.
// Ёта реализаци€ называетс€ рекурсивным экземпл€ром шаблона :

template<class Tuple, std::size_t N>
struct TuplePrinter {
	static void print(const Tuple& t)
	{
		TuplePrinter<Tuple, N - 1>::print(t);
		cout << ", " << get<N - 1>(t);
	}
};


template<class Tuple>
struct TuplePrinter<Tuple, 1> {
	static void print(const Tuple& t)
	{
		cout << get<0>(t);
	}
};



// функци€ printTuple() вызывает функцию - член print() класса TuplePrinter :

template<class... Args>
void printTuple(const tuple<Args...>& t)
{
	cout << "(";
	TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
	cout << ")" << endl;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	vector<string> v1{ "one", "two", "three", "four", "five", "six" };
	vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
	vector<float> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

	auto t1 = std::make_tuple(v1[0], v1[1], v3[0]);
	printTuple(t1);

	auto t2 = std::make_tuple(v1[0], v1[1], v2[1], v3[0], v3[1]);
	printTuple(t2);

	auto t3 = make_tuple(v2[2], v3[4], v1[3], v3[4]);
	printTuple(t3);

	auto t4 = make_tuple(v1[0], v1[1], v2[5], v3[4], v2[2], v1[5]);
	printTuple(t4);

	return 0;
}
