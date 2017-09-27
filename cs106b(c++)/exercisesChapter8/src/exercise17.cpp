

#include "exercise17.h"
#include "gwindow.h"


using namespace std;
//const
const double TRUNK_TO_BRANCH_RELATION = 1.7;
const int START_LEFT_ANGLE = 135;
const int START_RIGHT_ANGLE = 45;

//func prototypes
void drawFractalTree (GWindow & gw, GPoint pt, double size, int order, int angleLeft, int angleRight);

//general
void exercise17() {
    GWindow gw;
    double cx = gw.getWidth() / 2;
    double by = gw.getHeight();
    int size = 100;
    gw.drawLine(cx, by, cx, by - size);
    GPoint pt(cx, by - size);
    drawFractalTree(gw, pt, size, 8, START_LEFT_ANGLE, START_RIGHT_ANGLE);
}

void drawFractalTree (GWindow & gw, GPoint pt, double size, int order, int angleLeft, int angleRight) {
    if (order < 0) {
        return;
    } else {

        double curSize = size / TRUNK_TO_BRANCH_RELATION;
        GPoint pointBranchRight = gw.drawPolarLine(pt, curSize, angleRight);
        GPoint pointBranchLeft = gw.drawPolarLine(pt, curSize,   angleLeft);


        if (order % 2 == 0) {
            drawFractalTree(gw, pointBranchRight, curSize, order - 1, angleRight - 45, angleLeft - 45 );
            drawFractalTree(gw, pointBranchLeft, curSize, order - 1, angleRight + 45, angleLeft + 45);
        } else {
            drawFractalTree(gw, pointBranchRight, curSize, order - 1, angleRight + 45, angleLeft + 45 );
            drawFractalTree(gw, pointBranchLeft, curSize, order - 1, angleRight - 45, angleLeft - 45);
        }


    }
}
