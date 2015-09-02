#pragma once
#include <iostream>
#include <conio.h>
#include "LinkedListProj\Node.hpp"
#include "LinkedListProj\LLToolkit.h"

using namespace std;

int main() {
	Node* n1 = new Node();
	Node* n2 = new Node(1, n1);
	Node* n3 = new Node(2, n2);
	Node* n4 = new Node(3, n3);

	LLToolkit::print(n4);

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
	LLToolkit::clear(n4);
	//LLToolkit::clear(copyn);
	while (1);
	return 0;
}