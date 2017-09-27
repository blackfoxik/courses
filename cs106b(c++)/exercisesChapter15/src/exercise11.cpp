#include "console.h"
#include "simpio.h"  // for getLine
#include "exercise11.h"
#include "gridex11.h"
#include "assert.h"
#include "grid.h"

//func prototypes


//general
void exercise11() {
    GridEx11<int> as(2,2,0);
    //as.nCols = 2;
    //as.nRows = 2;
    as.set(1,1,5);
    std::cout << as.get(1,1) << endl;
    std::cout << as(1,1) << endl;
    //std::cout << as[1][1] << endl;
    //as[1][] = 5;
    //as.nCols = 3;
    //std::cout << as[1][1] << endl;

    Grid<int> intSet(2,2,0);
    intSet.set(1,1,5);
    int a = intSet[1][1];
    std::cout << a << endl;
}





