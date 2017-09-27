
#include "gwindow.h"
#include "gtypes.h"
#include "paintertask4.h"
#include "vector.h"


    void setPointsOnBorders(Vector<GPoint> &points);
    void drawLines(Vector<GPoint> &points);

    PainterTask4::PainterTask4() {
    }


    void PainterTask4::draw() {
        Vector<GPoint> points;
        setPointsOnBorders(points);
        drawLines(points);
    }

    void drawLines(Vector<GPoint> &points) {
        GWindow window(WINDOW_WIDTH, WINDOW_HEIGHT);
        window.setColor("White");
        window.clear();
        window.setColor("Black");


        GPoint p1 = points[0];
        GPoint p2 = points[DELTA];
        int curPosition = 0;
        int sumOfPoints = N_ACROSS * 2 + N_DOWN * 2 - 4;
        while(true) {
            curPosition = curPosition + DELTA;
            if(curPosition > sumOfPoints) {
                curPosition = curPosition % sumOfPoints;
            }
            else if(curPosition == sumOfPoints) {
               break;
            }

            p2 = points[curPosition];
            window.drawLine(p1,p2);
            p1 = p2;
        }

        window.setVisible(true);
    }

    void setPointsOnBorders(Vector<GPoint> &points){
        double sizeOfPegHorizont = double(WINDOW_WIDTH) / (N_ACROSS - 1);
        double sizeOfPegVertical = double(WINDOW_HEIGHT) / (N_DOWN - 1);
        GPoint lastPoint;
        //top
        for(int i = 0; i < N_ACROSS; i++) {
            GPoint pt(sizeOfPegHorizont*i,0);
            points.add(pt);
            lastPoint = pt;
        }
        //right
        for(int i = 1; i < N_DOWN; i++) {

            GPoint pt(lastPoint.getX(),sizeOfPegVertical*i);
            points.add(pt);
            lastPoint = pt;
        }
        //bottom
        for(int i = N_ACROSS; i > 1; i--) {
            GPoint pt(sizeOfPegHorizont*i - sizeOfPegHorizont*2,lastPoint.getY());
            points.add(pt);
            lastPoint = pt;
        }
        //left
        for(int i = N_DOWN; i > 2; i--){
            GPoint pt(lastPoint.getX(),sizeOfPegVertical*i - sizeOfPegVertical*2);
            points.add(pt);
            lastPoint = pt;
        }
    }




