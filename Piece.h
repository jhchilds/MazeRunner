//
// Created by Joshua Childs on 4/12/18.
//


#ifndef GIT_UP_AND_GO_PIECE_H
#define GIT_UP_AND_GO_PIECE_H

using namespace std;

#include <iostream>
#include <iomanip>
#include <cmath>


struct color {
    double red;
    double green;
    double blue;

};
/**
 * Location data for each line
 */
struct point {
    // public fields
    int x;
    int y;

    point();
    point(int xIn, int yIn);

    friend ostream& operator<<(ostream& outs, const point & toPrint);
};

class Piece {
protected:
    point center;
    color border;
    color fill;
    double area;
    double perimeter;
    virtual void calculateArea() = 0;
    virtual void calculatePerimeter() = 0;

public:
    // Constructors
    /**
    * Requires: nothing
    * Modifies: Piece with defaults at zero
    * Effects: Area, Perimeter, Center, Fill, Border at 0
    */
    Piece();
    /**
    * Requires: nothing
    * Modifies: Piece with specified Fill
    * Effects: Area, Perimeter, Center, Fill(specified), Border
    */
    Piece(point c, color b, color f);
    /**
    * Requires: nothing
    * Modifies: Piece with specified point, fill, and border
    * Effects: Area, Perimeter, Center, Fill(specified), Border
    */
    Piece(int xIn, int yIn, double rb, double gb, double bb, double rf, double gf, double bf);

    // Getters

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns center
    */
    point getCenter() const;

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns Border Color
    */
    color getBorderColor() const;

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns Fill Color
    */
    color getFillColor() const;

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns Area
    */
    double getArea() const;

    /**
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns Perimeter
    */
    double getPerimeter() const;

    // Setters

    /**
    * Requires: nothing
    * Modifies: Center
    * Effects: Sets center to point c
    */
    void setCenter(point c);

    /**
    * Requires: nothing
    * Modifies: Center
    * Effects: Sets center to 2 ints, x and y
    */
    void setCenter(int xIn, int yIn);

    /**
    * Requires: nothing
    * Modifies: points x and y
    * Effects: Sets center deltaX and deltaY
    */
    void move(int deltaX, int deltaY);

    /**
    * Requires: nothing
    * Modifies: Border Color
    * Effects: Sets border color to color b
    */
    void setBorderColor(color b);

    /**
    * Requires: nothing
    * Modifies: Border Color
    * Effects: Sets border color by RGB values
    */
    void setBorderColor(double r, double g, double b);

    /**
    * Requires: nothing
    * Modifies: Fill Color
    * Effects: Sets fill color to color f
    */
    void setFillColor(color f);

    /**
    * Requires: nothing
    * Modifies: Fill Color
    * Effects: Sets fill color by RGB values
    */
    void setFillColor(double r, double g, double b);

    void overlapsPiece(Piece& toCheck);

    /**
    * Requires: pure virtual method to be overridden in subclasses
    * Modifies: GL values in Graphics
    * Effects: Draws Piece
    */
    virtual void draw() const = 0;
};

#endif //PROJECT_PIECE_H
