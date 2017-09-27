#include "exercise1.h"
#include <iostream>
#include "buffer.h"
#include <cassert>

using namespace std;

//func prototypes


void exercise1() {
    EditorBuffer buf;
    buf.insertCharacter('t');
    buf.insertCharacter('h');
    buf.insertCharacter('i');
    buf.insertCharacter('s');
    assert(buf.getCursor() == 4);
    assert(buf.getText() == "this");
    buf.moveCursorBackward();
    assert(buf.getCursor() == 3);
    buf.moveCursorToStart();
    assert(buf.getCursor() == 0);
    buf.moveCursorForward();
    assert(buf.getCursor() == 1);
    buf.moveCursorToEnd();
    assert(buf.getCursor() == 4);
    for (int i = 0; i < 7; i++) {
        buf.insertCharacter('a');
    }
    assert(buf.getCursor() == 11);
    cout << buf.getText() << endl;
    buf.moveCursorToStart();
    for (int i = 0; i < 3; i++) {
        buf.deleteCharacter();
    }
    cout << buf.getText() << endl;

    buf.moveCursorToEnd();

    for (int i = 0; i < 3; i++) {
        buf.moveCursorBackward();
        buf.deleteCharacter();
    }
    cout << buf.getText() << endl;
}

