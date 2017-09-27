
#include "console.h"
#include "simpio.h"  // for getLine
#include "set.h"
#include "grid.h"
#include "exercise4.h"
using namespace std;

//func prototypes
void fillRegion(Grid<bool> & pixels, int row, int col);
void printGrid(Grid<bool> & pict);
void preparePict(Grid<bool> & pict);

void exercise4() {
 Grid<bool> pict(10,10);
 preparePict(pict);
 printGrid(pict);

 //fillRegion(pict,0,0);// fill outside
 fillRegion(pict,6,5);//fill inside
 printGrid(pict);
}

void fillRegion(Grid<bool> & pixels, int row, int col) {
    if (row >= pixels.height() || row < 0 || col >= pixels.width() || col < 0 || pixels[row][col] == true) {
        return;
    }
    pixels[row][col] = true;

    fillRegion(pixels, row + 1, col);
    fillRegion(pixels, row, col + 1);
    fillRegion(pixels, row - 1, col);
    fillRegion(pixels, row, col - 1);
}

void printGrid(Grid<bool> & pict) {
    cout << endl;
    for (int i = 0 ; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << pict.get(i,j) ;
        }
        cout << endl;
    }
}

void preparePict(Grid<bool> & pict) {
    for (int i = 0 ; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            pict[i][j] = false;
        }
    }

    pict[8][2] = true;
    pict[8][3] = true;
    pict[8][4] = true;
    pict[8][5] = true;
    pict[8][6] = true;
    pict[7][6] = true;
    pict[6][6] = true;
    pict[5][6] = true;
    pict[4][6] = true;
    pict[8][2] = true;
    pict[7][2] = true;
    pict[6][2] = true;
    pict[5][3] = true;
    pict[4][4] = true;
    pict[4][5] = true;
}
