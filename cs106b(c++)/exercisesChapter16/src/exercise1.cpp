#include "exercise1.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "tokenscanner.h"
#include "vector.h"
#include <fstream>


//using namespace std;

struct FamilyTreeNode {
    string name;
    Vector<FamilyTreeNode *> children;
};

//func prototype
FamilyTreeNode *readFamilyTree(string filename);
void displayFamilyTree(FamilyTreeNode *root, string spaces);
void displayFamilyTree(FamilyTreeNode *root);
void fillNames(string & line, string & parent, string & child);
FamilyTreeNode * findParentByName(string &parentName, FamilyTreeNode *root);

void exercise1() {
    string filename = "Normandy.txt";
    FamilyTreeNode *root = readFamilyTree(filename);
    displayFamilyTree(root);
}

FamilyTreeNode *readFamilyTree(string filename) {
    TokenScanner ts;
    ifstream infile;
    infile.open(filename);
    ts.setInput(infile);
    ts.ignoreWhitespace();
    ts.addWordCharacters(" ");
    ts.addWordCharacters(":");
    FamilyTreeNode *root = new FamilyTreeNode;
    string nameRoot = ts.nextToken();
    root->name = nameRoot;


    while (ts.hasMoreTokens()) {
        string curLine = ts.nextToken();
        string parentName = "";
        string childName = "";
        fillNames(curLine, parentName, childName);
        FamilyTreeNode * child = new FamilyTreeNode;
        child->name = childName;
        FamilyTreeNode *parent = findParentByName(parentName, root);
        parent ->children.add(child);

    }
    return root;
}

void displayFamilyTree(FamilyTreeNode *root) {
   displayFamilyTree(root, "");
}

void displayFamilyTree(FamilyTreeNode *root, string spaces) {
    //if (root->children.size() == 0) return;
    cout << spaces << root->name << endl;
    spaces +="  ";
    for (int i = 0 ; i < root->children.size(); i++) {
        if (root->children.get(i)->children.size() > 0) {
            displayFamilyTree(root->children.get(i), spaces);
        } else {
           cout << spaces << root->children.get(i)->name << endl;
        }
    }
}

void fillNames(string & line, string & parent, string & child) {
    int pos = line.find(":");
    if (pos == -1) {
        error ("the root was in line " + line);
    }
    child = line.substr(0, pos);
    parent = line.substr(pos + 1);
}

FamilyTreeNode * findParentByName(string &parentName, FamilyTreeNode *root) {
    if (root->name == parentName) {
        return root;
    }
    FamilyTreeNode *parent = NULL;
    for (int i = 0; i < root->children.size(); i++) {
        parent = findParentByName(parentName,root->children.get(i));
        if (parent != NULL) break;
    }
    return parent;
}
