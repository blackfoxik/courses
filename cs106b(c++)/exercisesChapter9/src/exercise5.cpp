#include "console.h"
#include "simpio.h"  // for getLine
#include "set.h"
#include "grid.h"
#include "exercise5.h"
using namespace std;

const char EMPTY_SQUARE = '.';
const char QUEEN = 'Q';
const char SQUARE_UNDER_ATTACK = '*';

//func prototypes
void printGrid(Grid<char> & board);
void prepareEmptyBoard(Grid<char> & board);
void markDownVerticalAttackLines(Grid<char> & board,int row, int col);
void markUpVerticalAttackLines(Grid<char> & board,int row, int col);
void markLeftHorizontalAttackLines(Grid<char> & board,int row, int col);
void markRightHorizontalAttackLines(Grid<char> & board,int row, int col);
void markTopRightAngleAttackLines(Grid<char> & board,int row, int col);
void markTopLeftAngleAttackLines(Grid<char> & board,int row, int col);
void markBottomRightAngleAttackLines(Grid<char> & board,int row, int col);
void markBottomLeftAngleAttackLines(Grid<char> & board,int row, int col);
void markVerticalAttackLines (Grid<char> & board,int row, int col);
void markHorizontalAttackLines (Grid<char> & board,int row, int col);
void markAngleAttackLines (Grid<char> & board,int row, int col);
void markAttackLines(Grid<char> & board,int row, int col);
bool putQueensOnBoard(Grid<char> & board, int countOfQueens);




void exercise5() {
     int size = getInteger("Enter size of board: ");
     int countOfQueens = getInteger("How many Queens do you want to put on the board: ");
     Grid<char> board(size,size);
     prepareEmptyBoard(board);

     printGrid(board);
     if(putQueensOnBoard(board, countOfQueens)) {
        printGrid(board);
     } else {
        cout << "There is no solution to put " << countOfQueens << " Queen(s) on the board with size " << size << "X" << size << endl;
     }

}

bool putQueensOnBoard(Grid<char> & board, int countOfQueens) {
    if (countOfQueens == 0) {
        return true;
    }
    Grid<char> copyBoard = board;
    for (int i = 0; i < copyBoard.height(); i ++) {
        for(int j = 0; j < copyBoard.width(); j++) {
            if(copyBoard[i][j] == EMPTY_SQUARE) {
               copyBoard[i][j] = QUEEN;
               markAttackLines(copyBoard,i,j);
               printGrid(copyBoard);
               if (putQueensOnBoard(copyBoard, countOfQueens - 1)) {
                   board = copyBoard;
                   return true;
               }
               copyBoard = board;
            }
        }
    }
    return false;
}

void printGrid(Grid<char> & board) {
    cout << endl;
    for (int i = 0 ; i < board.height(); i++) {
        for (int j = 0; j < board.width(); j++) {
            cout << board.get(i,j) ;
        }
        cout << endl;
    }
}

void prepareEmptyBoard(Grid<char> & board) {
    for (int i = 0 ; i < board.height(); i++) {
        for (int j = 0; j < board.width(); j++) {
            board[i][j] = EMPTY_SQUARE;
        }
    }
}

void markDownVerticalAttackLines(Grid<char> & board,int row, int col) {
    if (row > board.height() - 1 || row < 0) {
        return;
    }
    board[row][col] = SQUARE_UNDER_ATTACK;
    markDownVerticalAttackLines(board, row + 1, col);
}

void markUpVerticalAttackLines(Grid<char> & board,int row, int col) {
    if (row > board.height() - 1 || row < 0) {
        return;
    }
    board[row][col] = SQUARE_UNDER_ATTACK;
    markUpVerticalAttackLines(board, row - 1, col);
}

void markLeftHorizontalAttackLines(Grid<char> & board,int row, int col) {
    if (col > board.width() - 1 || col < 0) {
        return;
    }
    board[row][col] = SQUARE_UNDER_ATTACK;
    markLeftHorizontalAttackLines(board, row, col - 1);
}

void markRightHorizontalAttackLines(Grid<char> & board,int row, int col) {
    if (col > board.width() - 1 || col < 0) {
        return;
    }
    board[row][col] = SQUARE_UNDER_ATTACK;
    markRightHorizontalAttackLines(board, row, col + 1);
}

void markTopRightAngleAttackLines(Grid<char> & board,int row, int col) {
    if (col > board.width() - 1 || col < 0 || row > board.height() - 1 || row < 0) {
        return;
    }
    board[row][col] = SQUARE_UNDER_ATTACK;
    markTopRightAngleAttackLines(board, row - 1, col + 1);
}

void markTopLeftAngleAttackLines(Grid<char> & board,int row, int col) {
    if (col > board.width() - 1 || col < 0 || row > board.height() - 1 || row < 0) {
        return;
    }
    board[row][col] = SQUARE_UNDER_ATTACK;
    markTopLeftAngleAttackLines(board, row - 1, col - 1);
}

void markBottomRightAngleAttackLines(Grid<char> & board,int row, int col) {
    if (col > board.width() - 1 || col < 0 || row > board.height() - 1 || row < 0) {
        return;
    }
    board[row][col] = SQUARE_UNDER_ATTACK;
    markBottomRightAngleAttackLines(board, row + 1, col + 1);
}

void markBottomLeftAngleAttackLines(Grid<char> & board,int row, int col) {
    if (col > board.width() - 1 || col < 0 || row > board.height() - 1 || row < 0) {
        return;
    }
    board[row][col] = SQUARE_UNDER_ATTACK;
    markBottomLeftAngleAttackLines(board, row + 1, col - 1);
}

void markVerticalAttackLines (Grid<char> & board,int row, int col) {
    markUpVerticalAttackLines(board, row - 1, col);
    markDownVerticalAttackLines(board, row + 1, col);
}

void markHorizontalAttackLines (Grid<char> & board,int row, int col) {
    markLeftHorizontalAttackLines(board, row, col - 1);
    markRightHorizontalAttackLines(board, row, col + 1);
}

void markAngleAttackLines (Grid<char> & board,int row, int col) {
    markTopRightAngleAttackLines(board, row - 1, col + 1);
    markTopLeftAngleAttackLines(board, row - 1, col - 1);
    markBottomRightAngleAttackLines(board, row + 1, col + 1);
    markBottomLeftAngleAttackLines(board, row + 1, col - 1);
}

void markAttackLines(Grid<char> & board,int row, int col) {
    markVerticalAttackLines(board, row, col);
    markHorizontalAttackLines(board, row, col);
    markAngleAttackLines(board, row, col);
}
