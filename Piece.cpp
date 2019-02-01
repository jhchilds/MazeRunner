//
// Created by Joshua Childs on 4/12/18.
//

#include "Piece.h"

/******************** Point Struct ********************/

point::point() : x(0), y(0) { }

point::point(int xIn, int yIn) : x(xIn), y(yIn) { }

ostream& operator<<(ostream& outs, const point & toPrint) {
    outs<<toPrint.x<<","<<toPrint.y;
}

/******************** Piece Class ********************/

Piece::Piece() : area(0), perimeter(0), center({0, 0}),
                  fill({0, 0, 0}), border({0, 0, 0}) {
    // color defaults to black
}

Piece::Piece(point c, color b, color f) : area(0), perimeter(0),
                                          center(c),
                                          border(b), fill(f) { }

Piece::Piece(int xIn, int yIn,
             double rb, double gb, double bb,
             double rf, double gf, double bf) : area(0),
                                                perimeter(0),
                                                center({xIn, yIn}),
                                                border({rb, gb, bb}),
                                                fill({rf, gf, bf}) { }

point Piece::getCenter() const {
    return center;
}

color Piece::getBorderColor() const {
    return border;
}

color Piece::getFillColor() const {
    return fill;
}

double Piece::getArea() const {
    return area;
}

double Piece::getPerimeter() const {
    return perimeter;
}

void Piece::setCenter(point c) {
    center = c;
}

void Piece::setCenter(int xIn, int yIn) {
    center = {xIn, yIn};
}

void Piece::move(int deltaX, int deltaY) {
    center.x += deltaX;
    center.y += deltaY;
}

void Piece::setBorderColor(color b) {
    border = b;
}

void Piece::setBorderColor(double r, double g, double b) {
    border = {r, g, b};
}

void Piece::setFillColor(color f) {
    fill = f;
}

void Piece::setFillColor(double r, double g, double b) {
    fill = {r, g, b};
}