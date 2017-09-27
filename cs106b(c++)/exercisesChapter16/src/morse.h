// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files
#ifndef _morse_h
#define _morse_h
#include <string>
#include "grid.h"
#include "gwindow.h"
#include "point.h"



class Morse {
public:
    Morse();
    std::string getMorseCodeLetter(std::string code);
private:
    struct BSTNode {
        std::string key;
        std::string value;
        BSTNode *left, *right;
    };
    void fillTable();
    void put(BSTNode *&curNode, std::string key, std::string value, int pos);
    std::string getLetter(BSTNode *curNode, std::string code, int pos);
    BSTNode *root;
};

#endif

