#include "Vector.h"
namespace doa {

    // Precondition:
    // Postcondition: Every vector item is set to 0.
    // Time complexity: O(N)
    Vector::Vector()
    {
        for (int i = 0; i < SIZE; i++) {
            data[i] = 0;
        }
    }

    // Precondition: 0 <= index < SIZE.
    // Postcondition: Vector item at index is set to value of number.
    // Time complexity: O(1)
    void Vector::set(int index, int number)
    {
        if (index < 0 || index >= SIZE) {
            throw "Index out of bounds";
        }

        data[index] = number;
    }

    // Precondition: 0 <= index < SIZE.
    // Postcondition: Return the value at index.
    // Time complexity: O(1)
    int Vector::get(int index)
    {
        if (index < 0 || index >= SIZE) {
            throw "Index out of bounds";
        }

        return data[index];
    }

    // Precondition:
    // Postcondition: Return whether number exists.
    // Time complexity: O(N)
    bool Vector::contains(int number)
    {
        for (int i = 0; i < SIZE; i++) {
            if (data[i] == number) {
                return true;
            }
        }

        return false;
    }

    // Precondition:
    // Postcondition: Return the number of times that numbers occurs.
    // Time complexity: O(N)
    int Vector::howMany(int number)
    {
        int retVal = 0;

        for (int i = 0; i < SIZE; i++) {
            if (data[i] == number) {
                ++retVal;
            }
        }

        return retVal;
    }

    // Precondition:
    // Postcondition: Return whether all items are unique.
    // Time complexity: O(log(N))
    bool Vector::allUnique()
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = i+1; j < SIZE; j++) {
                if (data[i] == data[j]) {
                    return false;
                }
            }
        }

        return true;
    }
}