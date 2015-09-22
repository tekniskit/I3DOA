#ifndef I3DOA_PRINTSTARS_H
#define I3DOA_PRINTSTARS_H

void printChar(unsigned int n, char c) {
    if (n == 0) return;
    std::cout << c;
    printChar(n-1, c);
}

void printCharLine(unsigned int n, char c, unsigned int offset = 0) {
    if (n == 0) return;
    printChar(offset, ' ');
    printChar(n, c);
    std::cout << std::endl;
}

#endif //I3DOA_PRINTSTARS_H
