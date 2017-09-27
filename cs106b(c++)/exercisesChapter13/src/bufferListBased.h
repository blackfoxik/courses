#ifndef _bufferlistbased_h
#define _bufferlistbased_h


class EditorBufferListBased {
public:
    EditorBufferListBased();
    ~EditorBufferListBased();
    void moveCursorForward();
    void moveCursorBackward();
    void moveCursorToStart();
    void moveCursorToEnd();
    void insertCharacter(char ch);
    void deleteCharacter();
    std::string getText() const;
    int getCursor() const;

private:
    struct Cell {
        char ch;
        Cell *link;
    };
    Cell *start;
    Cell *cursor;
    EditorBufferListBased(const EditorBufferListBased & value) {}
    const EditorBufferListBased & operator=(const EditorBufferListBased & rhs) { return *this;}
};





#endif
