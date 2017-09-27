
#include "console.h"
#include "simpio.h"  // for getLine
#include <iomanip>
#include "set.h"
#include "grid.h"
#include "exercise13.h"
#include "random.h"
using namespace std;



using namespace std;
//func prototypes
void printVectEx13(Vector<int> & vect);
int findMajorityElement(Vector<int> & vect);

//general
void exercise13() {
    //Vector<int> vect {56,25,37,58,95,19,73,30};
    //Vector<int> vect {1,1,1,1,1,19,73,30};
    Vector<int> vect {1,2,1,1,3,1,5,1,44,1,1,19,73,1,30};
    int majorNumber = findMajorityElement(vect);
    cout << majorNumber << endl;

}

int findMajorityElement(Vector<int> & vect) {

    int majIndex = 0;
    int count = 1;
    for (int i = 1; i < vect.size(); i++) {
        if (vect[majIndex] == vect[i]) {
            count++;
        } else {
            count--;
        }
        if (count == 0) {
            majIndex = i;
            count = 1;
        }
    }

    int size = vect.size();
    int countOfElements = 0;
    int sum = 0;
    for (int i = 0; i < vect.size(); i++) {
        if (vect[i] == vect[majIndex]) {
           countOfElements++;
        }
    }
    if (countOfElements >= (size / 2 + 1)) {
        return vect[majIndex];
    } else {
        return -1;
    }

}


void printVectEx13(Vector<int> & vect) {
    for (int tmp : vect) {
        cout << tmp << " ";
    }
    cout << endl;
}
