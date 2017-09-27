
#include "intarray.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "error.h"

using namespace std;

IntArray::IntArray(int n) {
    capacity = n;
    array = new int[n];
    for (int i = 0; i < n; i++) {
        array[i] = 0;
    }
}

IntArray::~IntArray() {
    delete[] array;
}

int IntArray::size(){
    return capacity;
}

int IntArray::get(int k) {
   if (k >= capacity) error("Out of bounds");
   return array[k];
}

void IntArray::put(int k, int value) {
   if (k >= capacity) error("Out of bounds");
   array[k] = value;
}

int & IntArray::operator [](int k) {
    if (k >= capacity) error("Out of bounds");
    return array[k];
}

IntArray & IntArray::operator= (const IntArray & src) {
    if (this != &src) {
        delete[] array;
        deepCopy(src);
    }
    return *this;
}

IntArray::IntArray(const IntArray &src) {
    deepCopy(src);
}

void IntArray::deepCopy(const IntArray &src) {
    array = new int[src.capacity];
    for (int i = 0; i < src.capacity; i++) {
        array[i] = src.array[i];
    }
    capacity = src.capacity;
}
