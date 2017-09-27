#ifndef _lexicontree_h
#define _lexicontree_h
#include <string>
#include "vector.h"



class LexiconTree {
public:
    LexiconTree();
    LexiconTree(std::string &filename);
    void addWord(std::string word);
    bool contains(std::string word);

private:
    struct Node {
        Vector<Node*> alphabet;
        bool legitimate;
    };
    Node *root;
    void addWord(Node *curNode, std::string &word, int pos);
    bool contains(Node *curNode, std::string &word, int pos);
    //void fillTable();
    //void put(BSTNode *&curNode, std::string key, std::string value, int pos);
    //std::string getLetter(BSTNode *curNode, std::string code, int pos);

};

#endif

