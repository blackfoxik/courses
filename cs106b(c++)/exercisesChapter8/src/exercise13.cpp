

#include "exercise13.h"
#include <iostream>
#include "gwindow.h"
#include "random.h"

using namespace std;

//const
const double MIN_AREA = 10000;
const double MIN_EDGE = 20;

//func prototypes
void subdivideCanvas (GWindow & gw, double x, double y, double width, double height);

//general
void exercise13() {
    GWindow gw;
    subdivideCanvas(gw, 0, 0, gw.getWidth(), gw.getHeight());
}

void subdivideCanvas (GWindow & gw, double x, double y, double width, double height) {
    int numOfColor = randomInteger(-256, 256);
    gw.setColor(numOfColor);
    if (width * height >= MIN_AREA) {
        if (width > height) {
            double mid = randomReal(MIN_EDGE, width - MIN_EDGE);
            subdivideCanvas(gw, x, y, mid, height);
            subdivideCanvas(gw, x + mid, y, width - mid, height);
           // gw.drawLine (x + mid, y, x + mid, y + height);
            gw.fillRect(x + mid, y, x + mid, y + height);
        } else {
            double mid = randomReal(MIN_EDGE, height - MIN_EDGE);
            subdivideCanvas(gw, x, y, width, mid);
            subdivideCanvas(gw, x, y + mid, width, height - mid);
           // gw.drawLine (x, y + mid, x + width, y + mid);
            gw.fillRect(x, y + mid, x + width, y + mid);
        }
}
}
