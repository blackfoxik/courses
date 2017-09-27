/*
#include <cctype>
#include <iostream>
#include "bufferCPS.h"
#include "foreach.h"
#include "simpio.h"
#include "strlib.h"

using namespace std;

//func prototypes
void executeCommand(EditorBufferCPS & buffer, string line);
void displayBuffer(EditorBufferCPS & buffer);
void printHelpText();

void Run() {
EditorBufferCPS buffer;
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

string getWorForSearch(string line) {
   int position = 0;
   for (int i = 1; i < line.length(); i++) {
       if (line[i] == '/') {
           position = i;
           break;
       }
   }
   if (position > 0) {
       return line.substr(1,position - 1);
   }
   return "";
}

string getWordForReplacement(string line) {
    int position = 0;
    for (int i = 1; i < line.length(); i++) {
        if (line[i] == '/') {
            position = i;
            break;
        }
    }
    if (position > 0) {
        return line.substr(position + 1);
    }
    return "";
}

void executeCommand(EditorBufferCPS &buffer, string line) {
    int countOfExecution = findExecutions(line);
    int startPosition = 0;
    string subLine = line;
    if (countOfExecution > 1) {
       startPosition = findStartPosition(line);
       //subLine = line.substr(startPosition);
    }

    string newLine = "I";
    char nextStep = toupper(line[1]);
    string wordForSearch = "";
    string wordForReplacement = "";
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
    case 'C' :
            buffer.copy(countOfExecution);
            break;
    case 'P' :
            buffer.paste();
            break;
    case 'X' :
           buffer.copy(countOfExecution);
           for (int i = 0; i < countOfExecution; i++) {
               buffer.deleteCharacter();
           }
           break;
    case 'S' :
           if (!buffer.search(line.substr(1))) cout << "Search failed" << endl;
           break;
    case 'R' :
           wordForSearch = getWorForSearch(line);
           wordForReplacement = getWordForReplacement(line);
           if (buffer.search(wordForSearch)) {
               buffer.deleteWord();
               for (int i = 0; i < wordForReplacement.length();i++) {
                   buffer.insertCharacter(wordForReplacement[i]);
               }
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

void displayBuffer(EditorBufferCPS &buffer) {
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
