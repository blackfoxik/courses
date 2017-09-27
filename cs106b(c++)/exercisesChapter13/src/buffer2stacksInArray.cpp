#include <iostream>
#include <buffer2stacksInArray.h>

using namespace std;

EditorBuffer2StacksInArray::EditorBuffer2StacksInArray() {
    capacity = INITIAL_CAPACITY;
    array = new char[capacity];
    indexBefore = -1;
    indexAfter = capacity;
}

EditorBuffer2StacksInArray::~EditorBuffer2StacksInArray() {
    delete[] array;
}

void EditorBuffer2StacksInArray::moveCursorForward() {
    if (indexAfter == capacity - 1) return;
    array[++indexBefore] = array[indexAfter++];
}

void EditorBuffer2StacksInArray::moveCursorBackward() {
    if (indexBefore < 0) return;
    array[--indexAfter] = array[indexBefore--];
}

void EditorBuffer2StacksInArray::moveCursorToStart() {
    while (indexBefore >= 0) array[--indexAfter] = array[indexBefore--];
}

void EditorBuffer2StacksInArray::moveCursorToEnd() {
    while (indexAfter < capacity) array[++indexBefore] = array[indexAfter++];
}

void EditorBuffer2StacksInArray::insertCharacter(char ch) {
    if (indexBefore == indexAfter - 1) expandCapacity();
    array[++indexBefore] = ch;
}

void EditorBuffer2StacksInArray::deleteCharacter() {
    if (indexBefore == 0) return;
    indexBefore--;
}

string EditorBuffer2StacksInArray::getText() const {
    string head = "";
    for (int i = 0; i <= indexBefore; i ++) {
        head += array[i];
    }
    string tail = "";
    for (int i = capacity - 1; i >= indexAfter; i--) {
        tail = array[i] + tail;
    }
    return head + tail;
}

int EditorBuffer2StacksInArray::getCursor() const {
    return indexBefore;
}

void EditorBuffer2StacksInArray::expandCapacity() {
    char *oldArray = array;
    int oldCapacity = capacity - 1;
    capacity *= 2;
    array = new char[capacity];
    for (int i = 0; i <= indexBefore; i++) {
        array[i] =oldArray[i];
    }
    int curCapacity = capacity - 1;
    for (int i = oldCapacity; i >= indexAfter; i--) {
        array[curCapacity--] = oldArray[i];
    }
    indexAfter = curCapacity + 1;
    delete[] oldArray;
}







