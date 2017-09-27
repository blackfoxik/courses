#include <string>
//#include <ostream>
#include "gtypes.h"
using namespace std;
//all in comments because Stanford lib already has this implemantation
/*
GRectangle::GRectangle() {
    x = 0;
    y = 0;
    height = 0;
    width = 0;
}

GRectangle::GRectangle(double inputX, double inputY, double inputWidth, double inputHeight) {
    x = inputX;
    y = inputY;
    width = inputWidth;
    height = inputHeight;
}

double GRectangle::getX() const {
    return x;
}

double GRectangle::getY() const {
    return y;
}

double GRectangle::getWidth() const {
    return width;
}

double GRectangle::getHeight() const {
    return height;
}

bool GRectangle::isEmpty() const {
    return width <= 0 || height <= 0;
}

bool GRectangle::contains(double inputX, double inputY) const {
    if (((inputX >= x) || (inputX <= x + width)) && ((inputY >= y) || (inputY <= y + height))){
    return true;
    }
    else{
        return false;
    }
}

bool GRectangle::contains(GPoint inputPt) const {
    return contains(inputPt.getX(), inputPt.getY());
}

string GRectangle::toString() const {
    return "(" + to_string(x) + ", " + to_string(y) + " ," + to_string(width) + ", " + to_string(height);
}

friend bool operator==(const GRectangle & r1, const GRectangle & r2) {
    if ((r1.x == r2.x) && (r1.height == r2.width) && (r1.height == r2.height)) {
        return true;
    }
    else {
        return false;
    }
}

friend bool operator!=(const GRectangle & r1, const GRectangle & r2) {
    if (r1 == r2){
        return false;
    }
    else {
        return true;
    }
}

ostream &operator <<(ostream &os, GRectangle r){
    return r.toString();
}

friend int hashCode(const GRectangle & r) {
    // in this chapter we do not learn hash yet
    int 0;
}
*/


