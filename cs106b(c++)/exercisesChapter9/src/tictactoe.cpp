#include <iostream>
#include <string>
#include "error.h"
#include "simpio.h"
#include "strlib.h"
#include "vector.h"
#include "set.h"
#include "grid.h"
#include <iomanip>
using namespace std;



const char HUMAN_SIGN = 'O';
const char COMPUTER_SIGN = 'X';

const int MAX_DEPTH = 8;
const int WINNING_POSITION = 2;
const int LOSING_POSITION = - WINNING_POSITION;
enum Player { HUMAN, COMPUTER };

Player opponent(Player player) {
    return (player == HUMAN) ? COMPUTER : HUMAN;
}

struct Move {
    char sign;
    int nSquare;
};

struct Square {
    int nRow;
    int nCol;
};

const Player STARTING_PLAYER = COMPUTER;

class TicTacToe {
public:
    void play() {
        initGame();
        while (!gameIsOver()) {
            displayGame();
            if (getCurrentPlayer() == HUMAN) {
                makeMove(getUserMove());
            } else {
                Move move = getComputerMove();
                displayMove(move);
                makeMove(move);
            }
            switchTurn();
        }
        announceResult();
    }
    void printInstructions() {
        cout << "Welcome to TicTacToe, the game of three in a row." << endl;
        cout << "I will be "<< COMPUTER_SIGN << " you will be " << HUMAN_SIGN << endl;
        cout << "The squares are numbered like this:" << endl;
        printBoardWithNumbers();
    }
private:
    void printBoardWithNumbers() {

        for (int i = 0; i < board.nRows; i++) {
            for (int j = 0; j < board.nCols; j++) {
                cout << setw(2) << board[i][j];
                if (j % 2 == 0 && j != 0) {
                    cout << endl;
                } else {
                    cout << " |";
                }
            }
            if ( i != 2) cout << "-----------" << endl;
        }
    }
    void printBoard() {

        for (int i = 0; i < board.nRows; i++) {
            for (int j = 0; j < board.nCols; j++) {
                if (board[i][j] == COMPUTER_SIGN || board[i][j] == HUMAN_SIGN) {
                    cout << setw(2) << board[i][j];
                } else {
                    cout << setw(2) << " ";
                }
                if (j % 2 == 0 && j != 0) {
                    cout << endl;
                } else {
                    cout << " |";
                }
            }
            if ( i != 2) cout << "-----------" << endl;
        }
        cout << endl;
    }

    Move findBestMove() {
        int rating;
        return findBestMove(0, rating, COMPUTER);
    }

Move findBestMove(int depth, int & rating, Player curPlayer) {
    Vector<Move> moveList;
    Move bestMove;
    int minRating = WINNING_POSITION + 1;
    generateMoveList(moveList, curPlayer);
    if (moveList.isEmpty()) error("No moves available");
    for (Move move : moveList) {
        makeMove(move);
        int moveRating = evaluatePosition(depth + 1, curPlayer);
        if (moveRating < minRating) {
            bestMove = move;
            minRating = moveRating;
        }
        retractMove(move);
    }
    rating = -minRating;
    return bestMove;
}

int evaluatePosition(int depth, Player curPlayer) {
    if (gameIsOver() || depth >= MAX_DEPTH) {
        return evaluateStaticPosition();
    }
    int rating;
    //cout << depth << endl;
    //printBoard();

    curPlayer = opponent(curPlayer);
    findBestMove(depth, rating, curPlayer);
    return rating;
}

int evaluateStaticPosition() {
    if (getCurrentPlayer() == HUMAN) {
        printBoard();
        return WINNING_POSITION;

    } else{
        printBoard();
       return LOSING_POSITION;
    }
}

void generateMoveList(Vector<Move> & moveList, Player curPlayer) {
    for (int i = 1; i <= board.nRows * board.nCols; i++) {
        if (canMoveAtSquare(i)) {
            Move curMove;
            curMove.nSquare = i;
            curMove.sign = (curPlayer == HUMAN) ? HUMAN_SIGN : COMPUTER_SIGN;
            moveList.add(curMove);
        }
    }
}

void retractMove(Move move) {
    Square curSquare = getSquareByNumber(move.nSquare);
    board[curSquare.nRow][curSquare.nCol] = move.nSquare;
}

void initGame() {
  whoseTurn = STARTING_PLAYER;
}

void fillSetByWinCombinations(Vector< Set<char> > & winCombination) {
    //rows
    for (int i = 0; i < board.nRows; i++) {
        Set<char> curSet;
        for (int j = 0; j < board.nCols; j++) {
            curSet.add(board[i][j]);
        }
        winCombination.add(curSet);
    }
    //colums
    for (int i = 0; i < board.nCols; i++) {
        Set<char> curSet;
        for (int j = 0; j < board.nRows; j++) {
            curSet.add(board[j][i]);
        }
        winCombination.add(curSet);
    }

    Set<char> c1;
    c1.add(board[0][0]);
    c1.add(board[1][1]);
    c1.add(board[2][2]);
    winCombination.add(c1);


    Set<char> c2;
    c2.add(board[2][0]);
    c2.add(board[1][1]);
    c2.add(board[0][2]);
    winCombination.add(c2);
}

char winner(Vector< Set<char> > & combinations) {
    for (Set<char> curComb : combinations) {
       if (curComb.size() == 1) return curComb.first();
    }
    return 'N';
}

char winner() {
    Vector< Set<char> > winCombinations;
    fillSetByWinCombinations(winCombinations);
    return winner(winCombinations);
}

bool isThereWinner() {
    Vector< Set<char> > winCombinations;
    fillSetByWinCombinations(winCombinations);
    if (winner(winCombinations) != 'N') {
        return true;
    }
    return false;
}

bool isBoardFull() {
    for (int i = 0; i < board.nRows; i++) {
        for (int j = 0; j < board.nCols; j++) {
            char curSign = board[i][j];
            if (curSign != COMPUTER_SIGN && curSign != HUMAN_SIGN) return false;
        }
    }
    return true;
}

bool gameIsOver() {
    //if there is line with three same signs
    if (isThereWinner()) {
        return true;
    }
    if (isBoardFull()) {
        return true;
    }
    return false;
}

void displayGame() {
   cout << "The game looks like this:" << endl;
   printBoard();
}

Player getCurrentPlayer() {
    return whoseTurn;
}

void makeMove(Move move) {
  Square curSquare = getSquareByNumber(move.nSquare);
  board[curSquare.nRow][curSquare.nCol] = move.sign;
  //nCoins -= move.nTaken;
}

void displayMove(Move &move) {
   cout << "I'll move to " << move.nSquare << "." << endl;
}

void switchTurn() {
    whoseTurn = opponent(whoseTurn);
}

Move getComputerMove() {
    Move compMove = findBestMove();
    return compMove;
}

Square getSquareByNumber (int squareNuber) {
    Square result;
    switch (squareNuber) {
    case 1:
        result.nRow = 0;
        result.nCol = 0;
        return result;

    case 2:
        result.nRow = 0;
        result.nCol = 1;
        return result;

    case 3:
        result.nRow = 0;
        result.nCol = 2;
        return result;

    case 4:
        result.nRow = 1;
        result.nCol = 0;
        return result;

    case 5:
        result.nRow = 1;
        result.nCol = 1;
        return result;

    case 6:
        result.nRow = 1;
        result.nCol = 2;
        return result;

    case 7:
        result.nRow = 2;
        result.nCol = 0;
        return result;

    case 8:
        result.nRow = 2;
        result.nCol = 1;
        return result;

    case 9:
        result.nRow = 2;
        result.nCol = 2;
        return result;

    default :
        result.nRow = -1;
        result.nCol = -1;
        return result;

    }
}

char getCharAtBoard(Square & square) {
    return board[square.nRow][square.nCol];
}

bool canMoveAtSquare(int numSquare) {
    Square square = getSquareByNumber(numSquare);
    if (square.nCol == -1) {
        return false;
    }
    char curSign = getCharAtBoard(square);
    if (curSign == COMPUTER_SIGN || curSign == HUMAN_SIGN) {
        return false;
    }
    return true;
}

Move getUserMove() {
    Move userMove;
    while (true) {
        cout << "Your move" << endl;
        int numSquare = getInteger("What square? ");

        if (canMoveAtSquare(numSquare)) {
            userMove.nSquare = numSquare;
            userMove.sign = HUMAN_SIGN;
            return userMove;
        }

        cout << "That's cheating! Please choose a right square!";
    }
}

void announceResult() {

    cout << endl;
    printBoard();
    if (winner() == HUMAN_SIGN) {
       cout << "I lose." << endl;
    } else if (winner() == COMPUTER_SIGN) {
       cout << "I win." << endl;
    } else {
        cout << "Draw." << endl;
    }

}


Grid<char> board{{'1','2','3'},{'4','5','6'},{'7','8','9'}};
Player whoseTurn;
};


