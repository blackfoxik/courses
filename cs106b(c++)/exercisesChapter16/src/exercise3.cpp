#include "exercise3.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "tokenscanner.h"
#include "vector.h"
#include <fstream>


//using namespace std;

struct FamilyTreeNodeEx3 {
    string name;
    FamilyTreeNodeEx3 *eldestChildren;
    FamilyTreeNodeEx3 *subling;
};

//func prototype
FamilyTreeNodeEx3 *readFamilyTreeEx3(string filename);
void displayFamilyTreeEx3(FamilyTreeNodeEx3 *root, string spaces);
void displayFamilyTreeEx3(FamilyTreeNodeEx3 *root);
void fillNamesEx3(string & line, string & parent, string & child);
FamilyTreeNodeEx3 * findParentByNameEx3(string &parentName, FamilyTreeNodeEx3 *root);

void exercise3() {
    string filename = "Normandy.txt";
    FamilyTreeNodeEx3 *root = readFamilyTreeEx3(filename);
    displayFamilyTreeEx3(root);
}

FamilyTreeNodeEx3 *readFamilyTreeEx3(string filename) {
    TokenScanner ts;
    ifstream infile;
    infile.open(filename);
    ts.setInput(infile);
    ts.ignoreWhitespace();
    ts.addWordCharacters(" ");
    ts.addWordCharacters(":");
    FamilyTreeNodeEx3 *root = new FamilyTreeNodeEx3;
    string nameRoot = ts.nextToken();
    root->name = nameRoot;
    root->eldestChildren = NULL;
    root->subling = NULL;


    while (ts.hasMoreTokens()) {
        string curLine = ts.nextToken();
        string parentName = "";
        string childName = "";
        fillNamesEx3(curLine, parentName, childName);
        FamilyTreeNodeEx3 * child = new FamilyTreeNodeEx3;
        child->name = childName;
        child->subling = NULL;
        child->eldestChildren = NULL;
        FamilyTreeNodeEx3 *parent = findParentByNameEx3(parentName, root);
        if (parent->eldestChildren != NULL) {
           FamilyTreeNodeEx3 * subling = parent->eldestChildren;
           while (subling->subling != NULL) {
               subling = subling->subling;
           }
           subling->subling = child;
        } else {
           parent ->eldestChildren = child;
        }

    }
    return root;
}

void displayFamilyTreeEx3(FamilyTreeNodeEx3 *root) {
   displayFamilyTreeEx3(root, "");
}

void displayFamilyTreeEx3(FamilyTreeNodeEx3 *root, string spaces) {
    //if (root->children.size() == 0) return;
    cout << spaces << root->name << endl;
    spaces +="  ";
    FamilyTreeNodeEx3 *child = root->eldestChildren;
    while (child != NULL) {
       displayFamilyTreeEx3(child, spaces);
       child = child->subling;
    }
}

void fillNamesEx3(string & line, string & parent, string & child) {
    int pos = line.find(":");
    if (pos == -1) {
        error ("the root was in line " + line);
    }
    child = line.substr(0, pos);
    parent = line.substr(pos + 1);
}

FamilyTreeNodeEx3 * findParentByNameEx3(string &parentName, FamilyTreeNodeEx3 *root) {
    if (root->name == parentName) {
        return root;
    }
    FamilyTreeNodeEx3 *parent = NULL;
    FamilyTreeNodeEx3 *curPerson = root->subling;
    while (curPerson != NULL) {
        parent = findParentByNameEx3(parentName, curPerson);
        if (parent != NULL) break;
        curPerson = curPerson->subling;
    }
    if (parent != NULL) return parent;
    curPerson = root ->eldestChildren;
    while (curPerson != NULL) {
        parent = findParentByNameEx3(parentName, curPerson);
        if (parent != NULL) break;
        curPerson = curPerson->subling;
    }
    return parent;
}
