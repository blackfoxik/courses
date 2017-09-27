
#include "console.h"
#include "simpio.h"  // for getLine
#include "lexicon.h"
#include "set.h"
#include "exercise11.h"
#include <foreach.h>

using namespace std;

//func prototypes
void listMnemonicsWithLexicon (string str);
void listMnemonicsWithLexicon (string str, string curString, int index, Lexicon &english);
string getSequenceBySignEx11(char curChar);
//general
void exercise11() {
    string str = getLine("Enter number: ");
    cout << "The possible mnemonicss of \"" << str << "\"  in lexicon are:" << endl;
    listMnemonicsWithLexicon(str);
}

void listMnemonicsWithLexicon (string str) {
    int index = 0;
    string curString = "";
    Lexicon english("EnglishWords.dat");
    listMnemonicsWithLexicon(str, curString, index, english);
}



void listMnemonicsWithLexicon (string str, string curString,int index, Lexicon &english) {

    if (str.length() == curString.length()) {
        if (english.contains(curString)) {
            cout << " \"" << curString << "\"" << endl;
        }
        return;
    } else {
        char curChar = str[index];
        string curSequence = getSequenceBySignEx11(curChar);
            foreach (char curSign in curSequence) {
                listMnemonicsWithLexicon(str, curString + curSign, index + 1, english);
            }
    }

}

string getSequenceBySignEx11(char curChar) {
    switch (curChar) {
        case '2':
        return "ABC";
        case '3':
        return "DEF";
        case '4':
        return "GHI";
        case '5':
        return "JKL";
        case '6':
        return "MNO";
        case '7':
        return "PQRS";
        case '8':
        return "TUV";
        case '9':
        return "WXYZ";
    default: return "";
    }
}

