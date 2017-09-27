/*
#include <cctype>
#include <iostream>
#include <buffer2stacksWord.h>
#include "foreach.h"
#include "simpio.h"
#include "strlib.h"

using namespace std;

//func prototypes
void executeCommand(EditorBuffer2StacksWord & buffer, string line);
void displayBuffer(EditorBuffer2StacksWord & buffer);
void printHelpText();

void Run() {
EditorBuffer2StacksWord buffer;
    while (true) {
        string cmd = getLine("*");
        if (cmd != "") executeCommand(buffer, cmd);
    }
}

int findExecutions(string line) {
    int i = 0;
    string c = "";
    while (isdigit(line[i])) {
        c += line[i];
        i++;
    }
    if (c != "") {
        return stringToInteger(c);
    } else {
        return 1;
    }
}

int findStartPosition(string line) {
    int i = 0;
    string c = "";
    while (isdigit(line[i])) {
        c += line[i];
        i++;
    }
    if (c != "") {
        return c.length();
    } else {
        return 1;
    }
}

void executeCommand(EditorBuffer2StacksWord &buffer, string line) {
    int countOfExecution = findExecutions(line);
    int startPosition = 0;
    string subLine = line;
    if (countOfExecution > 1) {
       startPosition = findStartPosition(line);
       //subLine = line.substr(startPosition);
    }

    string newLine = "I";
    char nextStep = toupper(line[1]);
    switch (toupper(line[startPosition])) {
    case 'I':
        for (int i = 1; i < line.length(); i++) {
          buffer.insertCharacter(line[i]);
        //foreach (char ch in line) {
            //buffer.insertCharacter(ch);
        }
        break;
    case 'D' :
        for (int i = 0; i < countOfExecution; i++) {
            buffer.deleteCharacter();
        }
        break;
    case 'F' :
        for (int i = 0; i < countOfExecution; i++) {
            buffer.moveCursorForward();
        }
        break;
    case 'B' :
        for (int i = 0; i < countOfExecution; i++) {
            buffer.moveCursorBackward();
        }
        break;
    case 'W' :    
        if (nextStep == 'F') {
           buffer.moveCursorNextWord();
        } else if (nextStep == 'B') {
           buffer.moveCursorPreviosWord();
        } else if (nextStep == 'D') {
           buffer.deleteWord();
        }
        break;
    case 'J' : buffer.moveCursorToStart();  break;
    case 'E' : buffer.moveCursorToEnd();  break;
    case 'T' : displayBuffer(buffer); break;
    case 'H' : printHelpText(); break;
    case 'Q' : exit(0);
    case 'A':

        //executeCommand(buffer, newLine);
        while (true) {
            string cmd = getLine("");
            newLine += cmd;
            newLine +='\n';
            if (newLine[newLine.length() - 2] == '.') break;
        }
        executeCommand(buffer, newLine);
        break;
    default: cout << "Illegal command" << endl; break;
    }
}

void displayBuffer(EditorBuffer2StacksWord &buffer) {
    string str = buffer.getText();
    cout << str << endl;
    /*for (int i = 0; i < str.length(); i++) {
        cout << " " << str[i];
    }
    cout << endl;
    cout << string(2 * buffer.getCursor(), ' ') << "^" << endl;
}

void printHelpText() {
    cout << "J - jump to beginning" << endl;
}
*/
