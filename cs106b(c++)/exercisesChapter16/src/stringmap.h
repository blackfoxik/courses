// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files
#ifndef _stringmap_h
#define _stringmap_h
#include <string>
#include "vector.h"

class StringMap {
public:
    StringMap();
    ~StringMap();
    std::string get(const std::string & key) const;
    void put(const std::string & key, const std::string & value);


private:
    struct KeyValuePair {
        std::string key;
        std::string value;
    };
    Vector<KeyValuePair> bindings;
    int findKey(const std::string & key) const;
};

#endif
