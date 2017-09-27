#include <iostream>
#include "console.h"

#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "ctype.h"
using namespace std;

string getCodeForLetter(char letter);
string implementStep1(string secondPart);
string implementStep2And3(string curResultStep1);
string implementStep4(string curResultStep2);
string getCodeForSecondPart(string secondPart);
string getCodeForName(string name);

int main() {
    while(true){
        string surname = getLine("Enter surname(RETURN to quit):");
        if(surname=="")break;
        string curCode = getCodeForName(surname);
        cout << "Soundex code for "<< surname << " is " << curCode <<endl;
    }
    return 0;
}

string getCodeForLetter(char letter){
    switch(letter){
       case 'A':
       case 'E':
       case 'I':
       case 'O':
       case 'U':
       case 'H':
       case 'W':
       case 'Y':
        return "0";
        //break;
       case 'B':
       case 'F':
       case 'P':
       case 'V':
        return "1";
       case 'D':
       case 'T':
        return "3";
       case 'M':
       case 'N':
       return "4";
       case 'L':
        return "5";
       case 'R':
        return "6";
       default :
        return "2";
    }
}
string implementStep1(string secondPart){
    string curResultStep1 = "";
    for(int i=0; i<secondPart.length(); i++){
       char curLetter = toupper(secondPart[i]);
       if(isalpha(curLetter)) curResultStep1+=getCodeForLetter(curLetter);
    }
    return curResultStep1;
}

string implementStep2And3(string curResultStep1){
    string curResultStep2 = "";
    char previous ='\0';
    for(int i = 0; i < curResultStep1.length(); i++){
        if(previous != curResultStep1[i] && curResultStep1[i] != '0'){
            previous = curResultStep1[i];
            curResultStep2 += curResultStep1[i];
        }
    }
    return curResultStep2;
}

string implementStep4(string curResultStep2){
    if(curResultStep2.length()<3){
        int countAdds = 3 - curResultStep2.length();
        for(int i = 0; i < countAdds; i++){
            curResultStep2 += "0";
        }
    }
    else if(curResultStep2.length()>3){
        curResultStep2 = curResultStep2.substr(0,3);
    }
    return curResultStep2;
}

string getCodeForSecondPart(string secondPart){
    if(secondPart.length()==0)return "000";

    string curResultStep1 = implementStep1(secondPart);
    string curResultStep2And3 = implementStep2And3(curResultStep1);
    string curResultStep4 = implementStep4(curResultStep2And3);

    return curResultStep4;
}

string getCodeForName(string name){
    string result ="";
    result+= toupper(name[0]);
    string secondPart = name.substr(1);
    secondPart = getCodeForSecondPart(secondPart);
    return result+secondPart;
}
