/*
#include <cctype>
#include <iostream>
#include <buffer.h>
#include "foreach.h"
#include "simpio.h"

using namespace std;

//func prototypes
void executeCommand(EditorBuffer & buffer, string line);
void displayBuffer(EditorBuffer & buffer);
void printHelpText();

void Run() {
EditorBuffer buffer;
    while (true) {
        string cmd = getLine("*");
        if (cmd != "") executeCommand(buffer, cmd);
    }
}

void executeCommand(EditorBuffer &buffer, string line) {
    switch (toupper(line[0])) {
    case 'I':
        for (int i = 1; i < line.length(); i++) {
          buffer.insertCharacter(line[i]);
        //foreach (char ch in line) {
            //buffer.insertCharacter(ch);
        }

        break;
    case 'D' : buffer.deleteCharacter();  break;
    case 'F' : buffer.moveCursorForward();  break;
    case 'B' : buffer.moveCursorBackward();  break;
    case 'J' : buffer.moveCursorToStart();  break;
    case 'E' : buffer.moveCursorToEnd();  break;
    case 'T' : displayBuffer(buffer); break;
    case 'H' : printHelpText(); break;
    case 'Q' : exit(0);
    default: cout << "Illegal command" << endl; break;
    }
}

void displayBuffer(EditorBuffer &buffer) {
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










