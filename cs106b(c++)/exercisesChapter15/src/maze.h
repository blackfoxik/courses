// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files
#ifndef _maze_h
#define _maze_h
#include <string>
#include "grid.h"
#include "gwindow.h"
#include "point.h"

enum Direction { NORTH, EAST, SOUTH, WEST};

class Maze {
public:
    Maze(std::string filename);
    Maze(std::string filename, GWindow & gw);

    Point getStartPosition();
    bool isOutside(Point pt);
    bool wallExists(Point pt, Direction dir);
    void markSquare(Point pt);
    void unmarkSquare(Point pt);
    bool isMarked(Point pt);
};

#endif

