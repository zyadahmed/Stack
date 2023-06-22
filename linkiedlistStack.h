#pragma once
template <class T>
struct Node
{
	T data;
	Node<T>* next;
};
template <class T>
class linkiedlistStack
{
public:
	linkiedlistStack();
	linkiedlistStack(const linkiedlistStack<T>& otherStack);
	~linkiedlistStack();
	void push(const T& item);
	void pop();
	T top()const;
	bool isEmpty() const;
	void initializeStack();
private:
	Node<T>* stackTop;
	void copyStack(const linkiedlistStack<T>& otherStack);
};

