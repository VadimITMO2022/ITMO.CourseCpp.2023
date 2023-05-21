#include <iostream>
#include <ctime>
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    using namespace std;

 
    int numberShots = 0, score = 0, score0;
    double x, y, radius;
    string level;
  

    do {
        std::cout << "Input the coordinates: ";
        cin >> x >> y;
 
        radius = sqrt( x * x + y * y );

        if (radius <= 1) {
            score0 = 10;
        }
        else if (1 < radius && radius <= 2) {
            score0 = 5;
        }
        else if (2 < radius && radius <= 3) {
            score0 = 1;
        }
        else 
        {
            score0 = 0;
        }
        
        score = score + score0;

        numberShots++;

        cout << "Score: " << score0 << 
                " Total score: "<< score << 
                " Number of shots: " << numberShots << endl;

    } while (score <50);

    if (numberShots <= 5) {
        level = "снайпер";
    }
    else if (numberShots <= 10) {
        level = "стрелок";
    }
    else {
        level = "новичок";
    }

    cout << "\nКоличество выстрелов: " << numberShots  
        << ". Уровень стрельбы: " << level << endl;
}