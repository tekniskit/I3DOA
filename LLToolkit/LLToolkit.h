#ifndef I3DOA_LLTOOLKIT_H
#define I3DOA_LLTOOLKIT_H

#include "../node/Node.h"

namespace doa {

    template<class T>
    class LLToolkit {

    public:
        // Precondition: headPtr points to the head of a list
        // Postcondition: Info has been inserted at the head of the list, and headPtr is updated
        void headInsert(Node<T> *&headPtr, T info) {
            headPtr = new Node<T>(info, headPtr);
        }

        // Precondition: headPtr points to the head of a list with at least 1 element
        // Postcondition: The head element has been removed and headPtr is updated to point to the new head element
        void headRemove(Node<T> *&headPtr) {
            Node<T> *condemned = headPtr;
            headPtr = headPtr->next;
            delete condemned;
        }

        // Precondition: prevPtr points to Node just before insertion point
        // Postcondition: A new Node with data=info has been inserted into the list after prevPtr
        void insert(Node<T> *prevPtr, T info) {
            prevPtr->next = new Node<T>(info, prevPtr->next);
        }

        // Precondition: prevPtr points to Node just before Node to remove
        // Postcondition: The Node after prevPtr has been removed from the list
        void remove(Node<T> *prevPtr) {
            Node<T> *condemned = prevPtr->next;
            prevPtr->next = prevPtr->next->next;
            delete condemned;
        }

        // Precondition: sourcePtr is the head pointer of a linked list.
        // Postcondition: A pointer to a copy of the linked list is returned. The original list is unaltered.
        Node<T> *copy(Node<T> *sourcePtr) {
            if (sourcePtr == nullptr) {
                return nullptr;
            }

            Node<T> *head = new Node<T>(sourcePtr->info);
            Node<T> *prev = head;

            for (Node<T> *node = sourcePtr->next; node != nullptr; node = node->next) {
                insert(prev, node->info);
                prev = prev->next;
            }

            return head;
        }

        // Precondition: headPtr is the head pointer of a linked list.
        // Postcondition: All nodes of the list have been deleted, and the headPtr is NULL.
        void clear(Node<T> *&headPtr) {
            while (headPtr != nullptr) {
                headRemove(headPtr);
            }
        }

        // Precondition: headPtr is the head pointer of a linked list.
        // Postcondition: The data item of each Node in the list has been printed to the screen.
        void print(Node<T> *headPtr) {
            for (Node<T> *node = headPtr; node != nullptr; node = node->next) {
                std::cout << node->info << " - ";
            }

            std::cout << "/" << std::endl;
        }

        // Precondition: headPtr is the head pointer of a linked list.
        // Postcondition: headPtr points to the start of a list that is reversed with respect to the original list
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
        Node<T> *split(Node<T> *splitPtr) {
            Node<T>* head = splitPtr->next;
            splitPtr->next = nullptr;
            return head;
        }

        // Precondition: head1 and head2 each point to the head of linked lists
        // Postcondition: head1 points to a list containing head1-lists' elements followed by head2-lists element.
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
    };

}

#endif //I3DOA_LLTOOLKIT_H
