#include "console.h"
#include "simpio.h"  // for getLine
#include <iomanip>
#include "set.h"
#include "grid.h"
#include "exercise6.h"
using namespace std;

const string EMPTY_SQUARE = ".";
const int SIZE = 5;

//func prototypes
void prepareEmptyBoardEx6(Grid<string> & board);
void printGridEx6(Grid<string> & board);
bool findKnightTour(Grid<string> & board, int r, int c, int curStep);
void findKnightTour(Grid<string> &board);


void exercise6() {
 //I used 5x5 because 8x8 took a lot of time
 Grid<string> board(SIZE,SIZE);
 prepareEmptyBoardEx6(board);
 printGridEx6(board);
 findKnightTour(board);
 printGridEx6(board);
}

void prepareEmptyBoardEx6(Grid<string> & board) {
    for (int i = 0 ; i < board.height(); i++) {
        for (int j = 0; j < board.width(); j++) {
            board[i][j] = EMPTY_SQUARE;
        }
    }
}

void printGridEx6(Grid<string> & board) {
    cout << endl;
    cout << "\n - - - - - - - - - - - - -\n";
    for (int i = 0 ; i < board.height(); i++) {
        cout << "| ";
        for (int j = 0; j < board.width(); j++) {
            if (board.get(i,j) == ".") {
                cout << setw(2)  << " " << " | ";
            } else {
                cout << setw(2)  << board.get(i,j) << " | ";
            }
        }
        cout << "\n - - - - - - - - - - - - -\n";
        //cout << endl;
    }
}

bool findKnightTour(Grid<string> & board, int r, int c, int curStep) {

    if (curStep == SIZE * SIZE + 1) {
        return true;
    }

    if (r > board.height() - 1 || r < 0 || c > board.width() - 1 || c < 0) {
        return false;
    }

    if (board[r][c] != EMPTY_SQUARE) {
        return false;
    }


    board[r][c] = std::to_string(curStep);

    if (findKnightTour(board, r - 2, c + 1, curStep + 1)) {
        return true;
    }

    if (findKnightTour(board, r - 2, c - 1, curStep + 1)) {
        return true;
    }

    if (findKnightTour(board, r - 1, c + 2, curStep + 1)) {
        return true;
    }
    if (findKnightTour(board, r + 1, c + 2, curStep + 1)) {
        return true;
    }
    if (findKnightTour(board, r + 2, c + 1, curStep + 1)) {
        return true;
    }
    if (findKnightTour(board, r + 2, c - 1, curStep + 1)) {
        return true;
    }
    if (findKnightTour(board, r + 1, c - 2, curStep + 1)) {
        return true;
    }
    if (findKnightTour(board, r - 1, c - 2, curStep + 1)) {
        return true;
    }
    board[r][c] = EMPTY_SQUARE;
    return false;
}

void findKnightTour(Grid<string> &board) {
    findKnightTour(board, SIZE - 1, 0, 1);
}
