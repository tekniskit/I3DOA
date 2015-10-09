#ifndef I3DOA_BSTTOOLKIT_H
#define I3DOA_BSTTOOLKIT_H

#include "BTNode.h"

namespace doa {
    template<typename T>
    class BSTToolkit {
    public:
        void insert(BTNode<T> *&root, const T &data) {
            if (data > root->data) {
                if (root->right == nullptr)
                    root->right = new BTNode<T>(data);
                else
                    insert(root->right, data);
            } else {
                if (root->left == nullptr)
                    root->left = new BTNode<T>(data);
                else
                    insert(root->left, data);
            }
        }

        void remove(BTNode<T> *&root, const T &data) {
            if (root == nullptr) return;

        }

        bool search(BTNode<T> *root, const T &data) {
            if (root == nullptr)
                return false;

            if (root->data < data)
                return search(root->left, data);
            else if (root->data > data)
                return search(root->right, data);
            else
                return true;
        }

        void print(BTNode<T> *root, int depth = 0) {
            if (root == nullptr)
                return;

            print(root->right, depth + 1);
            std::cout << std::string(4 * depth, ' ') << root->data << std::endl;
            print(root->left, depth + 1);
        }

        T sum(BTNode<T>* root) {
            return root ? root->data + sum(root->left) + sum(root->right) : 0;
        }
    };
}


#endif //I3DOA_BSTTOOLKIT_H
