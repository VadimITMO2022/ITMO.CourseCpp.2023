#include <iostream>

using namespace std;

class A {
private:
    int dim;
    int* array;
public:
    A() {
        dim = 0;
        array = {};
    }
    

    A(int size) {
        dim = size;
        array = new int[size];
        for (int i = 0;i < size;i++) {
            array[i] = 0;
        }
    }
 
 
    int size()const {
        int size1 = 0;
        for (int i = 0;i < dim ;i++) {
            size1++;
        }
        return size1;
    }
 
 
    A& operator=(const A& arr) {
        dim = arr.dim;
        array = new int[dim];
        for (int i = 0; i < dim; i++)
            array[i] = arr.array[i];
        return *this;
    }
        
 
    const int& operator[] (int& i)const {
        return array[i];
    }



};


int main()
{

        A a1;
        A a2(10); //10 Ц размер массива 
        A a3 = a2;
        a1 = a3;
        a2 = A(20);
        const A a4(5);
        for (int i = 0; i < a2.size(); i++)
        {
            cout << i << "  " << a4[i] << endl; 
        };   
}
