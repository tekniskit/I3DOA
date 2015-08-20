#include <iostream>
#include "vector/Vector_test.h"

using namespace std;

int main() {
    doa::Vector_test vector_test;
    cout << "Vector tests: " << (vector_test.validate() ? "passed" : "failed") << endl;

    return 0;
}
