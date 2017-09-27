// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files
#ifndef _stringmapbucketsexpanddynamically_h
#define _stringmapbucketsexpanddynamically_h
#include <string>

template <typename KeyType, typename ValueType>
class MapBucketsExpandDynamically{
public:
    MapBucketsExpandDynamically();
    ~MapBucketsExpandDynamically();
    ValueType get(const KeyType & key) const;
    void put(const KeyType & key, const ValueType & value);


private:
    struct Cell {
        KeyType key;
        ValueType value;
        Cell *link;
    };
    static const int INITIAL_BUCKET_COUNT = 2;

    Cell **buckets;
    int nBuckets;
    int nCells;
    double loadFactor;
    void rehash();
    Cell *findCell(int bucket, const KeyType & key) const;
    MapBucketsExpandDynamically(const MapBucketsExpandDynamically & src) { }
    MapBucketsExpandDynamically & operator=(const MapBucketsExpandDynamically &src) {return *this;}
};


static const double REHASH_THRESHOLD = 0.7;
template <typename KeyType, typename ValueType>
MapBucketsExpandDynamically<KeyType, ValueType>::MapBucketsExpandDynamically() {
    loadFactor = 0;
    nCells = 0;
    nBuckets = INITIAL_BUCKET_COUNT;
    buckets = new Cell*[nBuckets];
    for (int i = 0; i < nBuckets; i++) {
        buckets[i] = NULL;
    }
}

template <typename KeyType, typename ValueType>
MapBucketsExpandDynamically<KeyType, ValueType>::~MapBucketsExpandDynamically() {
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
ValueType MapBucketsExpandDynamically<KeyType, ValueType>::get(const KeyType & key) const {
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    return (cp ==NULL) ? "" : cp->value;
}

template <typename KeyType, typename ValueType>
void MapBucketsExpandDynamically<KeyType, ValueType>::put(const KeyType & key, const ValueType & value) {
    int hashC = hashCode(key);
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    if (cp == NULL) {

        loadFactor = double(nCells) / double(nBuckets);
        if (loadFactor > REHASH_THRESHOLD) {
            rehash();
            bucket = hashCode(key) % nBuckets;
        }
        cp = new Cell;
        cp->key = key;
        cp->link = buckets[bucket];
        buckets[bucket] = cp;
        nCells++;
    }
    cp->value = value;
}

template <typename KeyType, typename ValueType>
typename MapBucketsExpandDynamically<KeyType, ValueType>::Cell *MapBucketsExpandDynamically<KeyType, ValueType>::findCell(int bucket, const KeyType & key) const {
    Cell *cp = buckets[bucket];
    while (cp != NULL && key != cp->key) {
        cp = cp->link;
    }
    return cp;
}

template <typename KeyType, typename ValueType>
void MapBucketsExpandDynamically<KeyType, ValueType>::rehash() {
    int newNBuckets = nBuckets * 2;
    Cell **newBuckets = new Cell*[newNBuckets];
    for (int i = 0; i < newNBuckets; i++) {
        newBuckets[i] = NULL;
    }
    for (int i = 0; i < nBuckets; i++) {
        Cell *cp = buckets[i];
        while (cp != NULL) {
           int newNbucket = hashCode(cp->key) % newNBuckets;
           Cell *newCell = new Cell;
           newCell->key = cp->key;
           newCell->value = cp->value;
           newCell->link = newBuckets[newNbucket];
           newBuckets[newNbucket] = newCell;
           Cell *old = cp;
           cp = cp->link;
           delete old;
        }
    }
    nBuckets = newNBuckets;
    delete[] buckets;
    buckets = newBuckets;
    loadFactor = double(nCells) / double(nBuckets);
}

#endif
