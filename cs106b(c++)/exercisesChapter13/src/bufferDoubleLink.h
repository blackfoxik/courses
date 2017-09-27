#ifndef _bufferdoublelink_h
#define _bufferdoublelink_h


class EditorBufferDoubleLink {
public:
    EditorBufferDoubleLink();
    ~EditorBufferDoubleLink();
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
        Cell *next;
        Cell *prev;
    };
    Cell *start;
    Cell *cursor;
    EditorBufferDoubleLink(const EditorBufferDoubleLink & value) {}
    const EditorBufferDoubleLink & operator=(const EditorBufferDoubleLink & rhs) { return *this;}
};





#endif
