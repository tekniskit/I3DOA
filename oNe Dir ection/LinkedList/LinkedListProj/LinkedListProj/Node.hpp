#ifndef NODE_HEADER
#define NODE_HEADER

class Node
{
public:
	Node(int i = 0, Node* n = nullptr) 
		: info(i), next(n) {};

	int info;
	Node* next;
};

#endif