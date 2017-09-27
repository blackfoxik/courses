#include <iostream>
#include <buffer2stacksWord.h>
#include "charstack.h"
using namespace std;


EditorBuffer2StacksWord::EditorBuffer2StacksWord() {}
EditorBuffer2StacksWord::~EditorBuffer2StacksWord() {}

void EditorBuffer2StacksWord::moveCursorNextWord() {
    while (!after.isEmpty() && cursorInWord(after)) moveCursorForward();
}

void EditorBuffer2StacksWord::moveCursorPreviosWord() {
    while (!before.isEmpty() && cursorInWord(before)) moveCursorBackward();
}

void EditorBuffer2StacksWord::deleteWord() {
    while (!after.isEmpty() && cursorInWord(after)) deleteCharacter();
}

void EditorBuffer2StacksWord::moveCursorForward() {
    if (!after.isEmpty()) {
        before.push(after.pop());
    }
}

void EditorBuffer2StacksWord::moveCursorBackward() {
    if (!before.isEmpty()) {
        after.push(before.pop());
    }
}

void EditorBuffer2StacksWord::moveCursorToStart() {
    while (!before.isEmpty()) {
        after.push(before.pop());
    }
}

void EditorBuffer2StacksWord::moveCursorToEnd() {
    while (!after.isEmpty()) {
        before.push(after.pop());
    }
}

void EditorBuffer2StacksWord::insertCharacter(char ch) {
    before.push(ch);
}

void EditorBuffer2StacksWord::deleteCharacter() {
    if (!after.isEmpty()) {
        after.pop();
    }
}

string EditorBuffer2StacksWord::getText() const {
    CharStack beforeCopy = before;
    CharStack afterCopy = after;
    string str = "";
    while (!beforeCopy.isEmpty()) {
        str = beforeCopy.pop() + str;
    }
    while (!afterCopy.isEmpty()) {
        str += afterCopy.pop();
    }
    return str;
}

int EditorBuffer2StacksWord::getCursor() const {
    return before.size();
}

/*void EditorBuffer2Stacks::expandCapacity() {
    char *oldArray = array;
    capacity *= 2;
    array = new char[capacity];
    for (int i = 0; i < length; i++) {
        array[i] =oldArray[i];
    }
    delete[] oldArray;
}*/

bool EditorBuffer2StacksWord::cursorInWord(CharStack &stack) {
   char curChar = stack.peek();
   if (curChar == ' ' ||
       curChar == '.' ||
       curChar == ',' ||
       curChar == ';' ||
       curChar == ':') {
       return false;
   } else {
       return true;
   }

}





