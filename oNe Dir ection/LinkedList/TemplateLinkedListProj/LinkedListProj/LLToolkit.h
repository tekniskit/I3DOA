#ifndef LLTOOLKIT_HEADER
#define LLTOOLKIT_HEADER

#include <iostream>
#include "Node.hpp"

template<class T>
class LLToolkit {
	// Part 1
	public:
	static void headInsert(Node<T>*& headPtr, T info)
	{
		headPtr = new Node<T>(info, headPtr);
	}

	static void headRemove(Node<T>*& headPtr)
	{
		if (headPtr != nullptr)
		{
			Node<T>* toBeDeletedNode = headPtr;
			headPtr = toBeDeletedNode->next;
			delete toBeDeletedNode;
		}
	}

	static void insert(Node<T>* prevPtr, T info)
	{
		Node<T>* insertionNode = new Node<T>(info, prevPtr->next);
		prevPtr->next = insertionNode;
	}
	static void remove(Node<T>* prevPtr)
	{
		if (prevPtr->next != nullptr)
		{
			Node<T>* toBeDeletedNode = prevPtr->next;
			prevPtr->next = toBeDeletedNode->next;
			delete toBeDeletedNode;
		}
	}

	// Precondition: sourcePtr is the head pointer of a linekd list
	// Postcondition: A pointer to a copy of the linked list is returned. The original list is unaltered.
	// Time Complexity: O(N) or O(SIZE)
	Node<T>* copy(Node<T>* sourcePtr)
	{
		Node<T>* RetNode;
		Node<T>* keepHead;
		for (Node<T>* cursor = sourcePtr; cursor != nullptr; cursor = cursor->next)
		{
			if (cursor == sourcePtr)
			{
				RetNode = new Node<T>(cursor->info);
				keepHead = RetNode<T>;
			}
			else
			{
				insert(RetNode, cursor->info);
				RetNode = RetNode<T>->next;
			}
		}
		return keepHead;
	}

	// part 2
	static void clear(Node<T>*& headPtr)
	{
		for (Node<T>* cursor = headPtr; cursor != nullptr; cursor = cursor->next)
		{
			headRemove(cursor);
		}
	}

	static void print(Node<T>* headPtr)
	{
		for (Node<T>* cursor = headPtr; cursor != nullptr; cursor = cursor->next)
		{
			std::cout << cursor->info << " - ";
		}
		std::cout << "/" << std::endl;
	}

	static void reverse(Node<T>*& headPtr)
	{
		Node<T>* reverseNode<T> = new Node<T>();
		for (Node<T>* cursor = headPtr; cursor != nullptr; cursor = cursor->next)
		{
			if (cursor == headPtr)
			{
				reverseNode<T> = new Node<T>(cursor->info);
			}
			else
			{
				headInsert(reverseNode<T>, cursor->info);
			}
		}
		headPtr = reverseNode<T>;
	}

	Node<T>* split(Node<T>* splitPtr)
	{
		Node<T>* newHead = splitPtr->next;
		splitPtr->next = nullptr;
		return newHead;
	}

	Node<T>* build(T* content, size_t n)
	{
		Node<T>* RetHead = new Node<T>();
		for (size_t i = 1; i <= n; i++)
		{
			if (i == 1)
			{
				RetHead = new Node<T>(content[n - i]);
			}
			else
			{
				headInsert(RetHead, content[n - i]);
			}
		}
		return RetHead;
	}

	static void join(Node<T>*& head1, Node<T>* head2)
	{
		Node<T>* appendPtr;
		for (Node<T>* cursor = head1; cursor != nullptr; cursor = cursor->next)
		{
			if (cursor != nullptr)
			{
				appendPtr = cursor;
			}
		}
		for (Node<T>* cursor = head2; cursor != nullptr; cursor = cursor->next)
		{
			insert(appendPtr, cursor->info);
			appendPtr = appendPtr->next;
		}
	}

	static void rotateLeft(Node<T>*& head)
	{
		int keepNumber = head->info;
		headRemove(head);
		for (Node<T>* cursor = head; cursor != nullptr; cursor = cursor->next)
		{
			if (cursor->next == nullptr)
			{
				insert(cursor, keepNumber);
				cursor = cursor->next;
			}

		}
	}

	static void rotateRight(Node<T>*& head)
	{
		//Node<T>* keepHead = head;
		Node<T>* rememberNode<T> ;
		T keepNumber;
		for (Node<T>* cursor = head; cursor != nullptr; cursor = cursor->next)
		{
			if (cursor->next != nullptr)
			{
				rememberNode<T> = cursor;
			}
			else
			{
				keepNumber = cursor->info;
			}
		}
		headInsert(head, keepNumber);
		remove(rememberNode<T>);
	}

};

#endif