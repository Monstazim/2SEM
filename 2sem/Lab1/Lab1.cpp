#include <iostream>
#include <stack.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int newValue;
    Stack<int> Lab1Stack;
    cout << "Введите последовательность чисел" << endl;
    cin >> newValue;
    while (newValue != 0)
    {
        Lab1Stack.push(newValue);
        cin >> newValue;
    }

    int currentValue;
    int sizeOfStack = Lab1Stack.count();
    cout << "Положительные числа последовательности в обратном порядке:" << endl;
    for (int i{ 0 }; i < sizeOfStack; i++)
    {
        currentValue = Lab1Stack.pop();
        if (currentValue > 0)
        {
            cout << currentValue << endl;
        }
    }
}
