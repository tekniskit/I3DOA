#ifndef I3DOA_SEARCH_H
#define I3DOA_SEARCH_H
namespace doa {
    bool search(int* ar, int n, int target) {
        if (n == 0) return false;
        if (ar[0] == target) return true;

        search(ar + 1, n - 1, target);
    }
}

#endif //I3DOA_SEARCH_H
