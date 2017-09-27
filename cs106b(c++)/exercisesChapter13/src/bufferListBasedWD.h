#ifndef _bufferlistbasedwd_h
#define _bufferlistbasedwd_h


class EditorBufferListBasedWD {
public:
    EditorBufferListBasedWD();
    ~EditorBufferListBasedWD();
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
    EditorBufferListBasedWD(const EditorBufferListBasedWD & value) {}
    const EditorBufferListBasedWD & operator=(const EditorBufferListBasedWD & rhs) { return *this;}
};





#endif
