#include "console.h"
#include "simpio.h"  // for getLine
#include "set.h"
#include "grid.h"
#include "exercise8.h"
using namespace std;

const char EMPTY_SQUARE = '.';
const char BUSY_SQUARE = '*';
const char CORNER_SQUARE = 'X';
const int SIZE = 7;
const int CENTER = 3;

enum Directions {WEST, EAST, SOUTH, NORTH};

//prototypes
void printGridEx8(Grid<char> & board);
void prepareEmptyBoardEx8(Grid<char> & board);
bool isSolitairyComplete(Grid<char> & board, int countOfPegs);
bool isPointBusy(Grid<char> &board, int posX, int posY);
bool isPointInEdge(Grid<char> &board, int posX, int posY);
bool isStartPositionOk(Grid<char> &board, int startPosX, int startPosY);
bool isMidPositionOk(Grid<char> &board, int midPosX, int midPosY);
bool isFinPositionOk(Grid<char> &board, int finPosX, int finPosY);
bool makeMove(Grid<char> &board, Directions curDirection, int startPosX, int startPosY);
bool solvePegSolitairy(Grid<char> &board, int & countOfPegs);


void exercise8() {
 Grid<char> board(SIZE,SIZE);
 prepareEmptyBoardEx8(board);
 printGridEx8(board);

 int countOfPeg = 32;
 solvePegSolitairy(board, countOfPeg);
 printGridEx8(board);
}



bool solvePegSolitairy(Grid<char> &board, int & countOfPegs) {
    if (isSolitairyComplete(board,countOfPegs)) {
        return true;
    }

    Grid<char> curBoard = board;
    //cout << countOfPegs << endl;
    //printGridEx8(board);
    int prevCountOfPeg = countOfPegs;

    for (int i = 0; i < board.height(); i++) {
        for (int j = 0; j < board.width(); j++) {
            if (makeMove(curBoard, WEST, j, i )) {
                prevCountOfPeg -= 1;
                if (solvePegSolitairy(curBoard, prevCountOfPeg)) {
                    printGridEx8(board);
                    board = curBoard;
                    return true;
                }
            }
            curBoard = board;
            prevCountOfPeg = countOfPegs;
            if (makeMove(curBoard, EAST, j, i )) {
                prevCountOfPeg -= 1;
                if (solvePegSolitairy(curBoard, prevCountOfPeg)) {
                    printGridEx8(board);
                    board = curBoard;
                    return true;
                }
            }
            curBoard = board;
            prevCountOfPeg = countOfPegs;
            if (makeMove(curBoard, NORTH, j, i)) {
                prevCountOfPeg -= 1;
                if (solvePegSolitairy(curBoard, prevCountOfPeg)) {
                    printGridEx8(board);
                    board = curBoard;
                    return true;
                }
            }
            curBoard = board;
            prevCountOfPeg = countOfPegs;
            if (makeMove(curBoard, SOUTH, j, i)) {
                prevCountOfPeg -= 1;
                if (solvePegSolitairy(curBoard, prevCountOfPeg)) {
                    printGridEx8(board);
                    board = curBoard;
                    return true;
                }
            }
        }
    }
    return false;
}


bool makeMove(Grid<char> &board, Directions curDirection, int startPosX, int startPosY) {
    if (!isStartPositionOk(board, startPosX, startPosY)) return false;
    int midPosX;
    int finPosX;
    int midPosY;
    int finPosY;
    if (curDirection == EAST) {
       midPosX = startPosX + 1;
       finPosX = startPosX + 2;
       midPosY = startPosY;
       finPosY = startPosY;
    } else if (curDirection == WEST) {
        midPosX = startPosX - 1;
        finPosX = startPosX - 2;
        midPosY = startPosY;
        finPosY = startPosY;
    } else if (curDirection == NORTH) {
        midPosX = startPosX;
        finPosX = startPosX;
        midPosY = startPosY - 1;
        finPosY = startPosY - 2;
    } else if (curDirection == SOUTH) {
        midPosX = startPosX;
        finPosX = startPosX;
        midPosY = startPosY + 1;
        finPosY = startPosY + 2;
    }

    if (!isMidPositionOk(board, midPosX, midPosY)) return false;
    if (!isFinPositionOk(board, finPosX, finPosY)) return false;

       board[startPosX][startPosY] = EMPTY_SQUARE;
       board[midPosX][midPosY] = EMPTY_SQUARE;
       board[finPosX][finPosY] = BUSY_SQUARE;
       return true;
}

bool isStartPositionOk(Grid<char> &board, int startPosX, int startPosY) {

    if (!isPointInEdge(board, startPosX, startPosY)) return false;
    if (!isPointBusy(board, startPosX, startPosY)) return false;
    return true;
}

bool isMidPositionOk(Grid<char> &board, int midPosX, int midPosY) {

    if (!isPointInEdge(board, midPosX, midPosY)) return false;
    if (!isPointBusy(board, midPosX, midPosY)) return false;
    return true;
}

bool isFinPositionOk(Grid<char> &board, int finPosX, int finPosY) {

    if (!isPointInEdge(board, finPosX, finPosY)) return false;
    if (isPointBusy(board, finPosX, finPosY)) return false;
    return true;
}

bool isPointInEdge(Grid<char> &board, int posX, int posY) {
    if (posX >= 0 && posX <= board.height() - 1 && posY >= 0 && posY <= board.width() - 1 && board[posX][posY] != 'X') {
        return true;
    } else {
        return false;
    }
}

bool isPointBusy(Grid<char> &board, int posX, int posY) {
    if(board[posX][posY] == BUSY_SQUARE) {
        return true;
    } else {
        return false;
    }
}

bool isSolitairyComplete(Grid<char> & board, int countOfPegs) {
    if (countOfPegs <= 1 && board[CENTER][CENTER] == BUSY_SQUARE) {
       return true;
    } else {
        return false;
    }

}

void prepareEmptyBoardEx8(Grid<char> & board) {
    for (int i = 0 ; i < board.height(); i++) {
        for (int j = 0; j < board.width(); j++) {
            board[i][j] = BUSY_SQUARE;
        }
    }
    board[3][3] = EMPTY_SQUARE;
    board[0][0] = board[0][1] = board[1][0] = board[1][1] =
    board[0][5] = board[1][5] = board[0][6] = board[1][6] =
    board[5][0] = board[6][0] = board[5][1] = board[6][1] =
    board[5][5] = board[6][5] = board[5][6] = board[6][6] = CORNER_SQUARE;

}


void printGridEx8(Grid<char> & board) {
    cout << endl;
    for (int i = 0 ; i < board.height(); i++) {
        for (int j = 0; j < board.width(); j++) {
            cout << board.get(j,i) ;
        }
        cout << endl;
    }


}
