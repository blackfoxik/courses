// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files
#ifndef _stringmapbucketsaddmethod_h
#define _stringmapbucketsaddmethod_h
#include <string>
#include "vector.h"

class StringMapBucketsAddMethod {
public:
    StringMapBucketsAddMethod();
    ~StringMapBucketsAddMethod();
    std::string get(const std::string & key) const;
    void put(const std::string & key, const std::string & value);
    void add(const std::string & key, const std::string & value);
    void remove(const std::string & key);

private:
    struct Cell {
        std::string key;
        std::string value;
        Cell *link;
    };
    static const int INITIAL_BUCKET_COUNT = 13;
    Cell **buckets;
    int nBuckets;
    Cell *findCell(int bucket, const std::string & key) const;
    StringMapBucketsAddMethod(const StringMapBucketsAddMethod & src) { }
    StringMapBucketsAddMethod & operator=(const StringMapBucketsAddMethod &src) {return *this;}
};

#endif
