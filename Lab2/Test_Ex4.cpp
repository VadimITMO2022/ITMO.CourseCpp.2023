
#include <iostream>
#include <ctime>
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    using namespace std;


    int shots = 0, score = 0, score0;
    double x, y, r;
    string level;
    int a=0, b=100;
    double x0, y0, x1, y1;


    do {
        cout << "Input the coordinates on the target : ";
        cin >> x >> y;

// (x0,y0) random coordinates of center of the target
 
        // случайные числа в интервале [0;100]
        x1 = a + rand() % (b - a + 1);
        y1 = a + rand() % (b - a + 1);
      
        // случайные числа в интервале [0;1]
        x0 = 0.01 * x1;
        y0 = 0.01 * y1;

        x = x - x0;
        y = y - y0;

        r = sqrt(x * x + y * y);


        if (r <= 1) {
            score0 = 10;
        }
        else if (1 < r && r <= 2) {
            score0 = 5;
        }
        else if (2 < r && r <= 3) {
            score0 = 1;
        }
        else
        {
            score0 = 0;
        }

        score += score0;

        shots++;

        cout << "Score: " << score0 <<
            " Total score: " << score <<
            " Number of shots: " << shots << endl;
        cout << "x0= " << x0 << ", y0= " << y0 << endl;

    } while (score < 50);

    if (shots <= 5) {
        level = "снайпер";
    }
    else if (shots <= 10) {
        level = "стрелок";
    }
    else {
        level = "новичок";
    }

    cout << "\nКоличество выстрелов: " << shots
        << ". Уровень стрельбы: " << level << endl;
}