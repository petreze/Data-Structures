#pragma once
#include <iostream>
#include "Node.h"

template <typename T>
class Stack
{
private:
	Node<T>* first;
	size_t size;

	void copy(const Stack<T>& other)
	{

		if (other.first == nullptr)
		{
			this->first = nullptr;
			this->size = 0;
			return;
		}

		this->first = new Node<T>(other.first->data, other.first->next);

		Node<T>* temp1 = this->first;
		Node<T>* temp2 = other.first;

		while (temp2)
		{
			temp1->next = new Node<T>(temp2->next->data, temp2->next->next);
			temp2 = temp2->next;
			temp1 = temp1->next;
		}

		this->size = other.size;		

		/*
		Stack<T> reverse;
		reverse.copyReverse(other);
		this->copyReverse(reverse);
		*/
	}

	void copyReverse(const Stack<T>& other)
	{
		Node<T>* node = other.first;

		for (size_t i = 0; i < other.size(); i++)
		{
			this->push(node->data);
			node = node->next;
		}
	}

	bool isEmpty() const
	{
		return this->first == nullptr;
	}

	void erase()
	{
		for (int i = 0; i <= this->size; i++)
		{
			this->pop();
		}
	}

public:
	Stack()
	{
		this->first = nullptr;
		this->size = 0;
	}

	Stack(const Stack& other)
	{
		this->copy(other);
	}

	Stack<T>& operator=(const Stack<T>& other)
	{
		if (this != &other)
		{
			this->erase();
			this->copy(other);
		}

		return *this;
	}

	~Stack()
	{
		this->erase();
	}

	T& top() const
	{
		if (!isEmpty())
		{
			return this->first->data;
		}
		throw "Empty stack";
	}

	void push(const T& element)
	{
		Node<T>* add = new Node<T>(element, this->first);

		if (add)
		{
			this->first = add;
			this->size++;
		}
	}

	void pop()
	{
		if (!isEmpty())
		{
			Node<T>* remove = this->first;

			this->first = this->first->next;
			delete remove;
			this->size--;
		}
	}

	size_t getSize() const
	{
		return this->size;
	}

	void print() const
	{
		Node<T>* temp = first;
		
		while (temp)
		{
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}

};