#ifndef _pair_h
#define _pair_h
#include <string>
//#include "vector.h"


template <typename T1, typename T2>
class Pair {
public:
    Pair();
    Pair(T1 v1, T2 v2);
    T1 getFirst();
    T2 getSecond();
private:
    T1 *first;
    T2 *second;
};


template <typename T1, typename T2>
Pair<T1,T2>::Pair() {
    first = new T1;
    second = new T2;
}

template <typename T1, typename T2>
Pair<T1,T2>::Pair(T1 v1, T2 v2) {
    T1 *c1 = new T1;
    *c1 = v1;
    T2 *c2 = new T2;
    *c2 = v2;
    first = c1;
    second = c2;
}

template <typename T1, typename T2>
T1 Pair<T1,T2>::getFirst() {
   return *first;
}

template <typename T1, typename T2>
T2 Pair<T1,T2>::getSecond() {
   return *second;
}

#endif

