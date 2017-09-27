// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files
#ifndef _stringmapbst_h
#define _stringmapbst_h
#include <string>
#include "vector.h"

class StringMapBST {
public:
    StringMapBST();
    ~StringMapBST();
    std::string get(const std::string & key) const;
    void put(const std::string & key, const std::string & value);
    void remove(const std::string & key);
    void clear();
    bool isEmpty();
    bool containsKey(const std::string & key);
    int size();
    std::string operator[](const std::string & key);

private:
    struct BSTNode {
        std::string key;
        std::string value;
        BSTNode *left, *right;
    };
    int count;
    BSTNode *root;
    BSTNode * findKey(BSTNode *curNode,const std::string & key) const;
    void insertNode(BSTNode *&curNode, BSTNode *node);
    BSTNode *findRightMostNodeOnTheLeft(BSTNode *curNode);
    void remove(BSTNode *&curNode, const std::string & key);
    void postOrderClear(BSTNode *&t);
};

#endif
