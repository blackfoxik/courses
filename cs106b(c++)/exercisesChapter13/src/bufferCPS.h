#ifndef _buffer_h
#define _buffer_h


class EditorBufferCPS {
public:
    EditorBufferCPS();
    ~EditorBufferCPS();
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
    bool search(std::string str);
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
    EditorBufferCPS(const EditorBufferCPS & value) {}
    const EditorBufferCPS & operator=(const EditorBufferCPS & rhs) { return *this;}
    void expandCapacity();
    bool cursorInWord();
};





#endif
