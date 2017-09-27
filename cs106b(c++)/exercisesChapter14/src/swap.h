#ifndef _swap_h
#define _swap_h
#include <string>

template <typename ValueType>
void swap2(ValueType & a, ValueType & b) {
    ValueType tmp = a;
    a = b;
    b = tmp;
}

#endif

