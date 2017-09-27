
#include "familytree.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "error.h"
#include "strlib.h"



FamilyTreeNode::FamilyTreeNode(const std::string &name) {
    this->name = name;
    parent = NULL;
}

std::string FamilyTreeNode::getName() const {
    return name;
}

void FamilyTreeNode::addChild(FamilyTreeNode *child) {
    children.add(child);
    child->parent = this;
}

FamilyTreeNode *FamilyTreeNode::getParent() const {
  return parent;
}

Vector<FamilyTreeNode *> FamilyTreeNode::getChildren() const {
    return children;
}
