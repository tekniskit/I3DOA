#ifndef I3DOA_STAR_H
#define I3DOA_STAR_H

#include "printChars.h"

void star(unsigned int n, unsigned int i) {
    if (n == 0) return;

    star(n/2, i);

    printCharLine(n, '*', i);

    star(n/2, i+n/2);
}

#endif //I3DOA_STAR_H
