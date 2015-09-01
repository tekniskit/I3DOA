#ifndef I3DOA_LLTOOLKIT_H
#define I3DOA_LLTOOLKIT_H

#include <iostream>
#include "../node/Node.h"

namespace doa {

    template<class T>
    class LLToolkit {

    public:
        // Precondition: headPtr points to the head of a list
        // Postcondition: Info has been inserted at the head of the list, and headPtr is updated
        // Time complexity: O(1)
        void headInsert(Node<T> *&headPtr, T info) {
            headPtr = new Node<T>(info, headPtr);
        }

        // Precondition: headPtr points to the head of a list with at least 1 element
        // Postcondition: The head element has been removed and headPtr is updated to point to the new head element
        // Time complexity: O(1)
        void headRemove(Node<T> *&headPtr) {
            if (headPtr == nullptr)
                throw "Can't remove head. List is already empty.";

            Node<T> *condemned = headPtr;
            headPtr = headPtr->next;
            delete condemned;
        }

        // Precondition: prevPtr points to Node just before insertion point
        // Postcondition: A new Node with data=info has been inserted into the list after prevPtr
        // Time complexity: O(1)
        void insert(Node<T> *prevPtr, T info) {
            prevPtr->next = new Node<T>(info, prevPtr->next);
        }

        // Precondition: prevPtr points to Node just before Node to remove
        // Postcondition: The Node after prevPtr has been removed from the list
        // Time complexity: O(1)
        void remove(Node<T> *prevPtr) {
            Node<T> *condemned = prevPtr->next;
            prevPtr->next = prevPtr->next->next;
            delete condemned;
        }

        // Precondition: sourcePtr is the head pointer of a linked list.
        // Postcondition: A pointer to a copy of the linked list is returned. The original list is unaltered.
        // Time complexity: O(N)
        Node<T> *copy(Node<T> *sourcePtr) {
            if (sourcePtr == nullptr) {
                return nullptr;
            }

            Node<T> *head = new Node<T>(sourcePtr->info);
            Node<T> *end = head;

            for (Node<T> *node = sourcePtr->next; node != nullptr; node = node->next) {
                insert(end, node->info);
                end = end->next;
            }

            return head;
        }

        // Precondition: headPtr is the head pointer of a linked list.
        // Postcondition: All nodes of the list have been deleted, and the headPtr is NULL.
        // Time complexity: O(N)
        void clear(Node<T> *&headPtr) {
            while (headPtr != nullptr) {
                headRemove(headPtr);
            }
        }

        // Precondition: headPtr is the head pointer of a linked list.
        // Postcondition: The data item of each Node in the list has been printed to the screen.
        // Time complexity: O(N)
        void print(Node<T> *headPtr) {
            for (Node<T> *node = headPtr; node != nullptr; node = node->next) {
                std::cout << node->info << " - ";
            }

            std::cout << "/" << std::endl;
        }

        // Precondition: headPtr is the head pointer of a linked list.
        // Postcondition: headPtr points to the start of a list that is reversed with respect to the original list
        // Time complexity: O(N)
        void reverse(Node<T> *&headPtr) {
            if (headPtr == nullptr) {
                return;
            }

            Node<T>* left = nullptr;
            Node<T>* right = headPtr->next;

            while(right != nullptr) {
                headPtr->next = left;

                left = headPtr;
                headPtr = right;
                right = right->next;
            }

            headPtr->next = left;
        }

        // Precondition: splitPtr points to the node before the split point
        // Postcondition: A pointer is returned that points to the first node after splitPtr. The original list ends at the node pointed to by splitPtr
        // Time complexity: O(1)
        Node<T> *split(Node<T> *splitPtr) {
            Node<T>* head = splitPtr->next;
            splitPtr->next = nullptr;
            return head;
        }

        // Precondition: values points to an array of at least size n
        // Postcondition: A pointer is returned that points to the head of a list in which the nodes contains values from the array values
        // Time complexity: O(N)
        Node<T> *build(T *values, size_t n) {
            if (n == 0) {
                return nullptr;
            }

            Node<T>* head = new Node<T>(values[n-1]);

            for(int i = n-2; i >= 0; i--) {
                headInsert(head, values[i]);
            }

            return head;
        }

        // Precondition: head1 and head2 each point to the head of linked lists
        // Postcondition: head1 points to a list containing head1-lists' elements followed by head2-lists element.
        // Time complexity: O(N)
        void join(Node<T> *&head1, Node<T> *head2) {
            if (head2 == nullptr) {
                return;
            }

            if (head1 == nullptr) {
                head1 = head2;
                return;
            }

            Node<T> *end = head1;

            while(end->next != nullptr) {
                end = end->next;
            }

            end->next = head2;
        }

        // Precondition: head points to the head of a linked list
        // Postcondition: The list is rotated left by once - if it was 1-2-3-4, it is now 2-3-4-1
        // Time complexity: O(N)
        void rotateLeft(Node<T> *&head) {
            if (head == nullptr) {
                return;
            }

            Node<T> *end = head;

            while(end->next != nullptr) {
                end = end->next;
            }

            end->next = head;

            Node<T> *newHead = head->next;
            head->next = nullptr;
            head = newHead;
        }

        // Precondition: head points to the head of a linked list
        // Postcondition: The list is rotated right once - if it was 1-2-3-4, it is now 4-1-2-3
        // Time complexity: O(N)
        void rotateRight(Node<T> *&head) {
            if (head == nullptr) {
                return;
            }

            Node<T> *end = head;

            while(end->next->next != nullptr) {
                end = end->next;
            }

            end->next->next = head;
            head = end->next;
            end->next = nullptr;
        }

    };

}

#endif //I3DOA_LLTOOLKIT_H
