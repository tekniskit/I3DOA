#ifndef I3DOA_PRIORITYQUEUE_H
#define I3DOA_PRIORITYQUEUE_H


#include <vector>
#include "Queue.h"

namespace doa {

    template<class T>
    class PriorityQueue {
    public:
        PriorityQueue(unsigned int noPriorities = 1) {
            priorities.resize(noPriorities);
        }

        void push(T element, unsigned int priority) {
            if (priority > priorities.size() - 1) {
                throw "Invalid priority";
            }

            priorities[priority].push(element);
        }

        void pop() {
            for (int i = 0; i < priorities.size(); i++) {
                if (!priorities[i].isEmpty()) {
                    priorities[i].pop();
                    return;
                }
            }
        }

        T front() {
            if (isEmpty())
                throw "Queue is empty";

            for (int i = 0; i < priorities.size(); i++) {
                if (!priorities[i].isEmpty()) {
                    return priorities[i].front();
                }
            }
        }

        bool isEmpty() {
            for (int i = 0; i < priorities.size(); i++) {
                if (!priorities[i].isEmpty())
                    return false;
            }

            return true;
        }

        void print() {
            for (int i = 0; i < priorities.size(); i++) {
                priorities[i].print();
            }
        }

    private:
        std::vector<Queue<T>> priorities;
    };

}

#endif //I3DOA_PRIORITYQUEUE_H
