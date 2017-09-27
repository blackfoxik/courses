
#include "console.h"
#include "simpio.h"  // for getLine
#include "lexicon.h"
#include "set.h"
#include "exercise9.h"
#include <foreach.h>

using namespace std;

//func prototypes
void listPermutations (string str);
void listPermutations (string str, int index);

//general
void exercise9() {
    string str = getLine("Enter a string: ");
    cout << "The permutations of \"" << str << "\" are:" << endl;
    listPermutations(str);
}

void listPermutations (string str) {
    int index = 0;
    listPermutations(str, index);
}

void listPermutations (string str, int index) {

    if (str.length() == index) {
        return;
    } else {
        char curChar = str[index];

        for (int i = index + 1; i < str.length() ; i++) {
            string curString = str;

            char swapChar = str[i];
            curString[index] = swapChar;
            curString[i] = curChar;
            cout << " \"" << curString << "\"" << endl;
            listPermutations(curString,index + 1);
        }
        listPermutations(str,index + 1);

    }

}



