
#include "console.h"
#include "simpio.h"  // for getLine
#include "lexicon.h"
#include "set.h"
#include "exercise10.h"
#include <foreach.h>

using namespace std;

//func prototypes
void listMnemonics (string str);
void listMnemonics (string str, string curString, int index);
string getSequenceBySign(char curChar);


//general
void exercise10() {
    string str = getLine("Enter number: ");
    cout << "The possible mnemonicss of \"" << str << "\" are:" << endl;
    listMnemonics(str);
}

void listMnemonics (string str) {
    int index = 0;
    string curString = "";
    listMnemonics(str, curString, index);
}



void listMnemonics (string str, string curString,int index) {

    if (str.length() == curString.length()) {
        cout << " \"" << curString << "\"" << endl;
        return;
    } else {
        char curChar = str[index];
        string curSequence = getSequenceBySign(curChar);
            foreach (char curSign in curSequence) {
                listMnemonics(str, curString + curSign, index + 1);
            }
    }

}

string getSequenceBySign(char curChar) {
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


