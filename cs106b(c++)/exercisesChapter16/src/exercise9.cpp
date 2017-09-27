#include "exercise9.h"
#include <iostream>
#include "console.h"
#include "simpio.h"

using namespace std;
/*
struct BSTNode {
    string key;
    BSTNode *left, *right;
    int bf;
};

//mocks
void fixLeftImbalance(BSTNode *&t) {

}

void fixRightImbalance(BSTNode *&t) {

}

int removeNode(BSTNode *&t, const string & key) {
    if (t == NULL) return 0;
    if (key > t->key) {
        int delta = removeNode(t->right, key);
        if (delta == 0) return 0;
        switch (t->bf) {
            case -1:t->bf = 0; return 0;
            case 0: t->bf = 1; return 1;
            case 1:  fixLeftImbalance(t); t->bf = 0; return 0;
        }
    }
    if (key < t->key) {
        int delta = removeNode(t->left, key);
        if (delta == 0) return 0;
        switch (t->bf) {
            case 1:t->bf = 0; return 0;
            case 0: t->bf = -1; return -1;
            case -1:  fixRightImbalance(t); t->bf = 0; return 0;
        }
    }
    if (key == t->key) {
        t->left->right = t->right;
        BSTNode *old = t;
        t = t->left;
        delete old;
        return 1;
    }
}
*/
void exercise9() {
  //we need to implement func remove

}
