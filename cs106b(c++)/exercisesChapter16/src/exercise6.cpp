#include "exercise6.h"
#include <iostream>
#include "console.h"
#include "simpio.h"


struct BSTNode {
    string key;
    BSTNode *left, *right;
};

int height(BSTNode *tree) {
    int leftST = 0;
    int rightST = 0;
    if (tree->left != NULL) {
        leftST = height(tree->left);
    }
    if (tree->right != NULL) {
        rightST = height(tree->right);
    }
    if (leftST >= rightST) return leftST + 1;
    return rightST + 1;
}

//using namespace std;

void exercise6() {
  //we need to implement func height
}
