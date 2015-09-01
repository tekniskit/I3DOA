#ifndef LLTOOLKIT_HEADER
#define LLTOOLKIT_HEADER

#include "Node.hpp"

namespace LLToolkit {
	// Part 1
	void headInsert(Node*& headPtr, int info);
	void headRemove(Node*& headPtr);
	void insert(Node* prevPtr, int info);
	void remove(Node* prevPtr);

	// Precondition: sourcePtr is the head pointer of a linekd list
	// Postcondition: A pointer to a copy of the linked list is returned. The original list is unaltered.
	// Time Complexity: O(N) or O(SIZE)
	Node* copy(Node* sourcePtr);

	// part 2
	void clear(Node*& headPtr);
	void print(Node* headPtr);
	void reverse(Node*& headPtr);
	Node* split(Node* splitPtr);
	Node* build(int* content, size_t n);
	void join(Node*& head1, Node* head2);
	void rotateLeft(Node*& head);
	void rotateRight(Node*& head);
}

#endif