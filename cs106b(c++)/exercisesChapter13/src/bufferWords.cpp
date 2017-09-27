#include <iostream>
#include <bufferWords.h>

using namespace std;

EditorBufferWords::EditorBufferWords() {
    capacity = INITIAL_CAPACITY;
    array = new char[capacity];
    length = 0;
    cursor = 0;
}

EditorBufferWords::~EditorBufferWords() {
    delete[] array;
}

void EditorBufferWords::moveCursorForward() {
    if (cursor < length) cursor++;
}

void EditorBufferWords::moveCursorBackward() {
    if (cursor > 0) cursor--;
}

void EditorBufferWords::moveCursorNextWord() {
    while (cursor < length && cursorInWord()) cursor++;
}

void EditorBufferWords::moveCursorPreviosWord() {
    while (cursor > 0 && cursorInWord()) cursor--;
}

void EditorBufferWords::deleteWord() {
    while (cursor < length && cursorInWord()) {
        deleteCharacter();
        cursor--;
    }
}

void EditorBufferWords::moveCursorToStart() {
    cursor = 0;
}

void EditorBufferWords::moveCursorToEnd() {
    cursor = length;
}

void EditorBufferWords::insertCharacter(char ch) {
    if (length == capacity) expandCapacity();
    for (int i = length; i > cursor; i--) {
        array[i] = array[i - 1];
    }
    array[cursor] = ch;
    length++;
    cursor++;
}

void EditorBufferWords::deleteCharacter() {
    if (cursor < length) {
        for (int i = cursor + 1; i < length; i++) {
            array[i - 1] = array[i];
        }
    length--;
    }
}

string EditorBufferWords::getText() const {
    return string(array, length);
}

int EditorBufferWords::getCursor() const {
    return cursor;
}

void EditorBufferWords::expandCapacity() {
    char *oldArray = array;
    capacity *= 2;
    array = new char[capacity];
    for (int i = 0; i < length; i++) {
        array[i] =oldArray[i];
    }
    delete[] oldArray;
}

bool EditorBufferWords::cursorInWord() {
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






