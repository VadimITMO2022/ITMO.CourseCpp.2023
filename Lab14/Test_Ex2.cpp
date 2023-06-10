#include <iostream>
#include <vector>

using namespace std;

template<class T, class T1> void Print(vector<T> data, T1 str)
{

	for(auto it = data.begin(); it < data.end(); it++)
		if (it == data.end() - 1)
			cout << *it;
		else
			cout << *it << str;
}

int main() {
	std::vector<double> data = { 1.1, 2.2, 3.3 };
	Print(data, ", "); // на экране: 1, 2, 3
}

