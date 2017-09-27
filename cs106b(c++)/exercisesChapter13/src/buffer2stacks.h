#ifndef _buffer2stacks_h
#define _buffer2stacks_h
#include "charstack.h"

class EditorBuffer2Stacks {
public:
    EditorBuffer2Stacks();
    ~EditorBuffer2Stacks();
    void moveCursorForward();
    void moveCursorBackward();
    void moveCursorToStart();
    void moveCursorToEnd();
    void insertCharacter(char ch);
    void deleteCharacter();
    std::string getText() const;
    int getCursor() const;

private:
    //static const int INITIAL_CAPACITY = 10;
    //char *array;
    CharStack before;
    CharStack after;
    //int capacity;
    //int length;
    //int cursor;
    EditorBuffer2Stacks(const EditorBuffer2Stacks & value) {}
    const EditorBuffer2Stacks & operator=(const EditorBuffer2Stacks & rhs) { return *this;}
    void expandCapacity();
};





#endif
