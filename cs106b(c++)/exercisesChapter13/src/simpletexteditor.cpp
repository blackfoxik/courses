#include <cctype>
#include <iostream>
#include <bufferDoubleLink.h>
#include "foreach.h"
#include "simpio.h"

using namespace std;

//func prototypes
void executeCommand(EditorBufferDoubleLink & buffer, string line);
void displayBuffer(EditorBufferDoubleLink & buffer);
void printHelpText();

void Run() {
EditorBufferDoubleLink buffer;
    while (true) {
        string cmd = getLine("*");
        if (cmd != "") executeCommand(buffer, cmd);
    }
}

void executeCommand(EditorBufferDoubleLink &buffer, string line) {
    switch (toupper(line[0])) {
    case 'I':
        foreach (char ch in line) {
            buffer.insertCharacter(ch);
        }
        displayBuffer(buffer);
        break;
    case 'D' : buffer.deleteCharacter(); displayBuffer(buffer); break;
    case 'F' : buffer.moveCursorForward(); displayBuffer(buffer); break;
    case 'B' : buffer.moveCursorBackward(); displayBuffer(buffer); break;
    case 'J' : buffer.moveCursorToStart(); displayBuffer(buffer); break;
    case 'E' : buffer.moveCursorToEnd(); displayBuffer(buffer); break;
    case 'H' : printHelpText(); break;
    case 'Q' : exit(0);
    default: cout << "Illegal command" << endl; break;
    }
}

void displayBuffer(EditorBufferDoubleLink &buffer) {
    string str = buffer.getText();
    for (int i = 0; i < str.length(); i++) {
        cout << " " << str[i];
    }
    cout << endl;
    cout << string(2 * buffer.getCursor(), ' ') << "^" << endl;
}

void printHelpText() {
    cout << "J - jump to beginning" << endl;
}















