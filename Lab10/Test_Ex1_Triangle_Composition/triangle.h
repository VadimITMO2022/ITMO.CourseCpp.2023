#pragma once
#include <iostream>
#include "dot.h"

class Triangle {
private:
	Dot* dot1;
	Dot* dot2;
	Dot* dot3;

public:
	Triangle();
	void showSides();
	double getPerimeter();
	double getArea();
};