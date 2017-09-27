#include <iostream>
#include <bufferCPS.h>

using namespace std;

EditorBufferCPS::EditorBufferCPS() {
    capacity = INITIAL_CAPACITY;
    array = new char[capacity];
    length = 0;
    cursor = 0;
}

EditorBufferCPS::~EditorBufferCPS() {
    delete[] array;
}

void EditorBufferCPS::moveCursorNextWord() {
    while (cursor < length && cursorInWord()) cursor++;
}

void EditorBufferCPS::moveCursorPreviosWord() {
    while (cursor > 0 && cursorInWord()) cursor--;
}

void EditorBufferCPS::deleteWord() {
    while (cursor < length && cursorInWord()) {
        deleteCharacter();
        cursor--;
    }
}

void EditorBufferCPS::moveCursorForward() {
    if (cursor < length) cursor++;
}

void EditorBufferCPS::moveCursorBackward() {
    if (cursor > 0) cursor--;
}

void EditorBufferCPS::moveCursorToStart() {
    cursor = 0;
}

void EditorBufferCPS::moveCursorToEnd() {
    cursor = length;
}

void EditorBufferCPS::insertCharacter(char ch) {
    if (length == capacity) expandCapacity();
    for (int i = length; i > cursor; i--) {
        array[i] = array[i - 1];
    }
    array[cursor] = ch;
    length++;
    cursor++;
}

void EditorBufferCPS::deleteCharacter() {
    if (cursor < length) {
        for (int i = cursor + 1; i < length; i++) {
            array[i - 1] = array[i];
        }
    length--;
    }
}

string EditorBufferCPS::getText() const {
    return string(array, length);
}

int EditorBufferCPS::getCursor() const {
    return cursor;
}

void EditorBufferCPS::expandCapacity() {
    char *oldArray = array;
    capacity *= 2;
    array = new char[capacity];
    for (int i = 0; i < length; i++) {
        array[i] =oldArray[i];
    }
    delete[] oldArray;
}

void EditorBufferCPS::copy(int count) {
    tmpStorage = new char[count];
    for (int i = 0 ; i < count; i++) {
        tmpStorage[i] = array[cursor + i];
    }
    tmpSize = count;
}

void EditorBufferCPS::paste() {
    for (int i = 0; i < tmpSize; i++) {
        insertCharacter(tmpStorage[i]);
    }
}

bool EditorBufferCPS::cursorInWord() {
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

bool EditorBufferCPS::search(std::string str) {
    int matches = 0;
    int position = 0;
    char firstLetter = str[0];
    for (int i = cursor; i < length; i++) {
        matches = 0;
        if (firstLetter == array[i]) {
            matches++;
            for (int j = 1; j < str.length(); j++) {
                if (str[j] != array[i + j]) {
                    break;
                } else {
                    matches++;
                    position = i;
                }

            }
        }
        if (matches == str.length()) break;
    }
    if (matches == str.length()) {
        cursor = position;
        return true;
    }
    return false;
}


