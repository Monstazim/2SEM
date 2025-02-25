#pragma once

using namespace std;
/// <summary>
/// Объявление шаблона
/// Template Declaration
/// </summary>
/// /// 
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
	int counter = 0;

public:
		/// <summary>
	/// Функция, которая добавляет элемент на вершину стека
	/// A function that adds an element to the top of the stack
	/// </summary>
	void push(const T& value)
	{
		Node* newData = new Node();
		newData->data = value;
		newData->next = top;
		top = newData;
		++counter;
	}
	
	/// <summary>
	/// Функция, которая извлекает элемент с вершины стека и возвращает его значение
	/// A function that retrieves an element from the top of the stack and returns its value
	/// </summary>
	T pop()
	{
		if (top != nullptr)
		{
			T TopValue = top->data;
			top = top->next;
			--counter;
			return TopValue;
		}
		else
		{
			cerr << "Stack is empty" << endl;
		}
	}

	/// <summary>
	/// Функция, которая возвращает элемент находящийся на вершине стека
	/// A function that returns an element located at the top of the stack
	/// </summary>
	T peek()
	{
		if (top != nullptr)
		{
			return top->data;
		}
		else
		{
			cerr << "Stack is empty" << endl;
		}
	}

	/// <summary>
	/// Функция, которая возвращает количество элементов в коллекции
	/// A function that returns the number of items in a collection
	/// </summary>
	int count()
	{
		return counter;
	}

	/// <summary>
	/// Функция, которая удаляет все элементы из коллекции
	/// A function that removes all items from a collection
	/// </summary>
	void clear()
	{
		while (top != nullptr)
		{
			Node* temp = top;
			top = top->next;
			delete temp;
		}
		counter = 0;
	}
};
