#include <iostream>
#include <stdio.h>;
struct Stack
{ 
	int Data;
	Stack* next;
};
void s_push(Stack** top, int D) 
{
	Stack* q; 
	q = new Stack(); 
	q->Data = D; 
	if (top == NULL) 
	{ 
		*top = q;
	}
	else 
	{
		q->next = *top; 
		*top = q; 
	}
}
int main()
{
    std::cout << "Hello World!\n";
}
