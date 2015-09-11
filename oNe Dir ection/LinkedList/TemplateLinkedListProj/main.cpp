#pragma once
#include <iostream>
#include <conio.h>
#include "LinkedListProj\Node.hpp"
#include "LinkedListProj\LLToolkit.h"

using namespace std;

int main() {
	Node<int>* n1 = new Node<int>();
	Node<int>* n2 = new Node<int>(1, n1);
	Node<int>* n3 = new Node<int>(2, n2);
	Node<int>* n4 = new Node<int>(3, n3);

	LLToolkit<int>::print(n4);

	//int henning[] = { 4, 2, 0 };
	//Node* arraytest = LLToolkit::build(henning, 3);
	//LLToolkit::print(arraytest);

	//LLToolkit::reverse(n4);
	//LLToolkit::print(n4);

	/*Node* splittest = LLToolkit::split(n3);
	LLToolkit::print(n4);
	LLToolkit::print(splittest);*/

	//LLToolkit::join(n4, splittest);
	//LLToolkit::print(n4);

	//Node* copyn = LLToolkit::copy(n4);
	//LLToolkit::print(copyn);

	//LLToolkit::rotateRight(n4); //no work
	//LLToolkit::print(n4);

	//LLToolkit::rotateLeft(n4); //no work
	//LLToolkit::print(n4);

	//LLToolkit::clear(splittest);
	LLToolkit<int>::clear(n4);
	//LLToolkit::clear(copyn);
	while (1);
	return 0;
}