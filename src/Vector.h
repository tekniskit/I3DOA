#ifndef I3DOA_VECTOR_H
#define I3DOA_VECTOR_H

namespace doa {

    class Vector {

        // Time complexity:
        // N = no. elements

    public:
        static const int SIZE = 10;

        // Precondition:
        // Postcondition: Every vector item is set to 0.
        // Time complexity: O(N)
        Vector();

        // Precondition: 0 <= index < SIZE.
        // Postcondition: Vector item at index is set to value of number.
        // Time complexity: O(1)
        void set(int index, int number);

        // Precondition: 0 <= index < SIZE.
        // Postcondition: Return the value at index.
        // Time complexity: O(1)
        int get(int index);

        // Precondition:
        // Postcondition: Return whether number exists.
        // Time complexity: O(N)
        bool contains(int number);

        // Precondition:
        // Postcondition: Return the number of times that numbers occurs.
        // Time complexity: O(N)
        int howMany(int number);

        // Precondition:
        // Postcondition: Return whether all items are unique.
        // Time complexity: O(N^2). Kommer fra (n+1)*n/2
        bool allUnique();

    private:
        int data[SIZE];
    };

}

#endif //I3DOA_VECTOR_H
