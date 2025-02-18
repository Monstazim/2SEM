#pragma once
#include <iostream>
template <typename T>
class Stack
{
private:
	struct Node
	{
		T data;
		Node* next;
	};

	Node* top = nullptr;
	int num = 0;
public:
	void push(const T& value)
	{
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = top;
		top = newNode;
		++num;
	}

	T pop()
	{
		if (top == nullptr)
		{
			std::cerr << "Стек пуст!\n";
		}
		return top->data
	}
};
