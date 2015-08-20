#include "Vector_test.h"
#include "Vector.h"

namespace doa {
    bool Vector_test::validate() {
        Vector vector;
        int passed = 0;

        if (vector.get(5) == 0)
            ++passed;

        try {
            vector.get(-1);
        } catch (...) {
            ++passed;
        }

        try {
            vector.get(11);
        } catch (...) {
            ++passed;
        }

        vector.set(5, 10);

        if (vector.get(5) == 10)
            ++passed;

        if (vector.howMany(0) == 9)
            ++passed;

        if (vector.contains(10) == 1)
            ++passed;

        if (!vector.allUnique())
            ++passed;

        for (int i = 0; i < doa::Vector::SIZE; i++)
            vector.set(i, i);

        if (vector.allUnique())
            ++passed;

        return passed == 8;
    }
}