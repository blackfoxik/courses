#ifndef _familytree_h
#define _familytree_h
#include <string>
#include "vector.h"

class FamilyTreeNode {
public:
    FamilyTreeNode(const std::string & name);
    std::string getName() const;
    void addChild(FamilyTreeNode *child);
    FamilyTreeNode *getParent() const;
    Vector<FamilyTreeNode *> getChildren() const;
private:
    std::string name;
    FamilyTreeNode *parent;
    Vector<FamilyTreeNode *> children;
};

#endif

