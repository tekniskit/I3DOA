#ifndef I3DOA_QUEUE_H
#define I3DOA_QUEUE_H

#include "../LLToolkit/LLToolkit.h"

namespace doa {

    template<class T>
    class Queue {
    public:
        ~Queue() {
            llToolkit.clear(headPtr);
        }

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

        void pop() {
            llToolkit.headRemove(headPtr);
        }

        T front() {
            if (isEmpty())
                throw "Queue is empty";

            return headPtr->info;
        }

        bool isEmpty() {
            return headPtr == nullptr;
        }

        void print() {
            llToolkit.print(headPtr);
        }

    private:
        Node<T> *headPtr = nullptr;
        Node<T> *endPtr = nullptr;
        LLToolkit<T> llToolkit;
    };

}

#endif //I3DOA_QUEUE_H
