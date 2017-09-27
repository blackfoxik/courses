#ifndef _buffer2stacks_h
#define _buffer2stacks_h
#include "charstack.h"

class EditorBuffer2StacksWord {
public:
    EditorBuffer2StacksWord();
    ~EditorBuffer2StacksWord();
    void moveCursorForward();
    void moveCursorBackward();
    void moveCursorToStart();
    void moveCursorToEnd();
    void moveCursorNextWord();
    void moveCursorPreviosWord();
    void deleteWord();
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
    EditorBuffer2StacksWord(const EditorBuffer2StacksWord & value) {}
    const EditorBuffer2StacksWord & operator=(const EditorBuffer2StacksWord & rhs) { return *this;}
    void expandCapacity();
    bool cursorInWord(CharStack &stack);
};





#endif
