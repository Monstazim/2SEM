#include <iostream>
#include <stack.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int NewValue;
    Stack<int> Lab1Stack;
    cout << "Введите последовательность чисел" << endl;
    cin >> NewValue;
    while (NewValue != 0)
    {
        Lab1Stack.push(NewValue);
        cin >> NewValue;
    }

    int CurrentValue;
    int SizeOfStack = Lab1Stack.count();
    cout << "Положительные числа последовательности в обратном порядке:" << endl;
    for (int i{ 0 }; i < SizeOfStack; i++)
    {
        CurrentValue = Lab1Stack.pop();
        if (CurrentValue > 0)
        {
            cout << CurrentValue << endl;
        }
    }
}
