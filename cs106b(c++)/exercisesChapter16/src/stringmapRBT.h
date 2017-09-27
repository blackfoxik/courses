// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files
#ifndef _stringmaprbt_h
#define _stringmaprbt_h
#include <string>
#include "vector.h"

class StringMapRBT {
public:
    StringMapRBT();
    ~StringMapRBT();
    std::string get(const std::string & key) const;
    void put(const std::string & key, const std::string & value);
    void remove(const std::string & key);
    void clear();
    bool isEmpty();
    bool containsKey(const std::string & key);
    int size();
    std::string operator[](const std::string & key);

private:
    enum Color {RED, BLACK};
    struct RBTNode {
        std::string key;
        std::string value;
        RBTNode *left, *right;
        Color color;
    };
    int count;
    RBTNode *root;
    RBTNode * findKey(RBTNode *curNode,const std::string & key) const;
    void insertNode(RBTNode *&curNode, const std::string & key, const std::string & value);
    RBTNode *findRightMostNodeOnTheLeft(RBTNode *curNode);
    void remove(RBTNode *&curNode, const std::string & key);
    void postOrderClear(RBTNode *&t);
};

#endif
