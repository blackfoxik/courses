

#include "exercise16.h"
#include <cmath>
#include "gwindow.h"
#include "random.h"
#include "lexicon.h"
#include "grid.h"
using namespace std;

//func prototypes
void findBoggleWords(const Grid<char> & board, const Lexicon & english, Vector<string> & wordsFound);
void findBoggleWords(const Grid<char> & board, const Lexicon & english, Vector<string> & wordsFound, string curString, int nRow, int nCol, Set<string> path);
void fillBoard(Grid<char> & board);
void printWords(Vector<string> & wordsFound);
void addToPathCurLocation(Set<string> & path, int nRow, int nCol);
bool isStepLegal(const Grid<char> & board, int nRow, int nCol, Set<string> & path);
bool wordWasNotFoundedBefore(Vector<string> & wordsFound, string & curString);

string getStrNRowNCol(int nRow, int nCol);
//general
void exercise16() {
    Lexicon english("EnglishWords.dat");
    Vector<string> wordsFound;
    Grid<char> board(4,4);
    fillBoard(board);
    findBoggleWords(board, english, wordsFound);
    printWords(wordsFound);
    cout << "Was founded "<<  wordsFound.size() << endl;
}

void printWords(Vector<string> & wordsFound) {
    for (string curWord : wordsFound) {
        cout << curWord << endl;
    }
}

void findBoggleWords(const Grid<char> & board, const Lexicon & english, Vector<string> & wordsFound) {
    Set<string> path;

    for (int i = 0; i < board.nRows; i++) {
        for (int j = 0; j < board.nCols; j++) {
            findBoggleWords(board, english, wordsFound, "", i, j, path);
        }
    }

}

void findBoggleWords(const Grid<char> & board, const Lexicon & english, Vector<string> & wordsFound, string curString, int nRow, int nCol, Set<string> path) {
    if (curString.length() >= 4) {
        if (english.contains(curString) && wordWasNotFoundedBefore(wordsFound,curString)) {
            wordsFound.add(curString);
        }
    }
    if (!isStepLegal(board, nRow, nCol, path)) {
        return;
    }
    //check for prefix
    if (!english.containsPrefix(curString) && curString.length() > 0) {
        return;
    }

    curString += board[nRow][nCol];
    addToPathCurLocation(path, nRow, nCol);
    //right
    findBoggleWords(board, english, wordsFound, curString, nRow, nCol + 1, path);
    //left
    findBoggleWords(board, english, wordsFound, curString, nRow, nCol - 1, path);
    //top
    findBoggleWords(board, english, wordsFound, curString, nRow - 1, nCol, path);
    //bottom
    findBoggleWords(board, english, wordsFound, curString, nRow + 1, nCol, path);
    //right top
    findBoggleWords(board, english, wordsFound, curString, nRow - 1, nCol + 1, path);
    //right bottom
    findBoggleWords(board, english, wordsFound, curString, nRow + 1, nCol + 1, path);
    //left top
    findBoggleWords(board, english, wordsFound, curString, nRow - 1, nCol - 1, path);
    //left bottom
    findBoggleWords(board, english, wordsFound, curString, nRow + 1, nCol - 1, path);

}

string getStrNRowNCol(int nRow, int nCol) {
    string strNRow = integerToString(nRow);
    string strNCol = integerToString(nCol);
    string strNRowNCol = strNRow + strNCol;
    return strNRowNCol;
}

void addToPathCurLocation(Set<string> & path, int nRow, int nCol) {
    string strNRowNCol = getStrNRowNCol(nRow, nCol);
    path.add(strNRowNCol);
}

bool isStepLegal(const Grid<char> & board, int nRow, int nCol, Set<string> & path) {
    if (nRow < 0 || nCol < 0 || nRow >= board.nRows || nCol >= board.nCols ) {
        return false;
    }
    string strNRowNCol = getStrNRowNCol(nRow, nCol);
    if (path.contains(strNRowNCol)) {
        return false;
    }
    return true;
}

bool wordWasNotFoundedBefore(Vector<string> & wordsFound, string & curString) {
    for (string curWord : wordsFound) {
        if (curWord == curString) {
            return false;
        }
    }
    return true;
}

void fillBoard(Grid<char> & board) {
    board[0][0] = 'x';
    board[0][1] = 'c';
    board[0][2] = 'e';
    board[0][3] = 'r';

    board[1][0] = 'i';
    board[1][1] = 'm';
    board[1][2] = 'g';
    board[1][3] = 'a';

    board[2][0] = 'n';
    board[2][1] = 'o';
    board[2][2] = 'm';
    board[2][3] = 'l';

    board[3][0] = 'g';
    board[3][1] = 'z';
    board[3][2] = 'r';
    board[3][3] = 'p';
}
