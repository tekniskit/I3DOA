#ifndef NODE_HEADER
#define NODE_HEADER

template<class T>
class Node
{
public:
	Node(T i = 0, Node* n = nullptr) 
		: info(i), next(n) {};

	T info;
	Node* next;
};

#endif