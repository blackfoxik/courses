#include <iostream>
#include <buffer2stacks.h>
#include "charstack.h"
using namespace std;


EditorBuffer2Stacks::EditorBuffer2Stacks() {}
EditorBuffer2Stacks::~EditorBuffer2Stacks() {}



void EditorBuffer2Stacks::moveCursorForward() {
    if (!after.isEmpty()) {
        before.push(after.pop());
    }
}

void EditorBuffer2Stacks::moveCursorBackward() {
    if (!before.isEmpty()) {
        after.push(before.pop());
    }
}

void EditorBuffer2Stacks::moveCursorToStart() {
    while (!before.isEmpty()) {
        after.push(before.pop());
    }
}

void EditorBuffer2Stacks::moveCursorToEnd() {
    while (!after.isEmpty()) {
        before.push(after.pop());
    }
}

void EditorBuffer2Stacks::insertCharacter(char ch) {
    before.push(ch);
}

void EditorBuffer2Stacks::deleteCharacter() {
    if (!after.isEmpty()) {
        after.pop();
    }
}

string EditorBuffer2Stacks::getText() const {
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

int EditorBuffer2Stacks::getCursor() const {
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







