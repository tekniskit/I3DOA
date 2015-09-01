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
            llToolkit.headInsert(head, element);
        }

        void pop() {
            llToolkit.headRemove(head);
        }

        T top() {
            if (isEmpty())
                throw "Stack is empty";

            return head->info;
        }

        bool isEmpty() {
            return head == nullptr;
        }

    private:
        Node<T> *head = nullptr;
        LLToolkit<T> llToolkit;
    };
}

#endif //I3DOA_STACK_H
