#include "LLToolkit.h"
#include <iostream>
// Part 1

namespace LLToolkit {

void headInsert(Node*& headPtr, int info)
{
	headPtr = new Node(info, headPtr);
}

void headRemove(Node*& headPtr)
{
	if (headPtr != nullptr)
	{
		Node* toBeDeletednode = headPtr;
		headPtr = toBeDeletednode->next;
		delete toBeDeletednode;
	}
}

void insert(Node* prevPtr, int info)
{
	Node* insertionNode = new Node(info, prevPtr->next);
	prevPtr->next = insertionNode;
}
void remove(Node* prevPtr)
{
	if (prevPtr->next != nullptr)
	{
		Node* toBeDeletednode = prevPtr->next;
		prevPtr->next = toBeDeletednode->next;
		delete toBeDeletednode;
	}
}

// Precondition: sourcePtr is the head pointer of a linekd list
// Postcondition: A pointer to a copy of the linked list is returned. The original list is unaltered.
// Time Complexity: O(N) or O(SIZE)
Node* copy(Node* sourcePtr)
{
	Node* RetNode = new Node();
	Node* keepHead = new Node();
	for (Node* cursor = sourcePtr; cursor != nullptr; cursor = cursor->next)
	{
		if (cursor == sourcePtr)
		{
			RetNode = new Node(cursor->info);
			keepHead = RetNode;
		}
		else
		{
			insert(RetNode, cursor->info);
			RetNode = RetNode->next;
		}
	}
	return keepHead;
}

// part 2
void clear(Node*& headPtr)
{
	for (Node* cursor = headPtr; cursor != nullptr; cursor = cursor->next)
	{
		headRemove(cursor);
	}
}

void print(Node* headPtr)
{
	for (Node* cursor = headPtr; cursor != nullptr; cursor = cursor->next)
	{
		std::cout << cursor->info << " - ";
	}
	std::cout << "/" << std::endl;
}

void reverse(Node*& headPtr)
{
	Node* reversenode = new Node();
	for (Node* cursor = headPtr; cursor != nullptr; cursor = cursor->next)
	{
		if (cursor == headPtr)
		{
			reversenode = new Node(cursor->info);
		}
		else
		{
			headInsert(reversenode, cursor->info);
		}
	}
	headPtr = reversenode;
}

Node* split(Node* splitPtr)
{
	Node* newHead = splitPtr->next;
	splitPtr->next = nullptr;
	return newHead;
}

Node* build(int* content, size_t n)
{
	Node* RetHead = new Node();
	for (size_t i = 1; i <= n; i++)
	{
		if (i == 1)
		{
			RetHead = new Node(content[n - i]);
		}
		else
		{
			headInsert(RetHead, content[n - i]);
		}
	}
	return RetHead;
}

void join(Node*& head1, Node* head2)
{
	Node* appendPtr = new Node();
	for (Node* cursor = head1; cursor != nullptr; cursor = cursor->next)
	{
		if (cursor != nullptr)
		{
			appendPtr = cursor;
		}
	}
	for (Node* cursor = head2; cursor != nullptr; cursor = cursor->next)
	{
		insert(appendPtr, cursor->info);
		appendPtr = appendPtr->next;
	}
}

void rotateLeft(Node*& head)
{
	int keepNumber = head->info;
	headRemove(head);
	for (Node* cursor = head; cursor != nullptr; cursor = cursor->next)
	{
		if (cursor->next == nullptr)
		{
			insert(cursor, keepNumber);
			cursor = cursor->next;
		}
		
	}
}

void rotateRight(Node*& head)
{
	//Node* keepHead = head;
	Node* remembernode = new Node();
	int keepNumber;
	for (Node* cursor = head; cursor != nullptr; cursor = cursor->next)
	{	
		if (cursor->next != nullptr)
		{
			remembernode = cursor;
		}
		else
		{
			keepNumber = cursor->info;
		}
	}
	headInsert(head, keepNumber);
	remove(remembernode);
}

}