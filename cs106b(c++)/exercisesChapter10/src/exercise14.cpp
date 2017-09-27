
#include "console.h"
#include "simpio.h"  // for getLine
#include <iomanip>
#include "set.h"
#include "grid.h"
#include "exercise14.h"
#include "random.h"
using namespace std;



using namespace std;
//func prototypes
void printVectEx14(Vector<int> & vect);
int findDuplicate(Vector<int> & vect);

//general
void exercise14() {
    Vector<int> vect {56,25,37,58,95,19,73,30};
    //Vector<int> vect {5,19,73,5,30};
    //Vector<int> vect {1,2,1,1,3,1,5,1,44,1,1,19,73,1,30};
    int duplicateNumber = findDuplicate(vect);
    cout << duplicateNumber << endl;

}

int findDuplicate(Vector<int> & vect) {

    int dupIndex = 0;
    for (int i = 1; i < vect.size(); i++) {
        if (vect[dupIndex] == vect[i] && dupIndex != i) {
            return vect[i];
        }
        if (i == vect.size() - 1 && dupIndex < vect.size() - 1) {
            dupIndex++;
            i = 0;
        }
    }
    return -1;
}


void printVectEx14(Vector<int> & vect) {
    for (int tmp : vect) {
        cout << tmp << " ";
    }
    cout << endl;
}
