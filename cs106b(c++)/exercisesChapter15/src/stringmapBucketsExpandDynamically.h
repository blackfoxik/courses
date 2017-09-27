// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files
#ifndef _stringmapbucketsexpanddynamically_h
#define _stringmapbucketsexpanddynamically_h
#include <string>


class StringMapBucketsExpandDynamically {
public:
    StringMapBucketsExpandDynamically();
    ~StringMapBucketsExpandDynamically();
    std::string get(const std::string & key) const;
    void put(const std::string & key, const std::string & value);


private:
    struct Cell {
        std::string key;
        std::string value;
        Cell *link;
    };
    static const int INITIAL_BUCKET_COUNT = 2;

    Cell **buckets;
    int nBuckets;
    int nCells;
    double loadFactor;
    void rehash();
    Cell *findCell(int bucket, const std::string & key) const;
    StringMapBucketsExpandDynamically(const StringMapBucketsExpandDynamically & src) { }
    StringMapBucketsExpandDynamically & operator=(const StringMapBucketsExpandDynamically &src) {return *this;}
};

#endif
