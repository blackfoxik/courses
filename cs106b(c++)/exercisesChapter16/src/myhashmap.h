// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files
#ifndef _myhashmap_h
#define _myhashmap_h
#include <string>
#include "vector.h"

//#include <ostream>
#include "myhashmap.h"
using namespace std;

template <typename KeyType, typename ValueType>
class MyHashMap {
public:
    MyHashMap();
    ~MyHashMap();
    ValueType get(const KeyType & key) const;
    void put(const KeyType & key, const ValueType & value);
    int size();
    bool isEmpty();
    void remove(const KeyType & key);
    bool containsKey(const KeyType & key) const;
    void clear();
    ValueType& operator [](const KeyType& key);
    ValueType operator [](const KeyType& key) const;

private:
    struct Cell {
        KeyType key;
        ValueType value;
        Cell *link;
    };
    static const int INITIAL_BUCKET_COUNT = 13;
    Cell **buckets;
    int nBuckets;
    int nCell;
    Cell *findCell(int bucket, const KeyType & key) const;
    MyHashMap(const MyHashMap & src) { }
    MyHashMap & operator=(const MyHashMap &src) {return *this;}
};




template <typename KeyType, typename ValueType>
MyHashMap<KeyType, ValueType>::MyHashMap() {
    nBuckets = INITIAL_BUCKET_COUNT;
    nCell = 0;
    buckets = new Cell*[nBuckets];
    for (int i = 0; i < nBuckets; i++) {
        buckets[i] = NULL;
    }
}
template <typename KeyType, typename ValueType>
MyHashMap<KeyType, ValueType>::~MyHashMap() {
    for (int i = 0; i < nBuckets; i++) {
        Cell *cp = buckets[i];
        while (cp != NULL) {
            Cell *oldCell = cp;
            cp = cp->link;
            delete oldCell;
        }
    }
}
template <typename KeyType, typename ValueType>
//template <typename ValueType>
//template <typename KeyType>
ValueType MyHashMap<KeyType, ValueType>::get(const KeyType & key) const {
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    return (cp ==NULL) ? "" : cp->value;
}

//template <typename ValueType>
//template <typename KeyType>
template <typename KeyType, typename ValueType>
void MyHashMap<KeyType, ValueType>::put(const KeyType & key, const ValueType & value) {
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    if (cp == NULL) {
        cp = new Cell;
        cp->key = key;
        cp->link = buckets[bucket];
        buckets[bucket] = cp;
        nCell++;
    }
    cp->value = value;
}

//template <typename ValueType>
//template <typename KeyType>
template <typename KeyType, typename ValueType>
typename MyHashMap<KeyType, ValueType>::Cell *MyHashMap<KeyType, ValueType>::findCell(int bucket, const KeyType & key) const {
    Cell *cp = buckets[bucket];
    while (cp != NULL && key != cp->key) {
        cp = cp->link;
    }
    return cp;
}
template <typename KeyType, typename ValueType>
int MyHashMap<KeyType, ValueType>::size() {
    return nCell;
}

template <typename KeyType, typename ValueType>
bool MyHashMap<KeyType, ValueType>::isEmpty() {
    return nCell==0;
}

template <typename KeyType, typename ValueType>
void MyHashMap<KeyType, ValueType>::remove(const KeyType & key) {
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    if (cp == NULL) {
        return;
    }
    Cell *old = cp;
    cp = cp->link;
    buckets[bucket] = cp;
    delete old;
    nCell--;
}
template <typename KeyType, typename ValueType>
bool MyHashMap<KeyType, ValueType>::containsKey(const KeyType & key) const {
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    return (cp != NULL);
}
template <typename KeyType, typename ValueType>
void MyHashMap<KeyType, ValueType>::clear() {
    nCell = 0;
    for (int i = 0; i < nBuckets; i++) {
        buckets[i] = NULL;
    }
}

template <typename KeyType, typename ValueType>
ValueType& MyHashMap<KeyType, ValueType>::operator [](const KeyType& key) {
    int bucket = hashCode(key) % nBuckets;
    Cell* cp = findCell(bucket, key);
    if (cp == NULL) {
        cp = new Cell;
        cp->key = key;
        cp->value = ValueType();
        cp->link = buckets[bucket];
        buckets[bucket] = cp;
        nCell++;
    }
    return cp->value;
}

template <typename KeyType, typename ValueType>
ValueType MyHashMap<KeyType, ValueType>::operator [](const KeyType& key) const {
    return get(key);
}

/*const int HASH_SEED = 5381;
const int HASH_MULTIPLIER = 33;
const int HASH_MASK = unsigned(-1) >> 1;

int hashCode(const string &str) {
    unsigned hash = HASH_SEED;
    int n = str.length();
    for (int i = 0 ; i < n; i++) {
        hash = HASH_MULTIPLIER * hash + str[i];
    }
    return int(hash & HASH_MASK);
}*/

#endif
