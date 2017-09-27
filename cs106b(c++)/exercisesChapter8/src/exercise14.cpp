

#include "exercise14.h"
#include <iostream>
#include "gwindow.h"
#include "random.h"

using namespace std;

//const
const double HALF_INCH_TICK = 0.2;
const double ONE_INCH = 108;


//func prototypes
void drawInch (GWindow & gw, double startPositionX, double finishPostionX, double fixedPostionY, double curPostionY,int indexOfTickHeight);

//general
void exercise14() {
    GWindow gw;
    double startPositionX = gw.getWidth() / 2 - ONE_INCH / 2;
    double finishPostionX = gw.getWidth() / 2 + ONE_INCH / 2;
    double fixedPostionY = gw.getHeight() / 2 - 1;
    double curTickHeight = HALF_INCH_TICK * 108;
    gw.drawLine(startPositionX, fixedPostionY, finishPostionX, fixedPostionY);
    int indexOfTickHeight = 1;
    drawInch(gw, startPositionX, finishPostionX, fixedPostionY, curTickHeight, indexOfTickHeight);
}

void drawInch (GWindow & gw, double startPositionX, double finishPostionX, double fixedPostionY, double curTickHeight,int indexOfTickHeight) {
    if (indexOfTickHeight == 5) {
        return;
    } else {
        double midPositionX = startPositionX + (finishPostionX - startPositionX) / 2;
        double curFinishPositionY = fixedPostionY - curTickHeight;
        gw.drawLine(midPositionX, fixedPostionY, midPositionX, curFinishPositionY);
        drawInch(gw, startPositionX, midPositionX, fixedPostionY, curTickHeight / 2, indexOfTickHeight + 1);
        drawInch(gw, midPositionX, finishPostionX, fixedPostionY, curTickHeight / 2, indexOfTickHeight + 1);
    }

}
