/*#include <iostream>
#include <string>
#include "error.h"
#include "simpio.h"
#include "strlib.h"
#include "vector.h"
using namespace std;

const int N_COINS = 17;
const int MAX_MOVE = 4;

const int MAX_DEPTH = 19;
const int WINNING_POSITION = 2;
const int LOSING_POSITION = - WINNING_POSITION;
enum Player { HUMAN, COMPUTER };

Player opponentEx13(Player player) {
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
                makeMove(getUserMove(), getCurrentPlayer());
            } else {
                Move move = getComputerMove();
                displayMove(move);
                makeMove(move, getCurrentPlayer());
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
        return findBestMove(0, rating, COMPUTER);
    }

Move findBestMove(int depth, int & rating, Player curPlayer) {
    Vector<Move> moveList;
    Move bestMove;
    int minRating = WINNING_POSITION + 1;
    generateMoveList(moveList);
    if (moveList.isEmpty()) error("No moves available");
    for (Move move : moveList) {
        makeMove(move, curPlayer);
        int moveRating = evaluatePosition(depth + 1, curPlayer);
        if (moveRating < minRating) {
            bestMove = move;
            minRating = moveRating;
        }
        retractMove(move, curPlayer);
    }
    rating = -minRating;
    return bestMove;
}

void switchCurplayer(Player &curPlayer) {
    curPlayer = opponentEx13(curPlayer);
}

int evaluatePosition(int depth, Player curPlayer) {
    if (gameIsOver() || depth >= MAX_DEPTH) {
        return evaluateStaticPosition();
    }
    int rating;
    switchCurplayer(curPlayer);
    findBestMove(depth, rating, curPlayer);
    return rating;
}

int evaluateStaticPosition() {
    if (humanCoins %2 == 0) {
    //if (getCurrentPlayer() == HUMAN) {

       return LOSING_POSITION;
    } else {
       return WINNING_POSITION;
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

void retractMove(Move move, Player curPlayer) {
    nCoins += move.nTaken;
    if (curPlayer == HUMAN) {
      humanCoins -= move.nTaken;
    } else {
      compCoins -= move.nTaken;
    }
}

void initGame() {
  nCoins = N_COINS;
  whoseTurn = STARTING_PLAYER;
}

bool gameIsOver() {
    return nCoins == 0;
}

void displayGame() {
   cout << "There are " << nCoins << " coins in the pile. you have " << humanCoins << ". I have "<< compCoins << endl;
}

Player getCurrentPlayer() {
    return whoseTurn;
}

void makeMove(Move move, Player curPlayer) {
  nCoins -= move.nTaken;
  if (curPlayer == HUMAN) {
    humanCoins += move.nTaken;
  } else {
    compCoins += move.nTaken;
  }
}

void displayMove(Move &move) {
   cout << "I'll take " << move.nTaken << "." << endl;
}

void switchTurn() {
    whoseTurn = opponentEx13(whoseTurn);
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
    if (humanCoins %2 == 0) {
        cout << "You win! Your score is " << humanCoins << endl;
    } else {
        cout << "I win! My score is " << compCoins << endl;
    }
}

int nCoins;
Player whoseTurn;
int humanCoins;
int compCoins;
};
*/
