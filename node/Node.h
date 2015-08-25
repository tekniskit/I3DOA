#ifndef I3DOA_NODE_H
#define I3DOA_NODE_H

namespace doa {

    template <class T>
    class Node {

    public:
        Node(T i = 0, Node* n = nullptr)
                : info(i), next(n) {};
        T info;
        Node* next;

    };

}

#endif //I3DOA_NODE_H
