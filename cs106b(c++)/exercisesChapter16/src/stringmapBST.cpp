#include <string>
//#include <ostream>
#include "stringmapBST.h"
using namespace std;

StringMapBST::StringMapBST() {
    count = 0;
    root = NULL;
}

StringMapBST::~StringMapBST() {}

string StringMapBST::get(const string & key) const {
    BSTNode *node = findKey(root,key);
    return (node == NULL) ? "":node->value;
}

void StringMapBST::insertNode(BSTNode *&curNode, BSTNode *node) {
    if (curNode == NULL) {
        curNode = node;
        return;
    }
    if (node->key < curNode->key) {
        insertNode(curNode->left, node);
    } else if (node->key > curNode->key) {
        insertNode(curNode->right, node);
    }
}

void StringMapBST::put(const string & key, const string & value) {
    BSTNode *node = findKey(root,key);
    if (node == NULL) {
        node = new BSTNode;
        node->key = key;
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        insertNode(root, node);
        count++;
        return;
    }
    node->value = value;
}

StringMapBST::BSTNode *StringMapBST::findKey(BSTNode *curNode, const string & key) const {
    if (curNode == NULL) return NULL;
    if (curNode->key == key) {
        return curNode;
    }
    if (key < curNode->key) {
        return findKey(curNode->left, key);
    } else {
        return findKey(curNode->right, key);
    }
    return NULL;
}

StringMapBST::BSTNode *StringMapBST::findRightMostNodeOnTheLeft(BSTNode *curNode) {
    BSTNode *turnLeft = curNode ->left;
    if (turnLeft == NULL) {
        return curNode;
    }
    while (turnLeft ->right != NULL) {
        turnLeft = turnLeft->right;
    }
    return turnLeft;
}

void StringMapBST::remove(BSTNode *&curNode, const std::string & key) {
   if (curNode == NULL) return;
   if (curNode->key == key) {
       if (curNode->left == NULL && curNode->right == NULL) {
           curNode = NULL;
           count--;
           return;
       }
       BSTNode *rightmostNodeOnTheLeft = findRightMostNodeOnTheLeft(curNode);
       if (rightmostNodeOnTheLeft != curNode ->left)rightmostNodeOnTheLeft ->left = curNode->left;
       rightmostNodeOnTheLeft ->right = curNode ->right;
       BSTNode *old = curNode;
       curNode = rightmostNodeOnTheLeft;
       old = NULL;
       count--;
       return;
   }
   if (key < curNode->key) {
       remove(curNode->left,key);
   }
   if (key > curNode->key) {
       remove(curNode->right,key);
   }
}

void StringMapBST::remove(const std::string & key) {
    remove(root, key);
    return;
    BSTNode *node = findKey(root,key);
    if (node != NULL) {
        if (node->left == NULL && node->right == NULL) {
            node = NULL;
            return;
        }
        BSTNode *rightmostNodeOnTheLeft = findRightMostNodeOnTheLeft(node);
        rightmostNodeOnTheLeft ->left = node->left;
        rightmostNodeOnTheLeft ->right = node ->right;
        BSTNode *old = node;
        node = rightmostNodeOnTheLeft;
        old = NULL;
        count--;
    }
}

int StringMapBST::size() {
    return count;
}

void StringMapBST::postOrderClear(BSTNode *&t) {
    if (t != NULL) {
        postOrderClear(t->left);
        postOrderClear(t->right);
        t = NULL;
    }
}

void StringMapBST::clear() {
    count = 0;
    postOrderClear(root);
}

bool StringMapBST::isEmpty(){
    return count == 0;
}

bool StringMapBST::containsKey(const std::string & key){
    BSTNode *node = findKey(root,key);
    return node != NULL;
}

string StringMapBST::operator [](const std::string & key) {
    return get(key);
}



