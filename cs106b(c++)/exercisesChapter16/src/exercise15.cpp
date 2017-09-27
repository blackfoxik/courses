#include "exercise15.h"
#include <cmath>
#include "gwindow.h"
#include "random.h"
#include "lexicontree.h"


using namespace std;

//general
void exercise15() {
    //class was implemented as a simplified just to understand the main idea
    LexiconTree l;
    l.addWord("cat");
    l.addWord("cab");
    l.addWord("carbon");
    cout<< l.contains("cat") << endl;
    cout<< l.contains("cab") << endl;
    cout<< l.contains("carbon") << endl;
    cout<< l.contains("car") << endl;
    cout<< l.contains("bat") << endl;
}

