#include <iostream>
#include <cassert>

class Stack
{
private:
    int array[10]; // массив - стек 
    int index; // индекс следующего свободного элемента стека

public:

    void reset()
    {
        index = 0;
        for (int i = 0; i < 10; ++i)
            array[i] = 0;
    }

    bool push(int data)
    {
       
        if (index == 10)   // —тек заполнен
            return false;
        else {

            array[index] = data;
            index++; 
            return true;
        }
    }

    int pop()
    {
        // стек пустой
        if (index < 1) {
            std::cout << "The stack is empty" << std::endl;
        }
        else {
            index = index - 1;
            return array[index];
        }
    
    }

    void print()
    {
        std::cout << "( ";
        for (int i = 0; i < index; ++i)
            std::cout << array[i] << " ";
        std::cout << ")\n";
    }
};

int main()
{
    Stack stack;
    stack.reset();
    stack.pop();

    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}