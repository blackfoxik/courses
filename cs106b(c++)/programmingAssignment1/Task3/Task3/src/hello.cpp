#include <iostream>
#include <math.h>
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "gevents.h"
#include "random.h"
#include "timer.h"


const int COUNT_VERTEX = 3;

void drawVertexes(GWindow &gw,Vector<GPoint> &vertexes);
void drawLines(GWindow &gw,Vector<GPoint> &vertexes);
GPoint getNextPoint(GPoint curPoint,GPoint secCurPoint);
void showLife(GWindow &gw,Vector<GPoint> &vertexes);
void waitForClose(GWindow &gw);

int main() {
    GWindow gw(800,600);
    gw.setColor("BLACK");
    gw.setVisible(true);

    Vector<GPoint> vertexes;

    drawVertexes(gw,vertexes);
    drawLines(gw,vertexes);

    showLife(gw,vertexes);

    waitForClose(gw);
    return 0;
}

void drawVertexes(GWindow &gw,Vector<GPoint> &vertexes){
    int curCountVertex = 0;
    while(curCountVertex<COUNT_VERTEX){
       GMouseEvent e = waitForClick();
       if(e.getEventType() == MOUSE_CLICKED){
           curCountVertex+=1;
           gw.fillOval(e.getX()-1,e.getY()-1,2,2);
           GPoint curPoint(e.getX(),e.getY());
           vertexes.push_back(curPoint);
       }
    }
}

void drawLines(GWindow &gw,Vector<GPoint> &vertexes){
    for(int i=0;i<COUNT_VERTEX;i++){
        if(i<COUNT_VERTEX-1){
            gw.drawLine(vertexes.get(i),vertexes.get(i+1));
        }
        else{
            gw.drawLine(vertexes.get(i),vertexes.get(0));
        }

    }
}

GPoint getNextPoint(GPoint curPoint,GPoint secCurPoint){
    double nextX;
    double nextY;
    double halfX = (fabs(curPoint.getX()-secCurPoint.getX()))/2;
    double halfY = (fabs(curPoint.getY()-secCurPoint.getY()))/2;

    if(curPoint.getX()>secCurPoint.getX()){
        nextX = curPoint.getX()-halfX;
    }
    else{
        nextX = secCurPoint.getX()-halfX;
    }

    if(curPoint.getY()>secCurPoint.getY()){
        nextY = curPoint.getY()-halfY;
    }
    else{
        nextY = secCurPoint.getY()-halfY;
    }

    return GPoint(nextX,nextY);
}

void showLife(GWindow &gw,Vector<GPoint> &vertexes){
    int curNumber = randomInteger(0,COUNT_VERTEX-1);
    GPoint curPoint = vertexes.get(curNumber);
    GTimer timer(1);
    timer.start();
    while(true){
        GEvent e = waitForEvent(CLICK_EVENT|TIMER_EVENT);
        if(e.getEventType() == MOUSE_CLICKED){
            timer.stop();
            break;
        }

        int secCurNumber = randomInteger(0,COUNT_VERTEX-1);
        GPoint secCurPoint = vertexes.get(secCurNumber);
        curPoint = getNextPoint(curPoint,secCurPoint);
        gw.fillOval(curPoint.getX()-2,curPoint.getY()-2,2,2);
    }
}

void waitForClose(GWindow &gw){
    while(true){
        GEvent e = waitForEvent(CLICK_EVENT);
        if(e.getEventType() == MOUSE_CLICKED){
            gw.close();
            break;
        }
    }
}
