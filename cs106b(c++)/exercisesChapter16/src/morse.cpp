#include "morse.h"

Morse::Morse() {
    fillTable();
}

void Morse::fillTable() {
    root = new BSTNode;
    root->right = NULL;
    root->left = NULL;
    root->value = "";
    put(root, ".-","A",0);
    put(root, "-...","B",0);
    put(root, "-.-.","C",0);
    put(root, "-..","D",0);
    put(root, ".","E",0);
    put(root, "..-.","F",0);
    put(root, "--.","G",0);
    put(root, "....","H",0);
    put(root, "..","I",0);
    put(root, ".---","J",0);
    put(root, "-.-","K",0);
    put(root, ".-..","L",0);
    put(root, "--","M",0);
    put(root, "-.","N",0);
    put(root, "---","O",0);
    put(root, ".--.","P",0);
    put(root, "--.-","Q",0);
    put(root, ".-.","R",0);
    put(root, "...","S",0);
    put(root, "-","T",0);
    put(root, "..-","U",0);
    put(root, "...-","V",0);
    put(root, ".--","W",0);
    put(root, "-..-","X",0);
    put(root, "-.--","Y",0);
    put(root, "--..","Z",0);
}

void Morse::put(BSTNode *&curNode, std::string key, std::string value, int pos) {
    if (curNode == NULL) {
        curNode = new BSTNode;
        curNode->left = NULL;
        curNode->right = NULL;
    }
    if (pos == key.size()) {
        curNode->key = key;
        curNode->value = value;
        return;
    }
    char direction = key[pos];
    if (direction == '.') {
        //left
        put(curNode->left,key,value,pos + 1);
    } else {
        //right
        put(curNode->right,key,value,pos + 1);
    }

}

std::string Morse::getLetter(BSTNode *curNode, std::string code, int pos) {
    if (pos == code.size() && code == curNode->key) {
        return curNode->value;
    }
    char direction = code[pos];
    if (direction == '.') {
        //left
        return getLetter(curNode->left,code,pos + 1);
    } else if (direction == '-') {
        //right
        return getLetter(curNode->right,code,pos + 1);
    } else {
        error("invalid code! ("+code+")");
    }
    return "";
}

std::string Morse::getMorseCodeLetter(std::string code) {
    std::string letter = getLetter(root,code,0);
    return letter;
}




