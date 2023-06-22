#pragma once
#include "linkiedlistStack.h"
#include <stdexcept>
using namespace std;

template<class T>
linkiedlistStack<T>::linkiedlistStack()
{
	stackTop = nullptr;
}

template <class T>
linkiedlistStack<T>::linkiedlistStack(const linkiedlistStack<T>& otherStack)
{
	stackTop = nullptr;
	copyStack(otherStack);
}

template <class T>
linkiedlistStack<T>::~linkiedlistStack()
{
	initializeStack();
}

template <class T>
void linkiedlistStack<T>::initializeStack()
{
	Node<T>* temp;
	while (stackTop != nullptr)
	{
		temp = stackTop;
		stackTop = stackTop->next;
		delete temp;
	}
}

template <class T>
void linkiedlistStack<T>::push(const T& item)
{
	Node<T>* newNode = new Node<T>; // Specify template argument
	newNode->data = item;
	newNode->next = stackTop;
	stackTop = newNode;
}


template <class T>
void linkiedlistStack<T>::pop()
{
	if (isEmpty()) {
		throw out_of_range("Stack is Empty");
	}
	Node<T>* temp;
	temp = stackTop;
	stackTop = stackTop->next;
	delete temp;
}

template <class T>
T linkiedlistStack<T>::top() const
{
	if (isEmpty()) {
		throw out_of_range("Stack is Empty");
	}
	return stackTop->data;
}

template <class T>
bool linkiedlistStack<T>::isEmpty() const
{
	return (stackTop == nullptr);
}

template <class T>
void linkiedlistStack<T>::copyStack(const linkiedlistStack<T>& otherStack)
{
	Node<T>* newNode, * current, * newCurrent;
	if (otherStack.stackTop != nullptr) {
		stackTop = new Node<T>; // Specify template argument
		stackTop->data = otherStack.stackTop->data;
		stackTop->next = nullptr;
		current = otherStack.stackTop->next;
		newCurrent = stackTop;
		while (current != nullptr)
		{
			newNode = new Node<T>; // Specify template argument
			newNode->data = current->data;
			newNode->next = nullptr;
			newCurrent->next = newNode;
			newCurrent = newNode;
			current = current->next;
		}
	}
	else {
		stackTop = nullptr;
	}
}

