#ifndef PQUEUE_HEADER
#define PQUEUE_HEADER

#include "LLToolkit.h"

template<class T>
class PriorityQueue{
public:
	PriorityQueue()
	{
		HeadOfQueue = new Node < T >() ;
		TailOfQueue = HeadOfQueue;
	}
	~PriorityQueue();
	void push(T element, unsigned priority);
	void pop();
	T front();
	bool isEmpty();
	void dump();

private:
	Node<T>* HeadOfQueue;
	Node<T>* TailOfQueue;

};

#endif