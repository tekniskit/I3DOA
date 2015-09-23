#ifndef I3DOA_BOOKLET_H
#define I3DOA_BOOKLET_H

#include <cstdio>

void bookletPrint(int startPage, int endPage) {
    if (startPage > endPage) return;

    printf("Sheet x contains pages %d, %d, %d, %d.\n", startPage, startPage+1, endPage-1, endPage);

    bookletPrint(startPage+2, endPage-2);
};

#endif //I3DOA_BOOKLET_H
