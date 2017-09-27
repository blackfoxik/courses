

#include "exercise18.h"
#include "gwindow.h"
#include "simpio.h"
#include <cmath>


using namespace std;
//const


//func prototypes
void drawSierpinskiTriangle (GWindow & gw, GPoint a, GPoint b, GPoint c, double edgeLength, int order);

//general
void exercise18() {
    GWindow gw;
    double cx = gw.getWidth() / 2;
    double cy = gw.getHeight() / 2;
    double edgeLength = getReal("Enter edge length: ");
    int fractalOrder = getInteger("Enter fractal order: ");
    double h = (sqrt(3) / 2) * edgeLength;
    GPoint a(cx - edgeLength / 2, cy + h / 2);
    GPoint b(cx, cy - h / 2);
    GPoint c(cx + edgeLength / 2, cy + h / 2);

    drawSierpinskiTriangle (gw, a, b, c, edgeLength, fractalOrder);

}

void drawSierpinskiTriangle (GWindow & gw, GPoint a, GPoint b, GPoint c, double edgeLength, int order) {
    if (order == 0) {
        return;
    } else {
        //     b
        //   a   c
        gw.drawLine(a, b);
        gw.drawLine(b, c);
        gw.drawLine(a, c);

        //            b
        //
        //       ab1      bc1
        //
        //   a       ac1       c

        double h1 = (sqrt(3) / 2) * edgeLength / 2;
        GPoint ac1(a.getX() + edgeLength / 2, a.getY());
        GPoint ab1(a.getX() + edgeLength / 4, a.getY() - h1);
        GPoint bc1(c.getX() - edgeLength / 4, ab1.getY());

        drawSierpinskiTriangle(gw, a, ab1, ac1, edgeLength / 2, order - 1);
        drawSierpinskiTriangle(gw, ab1, b, bc1, edgeLength / 2, order - 1);
        drawSierpinskiTriangle(gw, ac1, bc1, c, edgeLength / 2, order - 1);
    }
}
