#include "lexicontree.h"

LexiconTree::LexiconTree() {
    root = NULL;
}

LexiconTree::LexiconTree(std::string &filename) {

}

void LexiconTree::addWord(Node *curNode, std::string &word, int pos) {
    if (pos > word.length() - 1) {
        curNode ->legitimate = true;
        return;
    }
    int curLetterIndex = word[pos] - 'a';
    //Vector<Node> v = curNode->alphabet;
    //Node *cp = v[curLetterIndex];
    Node *cp = curNode->alphabet[curLetterIndex];

    if(cp == NULL) {
        cp = new Node;
        Vector<Node*> v(26,NULL);
        cp->alphabet = v;
        cp->legitimate = (pos == word.length() - 1) ? true: false;
        curNode->alphabet[curLetterIndex] = cp;
    }
    addWord(cp, word, pos + 1);
}

void LexiconTree::addWord(std::string word) {
    if(root == NULL) {
        root = new Node;
        root->legitimate = false;
        Vector<Node*> v(26,NULL);
        root->alphabet = v;
        //for (int i = 0 ; i < 26; i++) {
        //    root->alphabet[i] = NULL;
        //}
    }
    addWord(root, word,0);
}

bool LexiconTree::contains(Node *curNode, std::string &word, int pos) {
    if (pos > word.length() - 1) {
        return curNode ->legitimate;
    }
    int curLetterIndex = word[pos] - 'a';
    Node *cp = curNode->alphabet[curLetterIndex];
    if(cp == NULL) {
        return false;
    }
    return contains(cp, word, pos + 1);
}

bool LexiconTree::contains(std::string word) {
    if (root == NULL) return false;
    bool res = contains(root, word, 0);
    return res;
}


