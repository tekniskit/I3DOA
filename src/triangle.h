#ifndef I3DOA_TRIANGLE_H
#define I3DOA_TRIANGLE_H

// Precondition: m <= n
// Postcondition: The function has printed a pattern of lines so that the
// first line contains m stars, the next line contains m+1 stars, and so on
// up to a line with n asterisks.
// Then the pattern is repeated backwards, going n back down to m.
// Example output:
// triangle(4, 6) will print this:
// ****
// *****
// ******
// ******
// *****
// ****

#include "printStars.h"

void triangle(unsigned int m, unsigned int n) {
    if (m > n) return;

    printStars(m);
    std::cout << std::endl;

    triangle(m+1, n);

    printStars(m);
    std::cout << std::endl;
}


#endif //I3DOA_TRIANGLE_H