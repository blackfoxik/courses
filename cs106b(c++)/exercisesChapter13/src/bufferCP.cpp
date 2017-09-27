#include <iostream>
#include <bufferCP.h>

using namespace std;

EditorBufferCP::EditorBufferCP() {
    capacity = INITIAL_CAPACITY;
    array = new char[capacity];
    length = 0;
    cursor = 0;
}

EditorBufferCP::~EditorBufferCP() {
    delete[] array;
}

void EditorBufferCP::moveCursorNextWord() {
    while (cursor < length && cursorInWord()) cursor++;
}

void EditorBufferCP::moveCursorPreviosWord() {
    while (cursor > 0 && cursorInWord()) cursor--;
}

void EditorBufferCP::deleteWord() {
    while (cursor < length && cursorInWord()) {
        deleteCharacter();
        cursor--;
    }
}

void EditorBufferCP::moveCursorForward() {
    if (cursor < length) cursor++;
}

void EditorBufferCP::moveCursorBackward() {
    if (cursor > 0) cursor--;
}

void EditorBufferCP::moveCursorToStart() {
    cursor = 0;
}

void EditorBufferCP::moveCursorToEnd() {
    cursor = length;
}

void EditorBufferCP::insertCharacter(char ch) {
    if (length == capacity) expandCapacity();
    for (int i = length; i > cursor; i--) {
        array[i] = array[i - 1];
    }
    array[cursor] = ch;
    length++;
    cursor++;
}

void EditorBufferCP::deleteCharacter() {
    if (cursor < length) {
        for (int i = cursor + 1; i < length; i++) {
            array[i - 1] = array[i];
        }
    length--;
    }
}

string EditorBufferCP::getText() const {
    return string(array, length);
}

int EditorBufferCP::getCursor() const {
    return cursor;
}

void EditorBufferCP::expandCapacity() {
    char *oldArray = array;
    capacity *= 2;
    array = new char[capacity];
    for (int i = 0; i < length; i++) {
        array[i] =oldArray[i];
    }
    delete[] oldArray;
}

void EditorBufferCP::copy(int count) {
    tmpStorage = new char[count];
    for (int i = 0 ; i < count; i++) {
        tmpStorage[i] = array[cursor + i];
    }
    tmpSize = count;
}

void EditorBufferCP::paste() {
    for (int i = 0; i < tmpSize; i++) {
        insertCharacter(tmpStorage[i]);
    }
}

bool EditorBufferCP::cursorInWord() {
   if (array[cursor] == ' ' ||
       array[cursor] == '.' ||
       array[cursor] == ',' ||
       array[cursor] == ';' ||
       array[cursor] == ':') {
       return false;
   } else {
       return true;
   }

}



