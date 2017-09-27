#ifndef _buffer2stacksinarray_h
#define _buffer2stacksinarray_h


class EditorBuffer2StacksInArray {
public:
    EditorBuffer2StacksInArray();
    ~EditorBuffer2StacksInArray();
    void moveCursorForward();
    void moveCursorBackward();
    void moveCursorToStart();
    void moveCursorToEnd();
    void insertCharacter(char ch);
    void deleteCharacter();
    std::string getText() const;
    int getCursor() const;

private:
    static const int INITIAL_CAPACITY = 10;
    char *array;
    int capacity;
    int indexBefore;
    int indexAfter;
    EditorBuffer2StacksInArray(const EditorBuffer2StacksInArray & value) {}
    const EditorBuffer2StacksInArray & operator=(const EditorBuffer2StacksInArray & rhs) { return *this;}
    void expandCapacity();
};





#endif
