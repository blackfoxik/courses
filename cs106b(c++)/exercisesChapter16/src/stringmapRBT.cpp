#include <string>
#include "stringmapRBT.h"
using namespace std;

StringMapRBT::StringMapRBT() {
    count = 0;
    root = NULL;
}

StringMapRBT::~StringMapRBT() {}

string StringMapRBT::get(const string & key) const {
    RBTNode *node = findKey(root,key);
    return (node == NULL) ? "":node->value;
}

void StringMapRBT::insertNode(RBTNode *&curNode, const string & key, const string & value) {
    if (curNode == NULL) {
        RBTNode *node = new RBTNode;
        node->key = key;
        node->value = value;
        node->left = NULL;
        node->right = NULL;
        node->color = RED;
        if (curNode == root) {
            root = node;
            root->color = BLACK;
            return;
        }
        curNode = node;
        return;
    }
    if (key < curNode->key) {
        insertNode(curNode->left, key, value);
    } else if (key > curNode->key) {
        insertNode(curNode->right, key, value);
    }
}

void StringMapRBT::put(const string & key, const string & value) {
    RBTNode *node = findKey(root,key);
    if (node == NULL) {
        insertNode(root, key, value);
        count++;
        return;
    }
    node->value = value;
}

StringMapRBT::RBTNode *StringMapRBT::findKey(RBTNode *curNode, const string & key) const {
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

StringMapRBT::RBTNode *StringMapRBT::findRightMostNodeOnTheLeft(RBTNode *curNode) {
    RBTNode *turnLeft = curNode ->left;
    if (turnLeft == NULL) {
        return curNode;
    }
    while (turnLeft ->right != NULL) {
        turnLeft = turnLeft->right;
    }
    return turnLeft;
}

void StringMapRBT::remove(RBTNode *&curNode, const std::string & key) {
   if (curNode == NULL) return;
   if (curNode->key == key) {
       if (curNode->left == NULL && curNode->right == NULL) {
           curNode = NULL;
           count--;
           return;
       }
       RBTNode *rightmostNodeOnTheLeft = findRightMostNodeOnTheLeft(curNode);
       if (rightmostNodeOnTheLeft != curNode ->left)rightmostNodeOnTheLeft ->left = curNode->left;
       rightmostNodeOnTheLeft ->right = curNode ->right;
       RBTNode *old = curNode;
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

void StringMapRBT::remove(const std::string & key) {
    remove(root, key);
    return;
    RBTNode *node = findKey(root,key);
    if (node != NULL) {
        if (node->left == NULL && node->right == NULL) {
            node = NULL;
            return;
        }
        RBTNode *rightmostNodeOnTheLeft = findRightMostNodeOnTheLeft(node);
        rightmostNodeOnTheLeft ->left = node->left;
        rightmostNodeOnTheLeft ->right = node ->right;
        RBTNode *old = node;
        node = rightmostNodeOnTheLeft;
        old = NULL;
        count--;
    }
}

int StringMapRBT::size() {
    return count;
}

void StringMapRBT::postOrderClear(RBTNode *&t) {
    if (t != NULL) {
        postOrderClear(t->left);
        postOrderClear(t->right);
        t = NULL;
    }
}

void StringMapRBT::clear() {
    count = 0;
    postOrderClear(root);
}

bool StringMapRBT::isEmpty(){
    return count == 0;
}

bool StringMapRBT::containsKey(const std::string & key){
    RBTNode *node = findKey(root,key);
    return node != NULL;
}

string StringMapRBT::operator [](const std::string & key) {
    return get(key);
}



