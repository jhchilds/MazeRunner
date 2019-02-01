//
// Created by PC on 4/6/2018.
//
#include "Line.h"
#include "graphics.h"
#include <cmath>

double distance(point a, point b) {
    return sqrt((b.y - a.y) * (b.y - a.y) + (b.x-a.x) * (b.x-a.x));
}

bool isInt(std::string toCheck) {
    if (toCheck == ""){return false;}//if empty string is input, its not an integer
    int count = 0;
    for(count; count < toCheck.length(); count++) {
        if (toCheck[count] != '1' && toCheck[count] != '2' && toCheck[count] != '3' && toCheck[count] != '4' &&
            toCheck[count] != '5' && toCheck[count] != '6' && toCheck[count] != '7' && toCheck[count] != '8' &&
            toCheck[count] != '9' && toCheck[count] != '0'){
            return false;
        }//if character is not a digit, return false
    }
    return true;//otherwise (all chars are digits), and input is not empty string, return true
}

std::string orientationToString(Orientation orient) {
    if (orient == VERTICAL) {
        return "VERTICAL";
    }
    else {
        return "HORIZONTAL";
    }
}

Orientation stringToOrientation(std::string orient) {
    if (orient == "VERTICAL" ) {
        return VERTICAL;
    }
    else {
        return HORIZONTAL;
    }
}

/***********************LINE CLASS**********************/
Line::Line(): start({0,0}),length(0), orientation(VERTICAL) {}

Line::Line(struct point startIn, int lengthIn, Orientation toGo) {
    setStart(startIn);
    if (lengthIn < 0 ) {
        lengthIn = 5;
    }
    length = lengthIn;
    orientation = toGo;
}

void Line::draw() const {
    glLineWidth((GLfloat)5);
    glBegin(GL_LINE_STRIP);
    glColor3f(clr.red,clr.blue,clr.green);
    glVertex2i(start.x,start.y);
    if (orientation == VERTICAL) {
        glVertex2i(start.x,start.y-length);
    }
    else {
        glVertex2i(start.x+length,start.y);
    }
    glEnd();
}

point Line::getStart() const {
    return start;
}

int Line::getLength() const {
    return length;
}

Orientation Line::getOrientation() const {
    return orientation;
}

std::vector<point> Line::getPoints() const {
    std::vector<point> toReturn = {};
    switch (orientation) {

        case (HORIZONTAL) : {
            for (int i = 0; i <= length; i++) {
                point toAdd = {start.x+i,start.y};
                toReturn.emplace_back(toAdd);
            }
            break;
        }

        case (VERTICAL) : {
            for (int i = 0; i <= length; i++) {
                point toAdd = {start.x,start.y-i};
                toReturn.emplace_back(toAdd);
            }
            break;
        }

    }
    return toReturn;
}

void Line::setStart(point newStart) {
    if (newStart.x > 0 || newStart.y > 0) {
        start = newStart;
    }
}

void Line::setOrientation(Orientation newOrientation) {
    orientation = newOrientation;
}

void Line::setLength(int newL) {
    if (newL > 0) {
        length = newL;
    }
}

point Line::getClosestPoint(int xIn, int yIn) const {
    double minDistance = 10000;
    point closest = {0,0};
    for (point p : getPoints()) {
        if (distance(p,{xIn,yIn}) < minDistance){
            minDistance = distance(p,{xIn,yIn});
            closest = p;
        }
    }

    return closest;
}

