//
// Created by PC on 4/24/2018.
//

#ifndef GIT_UP_AND_GO_SQUARE_H
#define GIT_UP_AND_GO_SQUARE_H

#include "Piece.h"

class Square {
private:
    point center;
    color fill;
    color border;
    color textColor;
    string message;
    int height, width;
    int yOffset, xOffset;

public:
    Square();
    Square(point cIn, color fIn, color bIn, color tIn, string mIn, int hIn, int wIn, int xOff, int yOff);

    point getCenter() const;
    color getFillColor() const;
    color getBorderColor() const;
    color getTextColor() const;
    int getHeight() const;
    int getWidth() const;
    string getMessage() const;
    int getYOffset() const;
    int getXOffset() const;

    void setCenter(point newC);
    void setFillColor(color newF);
    void setBorderColor(color newB);
    void setTextColor( color newT);
    void setHeight(int newH);
    void setWidth(int newW);
    void setMessage(string newM);

    void draw() const;

    bool overlappingPoint(point toCheck) const;

    /**
     * format:
     * height
     * width
     * start center
     * fr,fg,fb
     * br,bg,bb
     * message text
     * tr,tg,tb
     */
    friend istream& operator>>(istream& ins, Square & toFill);
    friend ostream& operator<<(ostream & outs, const Square & toPrint);
};

#endif
