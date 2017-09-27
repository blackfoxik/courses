#include "exercise1.h"
#include <iostream>
#include "console.h"
#include "simpio.h"
#include "grid.h"
#include "vector.h"

using namespace std;

void generateBinaryCode(int nBits);
void generateBinaryCode(int index, string & code);
string getStartCode(int n);
bool isCodeMax(string &code);

void exercise1() {
 int n = getInteger("Input n: ");
 generateBinaryCode(n);
}

void generateBinaryCode(int nBits) {
    string code = getStartCode(nBits);
    cout << code << endl;
    generateBinaryCode(code.size() - 1, code);
}

void generateBinaryCode(int index, string & code) {
    if (isCodeMax(code)) {
        return;
    }

    if (code[index] == '0') {
        code[index] = '1';
        cout << code << endl;
        generateBinaryCode( code.size() -1, code);
    } else {
        code[index] = '0';
        generateBinaryCode(index - 1, code);
    }

}

string getStartCode(int n) {
    string code = "";
    for (int i = 0; i < n; i++) {
        code += "0";
    }
    return code;
}

bool isCodeMax(string &code) {
    for (int i = 0; i < code.size(); i++) {
        if (code[i] != '1') return false;
    }
    return true;
}
