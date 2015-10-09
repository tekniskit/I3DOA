#include <iostream>
#include"BTNode.h"
#include"BSTToolkit.h"

using namespace doa;

int main()
{
    BSTToolkit<int> toolkit;

    BTNode<int>* root = new BTNode<int>(5);

    toolkit.insert(root, 1);
    toolkit.insert(root, 4);
    toolkit.insert(root, 10);
    toolkit.insert(root, 19);
    toolkit.insert(root, 20);
    toolkit.insert(root, 8);
    toolkit.insert(root, 4);
    toolkit.insert(root, 7);

    std::cout << "sum: " << toolkit.sum(root) << std::endl;
    std::cout << "search: " << toolkit.search(root, 2) << std::endl;
    toolkit.print(root);
    toolkit.remove(root, 4);
}
