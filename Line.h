//
// Created by PC on 4/6/2018.
//

#ifndef GIT_UP_AND_GO_LINE_H
#define GIT_UP_AND_GO_LINE_H

#include "Piece.h"
#include<vector>
#include <iostream>

//returns the distance between two points
double distance(point a, point b);

bool isInt(std::string toCheck);

enum Orientation {VERTICAL, HORIZONTAL};

std::string orientationToString(Orientation orient);

Orientation stringToOrientation(std::string orient);

/**
 * only supports straight lines
 */
class Line {
public:
    Line();

    //if length < 0, defaults to 5
    Line(point startIn, int lengthIn, Orientation toGo);//sets end point based on start point and direction - ensures straight lines

    virtual void draw() const;

    point getStart() const;
    int getLength() const;
    Orientation getOrientation() const;
    std::vector<point> getPoints() const; //returns vector of all points in the line

    void setStart(point newStart);//redraws the line
    //defaults to HORIZONTAL
    void setOrientation(Orientation newOrientation);
    void setLength(int newL);

    point getClosestPoint(int xIn, int yIn) const;

    //sees if radius > distance between closest point and tocheck
   // bool findConflict(PlayerPiece toCheck) const;
protected:
    point start;
    Orientation orientation;
    int length;
    const color clr = {55,219,197};
};

#endif
