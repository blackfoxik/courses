#ifndef _buffer_h
#define _buffer_h


class EditorBuffer {
public:
    EditorBuffer();
    ~EditorBuffer();
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
    int length;
    int cursor;
    EditorBuffer(const EditorBuffer & value) {}
    const EditorBuffer & operator=(const EditorBuffer & rhs) { return *this;}
    void expandCapacity();
};





#endif
