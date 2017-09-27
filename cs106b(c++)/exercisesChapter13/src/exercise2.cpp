#include "exercise2.h"
#include <iostream>
#include "buffer2stacksInArray.h"
#include <cassert>

using namespace std;

//func prototypes


void exercise2() {
    EditorBuffer2StacksInArray buf;
    buf.insertCharacter('t');
    buf.insertCharacter('h');
    buf.insertCharacter('i');
    buf.insertCharacter('s');
    cout << buf.getText() << endl;
    buf.moveCursorBackward();
    cout << buf.getText() << endl;
    //assert(buf.getCursor() == 4);
    for (int i = 0; i < 14; i++) {
        buf.insertCharacter('a');
        cout << buf.getText() << endl;
    }
    cout << buf.getText() << endl;
    for (int i = 0; i < 11; i++) {
        buf.deleteCharacter();
    }
    cout << buf.getText() << endl;
    for (int i = 0; i < 11; i++) {
        buf.moveCursorBackward();
    }
    cout << buf.getText() << endl;
    for (int i = 0; i < 11; i++) {
        buf.insertCharacter('z');
    }
    cout << buf.getText() << endl;
    buf.moveCursorToEnd();
    buf.insertCharacter('W');
    cout << buf.getText() << endl;
    buf.moveCursorToStart();
    buf.insertCharacter('W');
    cout << buf.getText() << endl;



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

