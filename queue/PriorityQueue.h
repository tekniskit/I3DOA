#ifndef I3DOA_PRIORITYQUEUE_H
#define I3DOA_PRIORITYQUEUE_H


#include <vector>
#include "Queue.h"

namespace doa {

    template<class T>
    class PriorityQueue {
    public:
        // Precondition:
        // Postcondition:   The vector is resized to fit the required priorities.
        // Time complexity: O(N)
        PriorityQueue(unsigned int noPriorities = 1) {
            priorities.resize(noPriorities);
        }

        // Precondition:    The priority is below the number of priorities specified in the ctor.
        // Postcondition:   Element is added with the specified priority.
        // Time complexity: O(1)
        void push(T element, unsigned int priority) {
            if (priority > priorities.size() - 1) {
                throw "Invalid priority";
            }

            priorities[priority].push(element);
        }

        // Precondition:
        // Postcondition:   The front element is deleted.
        // Time complexity: O(N)
        void pop() {
            for (int i = 0; i < priorities.size(); i++) {
                if (!priorities[i].isEmpty()) {
                    priorities[i].pop();
                    return;
                }
            }
        }

        // Precondition:    Queue is not empty.
        // Postcondition:   The front element is returned.
        // Time complexity: O(N)
        T front() {
            if (isEmpty())
                throw "Queue is empty";

            for (int i = 0; i < priorities.size(); i++) {
                if (!priorities[i].isEmpty()) {
                    return priorities[i].front();
                }
            }
        }

        // Precondition:
        // Postcondition:   Returns whether the queue is empty.
        // Time complexity: O(N)
        bool isEmpty() {
            for (int i = 0; i < priorities.size(); i++) {
                if (!priorities[i].isEmpty())
                    return false;
            }

            return true;
        }

        // Precondition:
        // Postcondition:   Prints the queue to standard out.
        // Time complexity: O(N^2)
        void print() {
            for (int i = 0; i < priorities.size(); i++) {
                priorities[i].print();
            }
        }

    private:
        std::vector<doa::Queue<T>> priorities;
    };

}

#endif //I3DOA_PRIORITYQUEUE_H
