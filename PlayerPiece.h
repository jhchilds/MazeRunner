//
// Created by Joshua Childs on 4/17/18.
//
#ifndef GIT_UP_AND_GO_PLAYERPIECE_H
#define GIT_UP_AND_GO_PLAYERPIECE_H

#include "Piece.h"

class PlayerPiece : public Piece {
private:
    double length;
    double width;

    /**
     * Area calculator
     * Requires: Nothing
     * Modifies: The area field
     * Effects: Calculates the area from length and width of the object and sets the area field
     */
    void calculateArea() override;

    /**
     * Perimeter calculator
     * Requires: Nothing
     * Modifies: The perimeter field
     * Effects: Calculates the perimeter from the length and width of the object and sets the area field
     */
    void calculatePerimeter() override;

public:
    /**
     * Default PlayerPiece constructor
     * Requires: Nothing
     * Modifies: Doubles length and width
     * Effects: Calls Piece constructor and initializes length/width to zero
     */
    PlayerPiece();



    /**
     * Non-Default PlayerPiece constructor
     * Requires: Double l and double w
     * Modifies: The length and width fields
     * Effects: Calls Piece constructor, calls setDimensions method and passes l and w values
     */
    PlayerPiece(int l, int w);

    PlayerPiece(point c, color b, color f, int l, int w);

    // Getters
    /**
     * Length Getter
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Returns the length field
     */
    int getLength() const;
    /**
     * Width gettter
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Returns the width field
     */
    int getWidth() const;

    // Setters
    /**
     * Dimension setter
     * Requires: double l and double w
     * Modifies: the length, width, area, and perimeter fields
     * Effects: Sets the length and width fields, calls calcArea and calcPerimeter methods
     */
    void setDimensions(int l, int w);

    /**
     * Draw PlayerPiece
     * Requires: Nothing
     * Modifies: Nothing
     * Effects: Draws the PlayerPiece
     */
    void draw() const override;

    /**
    * Overloaded Operator (binary)
    * Friend of the class (not a member)
    * Requires: nothing
    * Modifies: nothing
    * Effects: prints the PlayerPiece location to file
    * FORMAT BELOW
    * PLAYERPIECE
    * LENGTH
    * WIDTH
    * CENTER X,Y
    * FILL R,G,B
    * BORDER R,G,B
    */

    friend ostream& operator << (ostream& outs,
                                 const PlayerPiece &p);


/**
    * Overloaded Operator (binary)
    * Friend of the class (not a member)
    * Requires: nothing
    * Modifies: nothing
    * Effects: read the PlayerPiece Skills in from the istream
   */
    friend istream& operator >> (istream& ins,
                             PlayerPiece &p);

};

#endif //GIT_UP_AND_GO_PLAYERPIECE_H
