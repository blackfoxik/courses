
#include "console.h"
#include "simpio.h"  // for getLine
#include "lexicon.h"
#include "set.h"
#include "exercise12.h"
#include <foreach.h>

using namespace std;

//func prototypes
void listCompletions (string str);
void listCompletions (string str, string curString, int index, Lexicon &english);
string getSequenceBySignEx12(char curChar);
//general
void exercise12() {
    string str = getLine("Enter number: ");
    cout << "The possible mnemonicss of \"" << str << "\"  in lexicon are:" << endl;
    listCompletions(str);
}

void listCompletions (string str) {
    int index = 0;
    string curString = "";
    Lexicon english("EnglishWords.dat");
    listCompletions(str, curString, index, english);
}



void listCompletions (string str, string curString,int index, Lexicon &english) {

    if (str.length() <= curString.length()) {
        if (english.contains(curString)) {
            cout << " \"" << curString << "\"" << endl;
        }
        if (english.containsPrefix(curString)) {
           string curSequence = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
           foreach (char curSign in curSequence) {
                 listCompletions(str, curString + curSign, index + 1, english);
           }
        }
        return;
    } else {
        char curChar = str[index];
        string curSequence = getSequenceBySignEx12(curChar);
            foreach (char curSign in curSequence) {
                listCompletions(str, curString + curSign, index + 1, english);
            }
    }

}

string getSequenceBySignEx12(char curChar) {
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

