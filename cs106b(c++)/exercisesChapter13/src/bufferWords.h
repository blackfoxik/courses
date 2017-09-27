#ifndef _buffer_h
#define _buffer_h


class EditorBufferWords {
public:
    EditorBufferWords();
    ~EditorBufferWords();
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
    static const int INITIAL_CAPACITY = 10;
    char *array;
    int capacity;
    int length;
    int cursor;
    EditorBufferWords(const EditorBufferWords & value) {}
    const EditorBufferWords & operator=(const EditorBufferWords & rhs) { return *this;}
    void expandCapacity();
    bool cursorInWord();
};





#endif
