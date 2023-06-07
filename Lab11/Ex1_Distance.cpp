#include <iostream>

class Distance {
private:
    int feet;
    float inches;
public:
    // конструктор по умолчанию
    Distance() : feet(0), inches(0.0) { }

    // конструктор с двумя параметрами
    Distance(int ft, float in) : feet(ft), inches(in) { }
 
    void getdist()
    {
        std::cout << "\nВведите число футов : ";
        std::cin >> feet;
        std::cout << "\nВведите число дюймов : ";
        std::cin >> inches;
    }
    void showdist()
    {
        std::cout << feet << "\' - " << inches << "\"\n";
    }

    Distance operator+ (const Distance&) const;
};

Distance Distance::operator+ (const Distance& d2) const
{
    int f = feet + d2.feet;
    float i = inches + d2.inches;
    if (i >= 12.0)
    {
        i -= 12.0;
        f++;
    }
    return Distance(f, i);
}

int main() {
    
    int ft1 = 5;
    float in1 = 8;
    Distance dist1 = Distance(ft1, in1);
    std::cout << "\ndist1 =  ";
    dist1.showdist();

    int ft2 = 3;
    float in2 = 11;
    Distance dist2 = Distance(ft2, in2);
    std::cout << "\ndist2 =  ";
    dist2.showdist();

    int ft3 = 5;
    float in3 = 10;
    Distance dist3 = Distance(ft3, in3);
    std::cout << "\ndist3 =  ";
    dist3.showdist();

    Distance dist4 = dist1 + dist2 + dist3;
//    Distance dist4 = dist1 + dist2;
    std::cout << "\ndist4 =  ";
    dist4.showdist();
}