#include <iostream>
#include <bufferDoubleLink.h>

using namespace std;

EditorBufferDoubleLink::EditorBufferDoubleLink() {
     //start = cursor = new Cell;
     //start->link = NULL;
    cursor = NULL;
}

EditorBufferDoubleLink::~EditorBufferDoubleLink() {
    Cell *cp = start;
    while (cp != NULL) {
        Cell *next = cp->next;
        delete cp;
        cp = next;
    }
}

void EditorBufferDoubleLink::moveCursorForward() {
    if (cursor->next != NULL) {
        cursor = cursor->next;
    }
}

void EditorBufferDoubleLink::moveCursorBackward() {
   /* Cell *cp = start;
    if (cursor != start) {
        while (cp->prev != cursor) {
            cp = cp->prev;
        }
        cursor = cp;
    }*/
    if (cursor->prev != NULL) cursor = cursor->prev;
}

void EditorBufferDoubleLink::moveCursorToStart() {
    cursor = start;
}

void EditorBufferDoubleLink::moveCursorToEnd() {
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
}

void EditorBufferDoubleLink::insertCharacter(char ch) {
    Cell *cp = new Cell;
    if (cursor == NULL) start = cp;
    cp->ch = ch;
    cp->prev = cursor;
    if (cursor == NULL) {
        cp->next = NULL;
    } else {
       cp->next = cursor->next;
    }
    if (cursor != NULL) cursor->next = cp;
    //cp->link = cursor->link;
    //cursor->link = cp;
    cursor = cp;
}

void EditorBufferDoubleLink::deleteCharacter() {
    if (cursor->next == NULL) return;
    if (cursor->next != NULL && cursor->next->next == NULL) {
        Cell *oldCell = cursor->next;

        //cursor->prev = cursor->next->prev;
        cursor->next = NULL;
        delete oldCell;
        return;
    }
    if (cursor->next->next != NULL) {
        Cell *oldCell = cursor->next;
        //cursor->prev->next = cursor->next;
        //cursor->next->prev = cursor->prev;
        cursor->next->next->prev = cursor;
        cursor->next = cursor->next->next;

        delete oldCell;
    }
}

string EditorBufferDoubleLink::getText() const {
    string str = "";
    for (Cell *cp = start->next; cp != NULL; cp = cp->next) {
        str += cp->ch;
    }
    return str;
}

int EditorBufferDoubleLink::getCursor() const {
    int nChars = 0;
    for (Cell *cp = start; cp != cursor; cp = cp->next) {
        nChars++;
    }
    return nChars;
}








