#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "stack.h"
#include "tokenscanner.h"
using namespace std;

void setHTMLDictionary(TokenScanner &scanner){
    scanner.addOperator("</");
}



bool isCorrectlyNested(string htmlText){
    TokenScanner scanner;
    Stack<string> tags;
    scanner.ignoreWhitespace();
    setHTMLDictionary(scanner);
    scanner.setInput(htmlText);
    bool needCheck = false;
    bool openTag = false;
    while (scanner.hasMoreTokens()){
        string token = scanner.nextToken();
        if(token=="<"){
            openTag = true;
            continue;
        }
        if(openTag){
            tags.push(token);
            openTag = false;
        }
        if(token=="</"){
            needCheck = true;
            continue;
        }
        if(needCheck){
            if(token == tags.pop()){
                needCheck = false;
                continue;
            }
            else{
                return false;
            }
        }
        cout << " cur token is " << token << endl;
    }
    return true;
}

int main() {
    string htmlText= getLine();
    bool correctLine = isCorrectlyNested(htmlText);
    if(correctLine){
        cout << "True\n";
    }
    else{
        cout << "False\n";
    }
    return 0;
}
