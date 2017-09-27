/*#include <string>
//#include <ostream>
#include "myhashmap.h"
using namespace std;

//template <typename KeyType, typename ValueType>
//template <typename KeyType>
template <typename KeyType, typename ValueType>
MyHashMap::MyHashMap() {
    nBuckets = INITIAL_BUCKET_COUNT;
    buckets = new Cell*[nBuckets];
    for (int i = 0; i < nBuckets; i++) {
        buckets[i] = NULL;
    }
}
template <typename KeyType, typename ValueType>
MyHashMap::~MyHashMap() {
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
ValueType MyHashMap::get(const KeyType & key) const {
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    return (cp ==NULL) ? "" : cp->value;
}

//template <typename ValueType>
//template <typename KeyType>
template <typename KeyType, typename ValueType>
void MyHashMap::put(const KeyType & key, const ValueType & value) {
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    if (cp == NULL) {
        cp = new Cell;
        cp->key = key;
        cp->link = buckets[bucket];
        buckets[bucket] = cp;
    }
    cp->value = value;
}

//template <typename ValueType>
//template <typename KeyType>
template <typename KeyType, typename ValueType>
MyHashMap::Cell *MyHashMap::findCell(int bucket, const KeyType & key) const {
    Cell *cp = buckets[bucket];
    while (cp != NULL && key != cp->key) {
        cp = cp->link;
    }
    return cp;
}

const int HASH_SEED = 5381;
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



