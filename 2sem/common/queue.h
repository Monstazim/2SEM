#pragma once
#include <stdexcept>

using namespace std;

template <typename T>

class Queue
{
private:
	struct Node
	{
		T data;
		Node* next;
	};
	Node* top = nullptr;
	Node* bottom = nullptr;
	int counter = 0;

public:
	void queue(T data)
	{
		Node* newNode= new Node(data);
		if (bottom)
		{
			bottom->next = newNode;
		}
		else
		{
			head = newNode;
		}
		bottom = newNode;
		counter++;
	}


};