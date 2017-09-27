#ifndef _buffer_h
#define _buffer_h


class EditorBufferCP {
public:
    EditorBufferCP();
    ~EditorBufferCP();
    void moveCursorForward();
    void moveCursorBackward();
    void moveCursorToStart();
    void moveCursorToEnd();
    void insertCharacter(char ch);
    void deleteCharacter();
    void moveCursorNextWord();
    void moveCursorPreviosWord();
    void deleteWord();
    void copy(int count);
    void paste();
    std::string getText() const;
    int getCursor() const;

private:
    static const int INITIAL_CAPACITY = 10;
    char *array;
    int capacity;
    int length;
    int cursor;
    char *tmpStorage;
    int tmpSize;
    EditorBufferCP(const EditorBufferCP & value) {}
    const EditorBufferCP & operator=(const EditorBufferCP & rhs) { return *this;}
    void expandCapacity();
    bool cursorInWord();
};





#endif
