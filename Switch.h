//
// Created by PC on 4/19/2018.
//

#ifndef GIT_UP_AND_GO_SWITCH_H
#define GIT_UP_AND_GO_SWITCH_H

#include "Line.h"
#include "Piece.h"
#include <iostream>

//basically, just a rectangle
class Switch {
public:
    /**
     * Default Switch constructor
     * Requires: Nothing
     * Modifies: center point, height and width fields
     * Effects: Sets center to (0,0) and height/width field
     */
    Switch();

    /**
     * Non-Default Switch constructor
     * Requires: center point, int heightIn, int widthIn
     * Modifies: center point, height and width fields
     * Effects: sets the center point, height, and width fields
     */
    Switch(point centerIn, int heightIn, int widthIn);

    //getters
    /**
     * Center getter
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: returns the center point
     */
    point getCenter() const;

    /**
     * Height getter
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: returns the height field
     */
    int getHeight() const;

    /**
     * Width getter
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: returns the width field
     */
    int getWidth() const;

    //setters
    /**
     * Primary Center setter
     * Requires: A point C
     * Modifies: the center point of the switch
     * Effects: sets the center point of the switch to the passed in center point
     */
    void setCenter(point c);

    /**
     * Secondary Center setter
     * Requires: int xIn and int yIn
     * Modifies: the center point of the switch
     * Effects: setst eh center point of the switch to the passed in x and y coordinates
     */
    void setCenter(int xIn, int yIn);

    /**
     * Height setter
     * Requires: int heightIn
     * Modifies: the height field
     * Effects: sets the height field to the passed in value
     */
    void setHeight(int heightIn);

    /**
     * Width setter
     * Requires: int widthIn
     * Modifies: the width field
     * Effects: sets the width field to the passed in value
     */
    void setWidth(int widthIn);

    void draw() const;

    /**
     * format:
     * centerx,centery
     * height
     * width
     */
    friend std::istream& operator>>(std::istream & ins, Switch & toFill);
    friend std::ostream& operator<<(std::ostream & outs, Switch toFill);

    Switch& operator=(const Switch & toCopy);

private:
    point center;
    int height, width;
    const color color = {0,255,0};//switches are green
};

#endif //GIT_UP_AND_GO_SWITCH_H
