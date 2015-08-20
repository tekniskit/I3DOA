#ifndef I3DOA_VECTOR_H
#define I3DOA_VECTOR_H

namespace doa {
    class Vector
    {
    public:
        static const int SIZE = 10 ;
        Vector();
        void set(int index, int number);
        int get(int index);
        bool contains(int number);
        int howMany(int number);
        bool allUnique();
    private:
        int data[SIZE];
    };
}

#endif //I3DOA_VECTOR_H
