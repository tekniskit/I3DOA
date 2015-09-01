#ifndef I3DOA_STACK_H
#define I3DOA_STACK_H

#include "../LLToolkit/LLToolkit.h"

namespace doa {

    template<class T>
    class Stack {
    public:
        // Precondition:
        // Postcondition:   The linked list is deleted from the heap.
        // Time complexity: O(N)
        ~Stack() {
            llToolkit.clear(headPtr);
        }

        // Precondition:
        // Postcondition:   The stack now contains element at the top.
        // Time complexity: O(1)
        void push(T element) {
            llToolkit.headInsert(headPtr, element);
        }

        // Precondition:    The stack is not empty.
        // Postcondition:   The top element of the stack is deleted.
        // Time complexity: O(1)
        void pop() {
            llToolkit.headRemove(headPtr);
        }

        // Precondition:    The stack is not empty.
        // Postcondition:   Returns the top element of the stack.
        // Time complexity: O(1)
        T top() {
            if (isEmpty())
                throw "Stack is empty";

            return headPtr->info;
        }

        // Precondition:
        // Postcondition:   Returns whether the stack is empty.
        // Time complexity: O(1)
        bool isEmpty() {
            return headPtr == nullptr;
        }

        // Precondition:
        // Postcondition:   Prints the stack to standard out.
        // Time complexity: O(N)
        void print() {
            llToolkit.print(headPtr);
        }

    private:
        Node<T> *headPtr = nullptr;
        LLToolkit<T> llToolkit;
    };
}

#endif //I3DOA_STACK_H
