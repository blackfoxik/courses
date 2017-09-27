#include <iostream>
#include <bufferListBasedWD.h>

using namespace std;

EditorBufferListBasedWD::EditorBufferListBasedWD() {
     //start = cursor = new Cell;
     //start->link = NULL;
    cursor = NULL;
}

EditorBufferListBasedWD::~EditorBufferListBasedWD() {
    Cell *cp = start;
    while (cp != NULL) {
        Cell *next = cp->link;
        delete cp;
        cp = next;
    }
}

void EditorBufferListBasedWD::moveCursorForward() {
    if (cursor->link != NULL) {
        cursor = cursor->link;
    }
}

void EditorBufferListBasedWD::moveCursorBackward() {
    /*Cell *cp = start;
    if (cursor != start) {
        while (cp->link != cursor) {
            cp = cp->link;
        }
        cursor = cp;
    }*/
        Cell *cp = start;
        if (cursor != start) {
            while (cp->link != cursor) {
                cp = cp->link;
            }
            cursor = cp;
     }
}

void EditorBufferListBasedWD::moveCursorToStart() {
    cursor = start;
}

void EditorBufferListBasedWD::moveCursorToEnd() {
    while (cursor->link != NULL) {
        cursor = cursor->link;
    }
}

void EditorBufferListBasedWD::insertCharacter(char ch) {
    Cell *cp = new Cell;
    if (cursor == NULL) start = cp;
    cp->ch = ch;
    //cp->link = cursor->link;
    cp->link = NULL;
    if (cursor != NULL) cursor->link = cp;
    cursor = cp;

}

void EditorBufferListBasedWD::deleteCharacter() {
    if (cursor->link != NULL) {
        Cell *oldCell = cursor->link;
        cursor->link = cursor->link->link;
        delete oldCell;
    }
}

string EditorBufferListBasedWD::getText() const {
    string str = "";
    for (Cell *cp = start->link; cp != NULL; cp = cp->link) {
        str += cp->ch;
    }
    return str;
}

int EditorBufferListBasedWD::getCursor() const {
    int nChars = 0;
    for (Cell *cp = start; cp != cursor; cp = cp->link) {
        nChars++;
    }
    return nChars;
}








