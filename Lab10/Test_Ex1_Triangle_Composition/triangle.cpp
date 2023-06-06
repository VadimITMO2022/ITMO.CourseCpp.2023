#include <iostream>
#include "triangle.h"

using namespace std;


Triangle::Triangle() {
	dot1 = new Dot(-4.76, 5.65);
	dot2 = new Dot(0.5, 3.24);
	dot3 = new Dot(-2.4, 4.87);
}

// посчитать и вывести длины сторон треугольника

void Triangle::showSides()  {

	string str = "Длины сторон треугольника: ";
	double a = dot1->distanceTo(*Triangle::dot2);
	double b = dot2->distanceTo(*Triangle::dot3);
	double c = dot3->distanceTo(*Triangle::dot1);

	std::cout << str << a << ", " << b << ", " << c << std::endl;
}

// посчитать периметр треугольника

double Triangle::getPerimeter()  {

	double a = dot1->distanceTo(*Triangle::dot2);
	double b = dot2->distanceTo(*Triangle::dot3);
	double c = dot3->distanceTo(*Triangle::dot1);

	double perim = a + b + c;  //  периметр треугольника

	return perim;
}

// посчитать площадь треугольника

double Triangle::getArea() {

	// длины сторон треугольника
	double a = dot1->distanceTo(*Triangle::dot2);
	double b = dot2->distanceTo(*Triangle::dot3);
	double c = dot3->distanceTo(*Triangle::dot1);
	
	double p = (a + b + c)/2.;  // полупериметр

	double A = sqrt(p * (p -a) * (p - b) * (p - c));  //  площадь треугольника по формуле Герона

	return A;
}