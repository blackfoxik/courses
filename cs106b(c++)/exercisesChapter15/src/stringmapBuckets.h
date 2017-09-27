// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files
#ifndef _stringmapbuckets_h
#define _stringmapbuckets_h
#include <string>
#include "vector.h"

class StringMapBuckets {
public:
    StringMapBuckets();
    ~StringMapBuckets();
    std::string get(const std::string & key) const;
    void put(const std::string & key, const std::string & value);


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
    StringMapBuckets(const StringMapBuckets & src) { }
    StringMapBuckets & operator=(const StringMapBuckets &src) {return *this;}
};

#endif
