#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // для алгоритма сортировки
#include <cmath>
#include <windows.h>
using namespace std;


class Point {

private:
	double x;
	double y;

public:

Point() {
	x = 0;
	y = 0;
}

Point(double x, double y) {
	this->x = x;
	this->y = y;
}

double get_x() {
	return x;
}

double get_y() {
	return y;
}

double distanceToOrigin()
{
	double dist = sqrt(x * x + y * y);
	return dist;
}

bool operator<(Point& point)
{
	
	double dist1 = distanceToOrigin();
	double dist2 = point.distanceToOrigin();
	bool b = (dist1 < dist2);
	return b;
}

};

ostream& operator<<(ostream& out, Point& point)
{
	double dist = point.distanceToOrigin();
	out << "(" << point.get_x() << "," << point.get_y() << ")" << " distance to center: " << dist << "\n";
	return out;
}



int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::vector<Point> v;
	v.push_back(Point(1, 2));
	v.push_back(Point(10, 12));
	v.push_back(Point(21, 7));
	v.push_back(Point(4, 8));

	std::sort(v.begin(), v.end()); // требуется перегрузка оператора < для  класса Point

	for (auto& point : v)
		std::cout << point << '\n'; // требуется перегрузка оператора << для класса Point
	return 0;
}

