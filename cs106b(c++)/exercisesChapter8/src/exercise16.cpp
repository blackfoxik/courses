

#include "exercise16.h"
#include <cmath>
#include "gwindow.h"
#include "random.h"

using namespace std;

//func prototypes
void drawHFractal (GWindow & gw, double cx, double cy, double size, int order);

//general
void exercise16() {
    GWindow gw;
    double cx = gw.getWidth() / 2;
    double cy = gw.getHeight() / 2;
    drawHFractal(gw, cx, cy, 100, 3);
}

void drawHFractal (GWindow & gw, double cx, double cy, double size, int order) {
    if (order < 0) {
        return;
    } else {
        double leftPositionX = cx - size / 2;
        double rightPositionX = cx + size / 2;
        double topPositionY =  cy - size / 2;
        double bottomPositionY = cy + size / 2;
        gw.drawLine(leftPositionX, cy, rightPositionX, cy);
        gw.drawLine(leftPositionX, topPositionY, leftPositionX, bottomPositionY);
        gw.drawLine(rightPositionX, topPositionY, rightPositionX, bottomPositionY);

        drawHFractal(gw, leftPositionX, topPositionY, size / 2, order - 1);
        drawHFractal(gw, leftPositionX, bottomPositionY, size / 2, order - 1);
        drawHFractal(gw, rightPositionX, topPositionY, size / 2, order - 1);
        drawHFractal(gw, rightPositionX, bottomPositionY, size / 2, order - 1);
    }
}
