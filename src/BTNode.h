#ifndef I3DOA_BTNODE_H
#define I3DOA_BTNODE_H

namespace doa {
    template <typename T>
    class BTNode {
    public:
        BTNode(T data, BTNode<T>* left = nullptr, BTNode<T>* right = nullptr):
                data(data), left(left), right(right) {}

        T data;
        BTNode<T>* left;
        BTNode<T>* right;
    };
}


#endif //I3DOA_BTNODE_H
