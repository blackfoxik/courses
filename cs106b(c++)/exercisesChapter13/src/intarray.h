#ifndef _intarray_h
#define _intarray_h
#include <iostream>

using namespace std;

class IntArray {
    public:
    IntArray(int n);
    ~IntArray();
    int size();
    int get(int k);
    void put(int k, int value);
    int & operator[](int k);
    IntArray(const IntArray &src);
    IntArray & operator= (const IntArray & src);

    private:
    void deepCopy(const IntArray & src);
    int *array;
    int capacity;
};

#endif

