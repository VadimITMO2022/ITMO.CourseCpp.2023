// перевод длины из класса Distance в метры и обратно 
#include <iostream>
#include <windows.h>
using namespace std;

class Point {
private:
	int x, y;

public:
	Point(){
		x = 0;
		y = 0;
	}

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	int get_x() {
		return x;
	}

	int get_y() {
		return y;
	}

	void showPoint() 
	{
		cout << "(" << get_x() << "," << get_y() << ")" << endl;
	}
	

Point operator+ (Point p)
{
	int xx, yy;

	xx = x + p.x;
	yy = y + p.y;

	Point point(xx, yy);

    return point;	

}

Point operator+ (int n)
{
	int xx, yy;

	xx = x + n;
	yy = y + n;

	Point point(xx, yy);

	return point;

}

Point operator+= (Point pt)
{
	x += pt.get_x();
	y +=  pt.get_y();

	return *this;
}


};


int main ()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	Point pt1, pt2, pt3;

	pt1 = Point(1, 1);
	pt2 = Point(2, 2);
	pt3 = Point();


	pt3 = pt1 + pt2;
	pt3.showPoint();

	pt2 += pt1;
	pt2.showPoint();

	pt3 = pt1 + 5;
	pt3.showPoint();

return 0;
}
