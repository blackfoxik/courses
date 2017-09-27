#include <iostream>
#include <string>
#include "error.h"
#include "simpio.h"
#include "strlib.h"
#include "vector.h"

using namespace std;

/*
const Vector<int> N_Coins_IN_N_ROW {3,4,5};
const int WINNING_POSITION = 2;
const int LOSING_POSITION = - WINNING_POSITION;
enum Player { HUMAN, COMPUTER };

Player opponent(Player player) {
    return (player == HUMAN) ? COMPUTER : HUMAN;
}

struct Move {
    int nTaken;
    int nRow;
};

const Player STARTING_PLAYER = HUMAN;

class SimpleNim {
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
        cout << "Welcome to the game of Nim!" << endl;
    }
private:

Move findBestMove() {
        int rating;
        return findBestMove(rating);
    }

Move findBestMove(int & rating) {
    Vector<Move> moveList;
    Move bestMove;
    int minRating = WINNING_POSITION + 1;
    generateMoveList(moveList);
    if (moveList.isEmpty()) error("No moves available");
    for (Move move : moveList) {
        makeMove(move);
        int moveRating = evaluatePosition();
        if (moveRating < minRating) {
            bestMove = move;
            minRating = moveRating;
        }
        retractMove(move);
    }
    rating = -minRating;
    return bestMove;
}

int evaluatePosition() {
    if (gameIsOver()) {
        return evaluateStaticPosition();
    }
    int rating;
    findBestMove(rating);
    return rating;
}

int evaluateStaticPosition() {
    if (getCurrentPlayer() == HUMAN) {
        return LOSING_POSITION;
    } else {
        return WINNING_POSITION;
    }
}

void generateMoveList(Vector<Move> & moveList) {
    for (int i = 0; i < pile.size(); i++) {
        int limit = pile[i];
        for (int j = 1; j <= limit; j++) {
            Move curMove;
            curMove.nRow = i;
            curMove.nTaken = j;
            moveList.add(curMove);
        }
    }
}

void retractMove(Move move) {
    int result = pile[move.nRow] + move.nTaken;
    pile[move.nRow] = result;
}

void initGame() {
  pile = N_Coins_IN_N_ROW;
  whoseTurn = STARTING_PLAYER;
}

bool gameIsOver() {
    for (int i = 0; i < pile.size(); i++) {
        if (pile[i] > 0) return false;
    }
    return true;
}

void displayGame() {
   cout << "There are " << pile.size() << " row(s) of coins in the pile." << endl;
   for (int i = 1; i <= pile.size(); i++) {
       cout << "Row " << i << " consist " << pile[i - 1] << " coins." << endl;
   }
}

Player getCurrentPlayer() {
    return whoseTurn;
}

void makeMove(Move move) {
  int result = pile[move.nRow] - move.nTaken;
  pile[move.nRow] = result;
}

void displayMove(Move &move) {
   cout << "I'll take " << move.nTaken << " from "<< move.nRow + 1 << " row." << endl;
}

void switchTurn() {
    whoseTurn = opponent(whoseTurn);
}

Move getComputerMove() {
    Move compMove = findBestMove();
    return compMove;
}

Move getUserMove() {
    Move userMove;
    while (true) {
        int nRow = getInteger("From which row would you like to take? ");

        if (nRow < 0 || nRow > pile.size()) {
            cout << "Illegal number of row, try again!" << endl;
            continue;
        }
        nRow -= 1;
        int nTaken = getInteger("How many would you like? ");
        int limit = pile[nRow];
        if (nTaken > 0 && nTaken <= limit) {
            userMove.nTaken = nTaken;
            userMove.nRow = nRow;
            return userMove;
        }
        cout << "That's cheating! Please choose a number";
        cout << "between 1 and " << limit << "." << endl;
        cout << "There are " << pile[nRow] << " coins in the pile." << endl;
    }
}

void announceResult() {
        if (whoseTurn == COMPUTER) {
            cout << "I win." << endl;
        } else {
            cout << "I lose." << endl;
        }

}


Vector<int> pile;
Player whoseTurn;
};
*/
