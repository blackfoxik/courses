#include <string>
//#include <ostream>
#include "stringmapBucketsAddMethod.h"
using namespace std;

StringMapBucketsAddMethod::StringMapBucketsAddMethod() {
    nBuckets = INITIAL_BUCKET_COUNT;
    buckets = new Cell*[nBuckets];
    for (int i = 0; i < nBuckets; i++) {
        buckets[i] = NULL;
    }
}

StringMapBucketsAddMethod::~StringMapBucketsAddMethod() {
    for (int i = 0; i < nBuckets; i++) {
        Cell *cp = buckets[i];
        while (cp != NULL) {
            Cell *oldCell = cp;
            cp = cp->link;
            delete oldCell;
        }
    }
}

string StringMapBucketsAddMethod::get(const string & key) const {
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    return (cp ==NULL) ? "" : cp->value;
}

void StringMapBucketsAddMethod::put(const string & key, const string & value) {
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

void StringMapBucketsAddMethod::add(const string & key, const string & value) {
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    if (cp == NULL) {
        return;
    }
    Cell *newCp = new Cell;
    newCp->key = key;
    newCp->value = value;
    newCp->link = cp; //buckets[bucket];
    buckets[bucket] = newCp;
}

void StringMapBucketsAddMethod::remove(const string & key) {
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    if (cp == NULL) {
        return;
    }

    Cell *old = cp;
    cp = cp->link;
    buckets[bucket] = cp;
    delete old;
}

StringMapBucketsAddMethod::Cell *StringMapBucketsAddMethod::findCell(int bucket, const std::string & key) const {
    Cell *cp = buckets[bucket];
    while (cp != NULL && key != cp->key) {
        cp = cp->link;
    }
    return cp;
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



