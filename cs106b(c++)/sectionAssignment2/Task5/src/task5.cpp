#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "grid.h"
using namespace std;

int getCountOfBomb(int curRow, int curCol, Grid<bool> trueFalseGrid);
Grid<int> MakeGridOfCounts(Grid<bool> trueFalseGrid);
void showGrid(Grid<int> &countOfBombGrid);
void insertValues(Grid<bool> &trueFalseGrid);

int main() {
    Grid<bool> trueFalseGrid(6,6);
    insertValues(trueFalseGrid);
    Grid<int> countOfBombGrid = MakeGridOfCounts(trueFalseGrid);
    showGrid(countOfBombGrid);
    return 0;
}

int getCountOfBomb(int curRow, int curCol, Grid<bool> trueFalseGrid){
    int curCountOfBomb = 0;
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            int neighbourRow = curRow + i;
            int neighbourCol = curCol + j;
            if(trueFalseGrid.inBounds(neighbourRow,neighbourCol)){
                if(trueFalseGrid[neighbourRow][neighbourCol]){
                    curCountOfBomb++;
                }
            }
        }
    }
    return curCountOfBomb;
}

Grid<int> MakeGridOfCounts(Grid<bool> trueFalseGrid){
    Grid<int> countOfBombGrid(trueFalseGrid.numRows(),trueFalseGrid.numCols());
    for(int i = 0; i < trueFalseGrid.numRows(); i++){
        int curCountOfBomb = 0;
        for(int j = 0; j < trueFalseGrid.numCols(); j++){
            curCountOfBomb = getCountOfBomb(i,j,trueFalseGrid);
            countOfBombGrid[i][j] = curCountOfBomb;
        }
    }
    return countOfBombGrid;
}

void showGrid(Grid<int> &countOfBombGrid){
    for(int i = 0; i < countOfBombGrid.numRows(); i++){
        for(int j = 0; j < countOfBombGrid.numCols(); j++){
            cout << " " << countOfBombGrid[i][j] << " ";
        }
        cout << endl;
    }
}

void insertValues(Grid<bool> &trueFalseGrid){
    trueFalseGrid.set(0,0,true);
    trueFalseGrid.set(0,1,false);
    trueFalseGrid.set(0,2,false);
    trueFalseGrid.set(0,3,false);
    trueFalseGrid.set(0,4,false);
    trueFalseGrid.set(0,5,true);

    trueFalseGrid[1][0] = false;
    trueFalseGrid[1][1] = false;
    trueFalseGrid[1][2] = false;
    trueFalseGrid[1][3] = false;
    trueFalseGrid[1][4] = false;
    trueFalseGrid[1][5] = true;

    trueFalseGrid[2][0] = true;
    trueFalseGrid[2][1] = true;
    trueFalseGrid[2][2] = false;
    trueFalseGrid[2][3] = true;
    trueFalseGrid[2][4] = false;
    trueFalseGrid[2][5] = true;

    trueFalseGrid[3][0] = true;
    trueFalseGrid[3][1] = false;
    trueFalseGrid[3][2] = false;
    trueFalseGrid[3][3] = false;
    trueFalseGrid[3][4] = false;
    trueFalseGrid[3][5] = false;

    trueFalseGrid[4][0] = false;
    trueFalseGrid[4][1] = false;
    trueFalseGrid[4][2] = true;
    trueFalseGrid[4][3] = false;
    trueFalseGrid[4][4] = false;
    trueFalseGrid[4][5] = false;

    trueFalseGrid[5][0] = false;
    trueFalseGrid[5][1] = false;
    trueFalseGrid[5][2] = false;
    trueFalseGrid[5][3] = false;
    trueFalseGrid[5][4] = false;
    trueFalseGrid[5][5] = false;
}
