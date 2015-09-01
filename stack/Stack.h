//
// Created by rsreimer on 01-09-2015.
//

#ifndef I3DOA_STACK_H
#define I3DOA_STACK_H

#include "../node/Node.h"
#include "../LLToolkit/LLToolkit.h"

namespace doa {

    template<class T>
    class Stack {
    public:
        void push(T element) {
            llToolkit.headInsert(headPtr, element);
        }

        void pop() {
            llToolkit.headRemove(headPtr);
        }

        T top() {
            if (isEmpty())
                throw "Stack is empty";

            return headPtr->info;
        }

        bool isEmpty() {
            return headPtr == nullptr;
        }

    private:
        Node<T> *headPtr = nullptr;
        LLToolkit<T> llToolkit;
    };
}

#endif //I3DOA_STACK_H
