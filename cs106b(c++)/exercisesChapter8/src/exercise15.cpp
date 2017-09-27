

#include "exercise15.h"
#include <cmath>
#include "gwindow.h"
#include "random.h"

using namespace std;

//const
const double SIZE = 200;
const int ORDER = 5;


//func prototypes
GPoint drawFractalLine (GWindow & gw, GPoint pt, double r, double theta, int order);

//general
void exercise15() {
    GWindow gw;
    double cx = gw.getWidth() / 2;
    double cy = gw.getHeight() / 2;
    GPoint pt(cx - SIZE / 2, cy - sqrt(3.0) * SIZE / 6);
    pt = drawFractalLine(gw, pt, SIZE, 0, ORDER);
    //pt = drawFractalLine(gw, pt, SIZE, -120, ORDER);
    //pt = drawFractalLine(gw, pt, SIZE, 120, ORDER);
}

GPoint drawFractalLine (GWindow & gw, GPoint pt, double r, double theta, int order) {
    if (order == 0) {
        return gw.drawPolarLine(pt, r, theta);
    } else {
        int randomCore = 60 * randomInteger(-1, 1);
        pt = drawFractalLine(gw, pt, r / 3, theta + randomCore, order - 1);
        randomCore = 60 * randomInteger(-1, 1);
        pt = drawFractalLine(gw, pt, r / 3, theta + randomCore, order - 1);
        randomCore = 60 * randomInteger(-1, 1);
        pt = drawFractalLine(gw, pt, r / 3, theta + randomCore, order - 1);
        return drawFractalLine(gw, pt, r / 3, theta, order - 1);
    }
}
