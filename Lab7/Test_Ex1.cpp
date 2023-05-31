#include <iostream>
#include <windows.h>
using namespace std;

//using std::cin;
//using std::endl;

struct Time {
    int hours, minutes, seconds;
   
    
    Time subTime(Time t) {

        int hourstot = hours + t.hours;
        int minutestot = minutes + t.minutes;  
        int secondstot = seconds + t.seconds;

        // total number of seconds
        int stot = 3600 * hourstot + 60 * minutestot + secondstot;
       

        // number of hrs, min and sec in stot
        int hrs = stot / 3600;
        int minsec = stot % 3600;
        int min = minsec / 60;
        int sec = minsec % 60;

        return { hrs, min, sec };

    };


    Time diffTime(Time t) {
        int hourstot, minutestot, secondstot;
        int s1, s2;

        s1 = 3600 * hours + 60 * minutes + seconds;
        s2 = 3600 * t.hours + 60 * t.minutes + t.seconds;

        if (s1 >= s2) {
            hourstot = hours - t.hours;
            minutestot = minutes - t.minutes;
            secondstot = seconds - t.seconds;
        }
        else {
            hourstot = t.hours - hours;
            minutestot = t.minutes - minutes;
            secondstot = t.seconds - seconds;
        };

        // total number of seconds
        int sdiff = 3600 * hourstot + 60 * minutestot + secondstot;

        // number of hrs, min and sec in stot
        int hrs = sdiff / 3600;
        int minsec = sdiff % 3600;
        int min = minsec / 60;
        int sec = minsec % 60;

        return { hrs, min, sec };
    };
};

// проверка естественных допустимых значений для часов, минут и секунд

 bool checkFormat(Time t) {
  
    bool check = t.hours >= 0 && t.hours <= 24
        && t.minutes >= 0 && t.minutes <= 60
        && t.seconds >= 0 && t.seconds <= 60;

    return check;

}

 // количество секунд во введенном времени

 int sec(Time t) {
     int s = 3600 * t.hours + 60 * t.minutes + t.seconds;
     return s;
 }

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    Time t1;

    cout << "Введите часы, минуты и секунды 1-го момента времени: "<<endl;
    cin >> t1.hours>> t1.minutes >> t1.seconds;

    // проверка допустимых значений часов, минут и секунд
    if (!checkFormat(t1)) {
        cout << "Вы ввели время в неверном формате" << endl;
        return 0;
    }
    else {
        cout << "Вы ввели время: ";
        cout << t1.hours << " часов, " << t1.minutes << " минут, " << t1.seconds << " секунд" << endl;
    }
       
    // полное число секунд 
    cout << "Полное число секунд  : " << sec(t1) << endl;
    cout  << endl;

    Time t2;

    cout << "Введите часы, минуты и секунды 2-го момента времени: " << endl;
    cin >> t2.hours >> t2.minutes >> t2.seconds;

    // проверка допустимых значений часов, минут и секунд
    if (!checkFormat(t1)) {
        cout << "Вы ввели время в неверном формате" << endl;
        return 0;
    }
    else {
        cout << "Вы ввели время: ";
        cout << t2.hours << " часов, " << t2.minutes << " минут, " << t2.seconds << " секунд" << endl;
    }
  
    // полное число секунд
    cout << "Полное число секунд  : " << sec(t2) << endl;
    cout << endl;

    // Сложение времен
    Time summ = t1.subTime(t2);
    cout << "Результат сложения двух моментов времени :";   
    cout << summ.hours << " час(ов),  " << summ.minutes << " минут(ы), " << summ.seconds << " секунд(ы)." << endl;
   
    // Вычитание времен
    Time diff = t1.diffTime(t2);
    cout << "Результат вычитания двух моментов времени : ";    
    cout << diff.hours << " час(ов),  " << diff.minutes << " минут(ы), " << diff.seconds << " секунд(ы)." << endl;

}

