#include "console.h"
#include "simpio.h"  // for getLine
#include "stack.h"
#include "familytree.h"
#include "exercise4.h"
using namespace std;



void exercise4() {
    FamilyTreeNode w1("William I");
    FamilyTreeNode s1("Seba I");
    w1.addChild(&s1);
    cout << w1.getName() << endl;
}


