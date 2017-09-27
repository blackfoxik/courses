#include <iostream>
#include <string>
#include "error.h"
#include "simpio.h"
#include "strlib.h"
#include "vector.h"
/*
using namespace std;

const int N_COINS = 13;
const int MAX_MOVE = 3;

const int MAX_DEPTH = 9;
const int WINNING_POSITION = 2;
const int LOSING_POSITION = - WINNING_POSITION;
enum Player { HUMAN, COMPUTER };

Player opponent(Player player) {
    return (player == HUMAN) ? COMPUTER : HUMAN;
}

struct Move {
    int nTaken;
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
        return findBestMove(0, rating);
    }

Move findBestMove(int depth, int & rating) {
    Vector<Move> moveList;
    Move bestMove;
    int minRating = WINNING_POSITION + 1;
    generateMoveList(moveList);
    if (moveList.isEmpty()) error("No moves available");
    for (Move move : moveList) {
        makeMove(move);
        int moveRating = evaluatePosition(depth + 1);
        if (moveRating < minRating) {
            bestMove = move;
            minRating = moveRating;
        }
        retractMove(move);
    }
    rating = -minRating;
    return bestMove;
}

int evaluatePosition(int depth) {
    if (gameIsOver() || depth >= MAX_DEPTH) {
        return evaluateStaticPosition();
    }
    int rating;
    findBestMove(depth, rating);
    return rating;
}

int evaluateStaticPosition() {
    if (getCurrentPlayer() == HUMAN) {
       return WINNING_POSITION;
    } else {
       return LOSING_POSITION;
    }
}

void generateMoveList(Vector<Move> & moveList) {
    int limit = (nCoins < MAX_MOVE) ? nCoins : MAX_MOVE;
    for (int i = 1; i <= limit; i++) {
        Move curMove;
        curMove.nTaken = i;
        moveList.add(curMove);
    }
}

void retractMove(Move move) {
    nCoins += move.nTaken;
}

void initGame() {
  nCoins = N_COINS;
  whoseTurn = STARTING_PLAYER;
}

bool gameIsOver() {
    return nCoins <= 1;
}

void displayGame() {
   cout << "There are " << nCoins << " coins in the pile." << endl;
}

Player getCurrentPlayer() {
    return whoseTurn;
}

void makeMove(Move move) {
  nCoins -= move.nTaken;
}

void displayMove(Move &move) {
   cout << "I'll take " << move.nTaken << "." << endl;
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
        int nTaken = getInteger("How many would you like? ");
        int limit = (nCoins < MAX_MOVE) ? nCoins : MAX_MOVE;
        if (nTaken > 0 && nTaken <= limit) {
            userMove.nTaken = nTaken;
            return userMove;
        }
        cout << "That's cheating! Please choose a number";
        cout << "between 1 and " << limit << "." << endl;
        cout << "There are " << nCoins << " coins in the pile." << endl;
    }
}

void announceResult() {
    if (nCoins == 0) {
        cout << "You took the last coin. You lose." << endl;
    } else {
        cout << "There is only one coin left." << endl;
        if (whoseTurn == HUMAN) {
            cout << "I win." << endl;
        } else {
            cout << "I lose." << endl;
        }
    }
}

int nCoins;
Player whoseTurn;
};
*/
