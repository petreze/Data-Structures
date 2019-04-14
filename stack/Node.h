#pragma once
#include <iostream>

template <typename T>
struct Node
{
	T data;
	Node<T>* next;

	Node(const T& _data, Node<T>* _next = nullptr) : data(_data), next(_next) {}

};