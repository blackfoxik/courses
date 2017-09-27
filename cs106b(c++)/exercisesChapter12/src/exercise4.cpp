#include "exercise4.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "intarray.h"
#include <cassert>



using namespace std;



//prototypes

void printAr(IntArray ar) {
    for (int i = 0; i < 5; i++) {
        cout << ar.get(i) << endl;
    }
}

void exercise4() {
    IntArray ar(5);
    assert(ar.size() == 5);
    ar.put(1,11);
    ar.put(2,12);
    assert(ar.get(1) == 11);
    cout << ar.get(1) << endl << endl;
    cout << ar[2] << endl << endl;
    printAr(ar);

}



