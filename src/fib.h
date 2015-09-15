#ifndef I3DOA_FIB_H
#define I3DOA_FIB_H

/*
1)
2) n < 2. return n.
3) n > 3. return fib(n-1)+fib(n-2).
4)
*/

namespace doa {
    int fib(unsigned int n) {
        if (n < 2) return n;
        return fib(n-1)+fib(n-2);
    }
}

#endif //I3DOA_FIB_H
