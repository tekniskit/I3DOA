#ifndef I3DOA_QUEUE_H
#define I3DOA_QUEUE_H

#include "../LLToolkit/LLToolkit.h"

namespace doa {

    template<class T>
    class Queue {

        // Time complexity:
        // N = no. elements

    public:
        // Precondition:
        // Postcondition:   The linked list is deleted from the heap.
        // Time complexity: O(N)
        ~Queue() {
            llToolkit.clear(headPtr);
        }

        // Precondition:
        // Postcondition:   The queue now contains element at the rear.
        // Time complexity: O(1)
        void push(T element) {
            if (isEmpty()) {
                llToolkit.headInsert(headPtr, element);
                endPtr = headPtr;
            }
            else {
                llToolkit.insert(endPtr, element);
                endPtr = endPtr->next;
            }
        }

        // Precondition:
        // Postcondition:   The front element of the queue is deleted.
        // Time complexity: O(1)
        void pop() {
            llToolkit.headRemove(headPtr);
        }

        // Precondition:    The queue is not empty.
        // Postcondition:   Returns the front element of the queue.
        // Time complexity: O(1)
        T front() {
            if (isEmpty())
                throw "Queue is empty";

            return headPtr->info;
        }

        // Precondition:
        // Postcondition:   Returns whether the queue is empty.
        // Time complexity: O(1)
        bool isEmpty() {
            return headPtr == nullptr;
        }

        // Precondition:
        // Postcondition:   Prints the queue to standard out.
        // Time complexity: O(N)
        void print() {
            llToolkit.print(headPtr);
        }

    private:
        doa::Node<T> *headPtr = nullptr;
        doa::Node<T> *endPtr = nullptr;
        doa::LLToolkit<T> llToolkit;
    };

}

#endif //I3DOA_QUEUE_H
