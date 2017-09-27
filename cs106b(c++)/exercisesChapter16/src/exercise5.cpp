#include "console.h"
#include "simpio.h"  // for getLine
#include "stack.h"
#include "familytree.h"
#include "exercise5.h"
using namespace std;


FamilyTreeNode *commonAncestor(FamilyTreeNode * p1, FamilyTreeNode *p2);


void exercise5() {
    FamilyTreeNode w1("William I");
    FamilyTreeNode s1("Seba I");
    FamilyTreeNode w2("William II");
    w1.addChild(&s1);
    s1.addChild(&w2);
    FamilyTreeNode s2("Seba II");
    w1.addChild(&s2);
    FamilyTreeNode t2("Tor II");
    s2.addChild(&t2);
    FamilyTreeNode e2("Liza II");
    s2.addChild(&e2);
    cout << w1.getName() << endl;
    cout << commonAncestor(&t2,&w2)->getName() << endl;
    cout << commonAncestor(&e2,&t2)->getName() << endl;
    //t2 w2
}

FamilyTreeNode *commonAncestor(FamilyTreeNode * p1, FamilyTreeNode *p2) {
   FamilyTreeNode *match = NULL;
   FamilyTreeNode *par1 = p1;
   FamilyTreeNode *par2 = p2;
   while (match == NULL) {
       if (par1 == par2) {
           match = par1;
           break;
       }
       if (par1 == NULL) {
           par2 = par2->getParent();
           par1 = p1;
       }
       if (par1 == NULL && par2 == NULL) {
           break;
       }
       par1 = par1->getParent();
   }
   return match;
}
