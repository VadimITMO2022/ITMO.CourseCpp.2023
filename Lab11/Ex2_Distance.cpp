#include <iostream>

class Distance {
     

private:
    int feet;
    float inches;
public:
    const float MTF;
    // конструктор по умолчанию
    Distance() : feet(0), inches(0.0), MTF(3.280833F) { }
    // конструктор с двумя параметрами
    Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) { }
 
    void getdist()
    {
        std::cout << "\nВведите число футов : ";
        std::cin >> feet;
        std::cout << "\nВведите число дюймов : ";
        std::cin >> inches;
    }

    Distance(float meters) : MTF(3.280833F)
    {
        float fltfeet = MTF * meters; // перевод в футы
        feet = int(fltfeet); // число полных футов
        inches = 12 * (fltfeet-feet); // остаток - это дюймы
    }

    void showdist()
    {
        std::cout << feet << "\' - " << inches << "\"\n";
    }
    Distance operator+ (const Distance&) const;

    operator float() const
    {
        float fracfeet = inches / 12;
        fracfeet += static_cast<float>(feet);
        return fracfeet / MTF;
    }
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
    Distance dist2, dist3, dist4;

    Distance dist1 = 2.35F;
    float mtrs;  
    mtrs = static_cast<float>(dist1); 
    mtrs = dist2;

   

}