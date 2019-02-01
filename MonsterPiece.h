//
// Created by Joshua Childs on 4/17/18.
//

#ifndef GIT_UP_AND_GO_MONSTERPIECE_H
#define GIT_UP_AND_GO_MONSTERPIECE_H

#include "PlayerPiece.h"
#include <vector>

//MonsterPiece class extends Piece

class MonsterPiece : public Piece {
private:
    int length;
    int width;
    std::vector<point> endPoints;
    int path;

   /**
   * Requires: length and width
   * Modifies: nothing
   * Effects: calculates area by length*width
   */
    void calculateArea() override;
    /**
   * Requires: length and width
   * Modifies: nothing
   * Effects: calculates perim by 2(length) + 2(width)
   */
    void calculatePerimeter() override;

public:
   /**
   * Requires: nothing
   * Modifies: length and width
   * Effects: creates Piece() object with a default length and width
   */
    MonsterPiece();


    /**
   * Requires: nothing
   * Modifies: length and width
   * Effects: creates Piece() object with a specified length and width
                trusts input ends
     */
    MonsterPiece(int l, int w);

    MonsterPiece(point start, color border, color fill,int l, int w);

    // Getters
  /**
   * Requires: nothing
   * Modifies: nothing
   * Effects: returns length
   */
    int getLength() const;
  /**
   * Requires: nothing
   * Modifies: nothing
   * Effects: returns width
   */
    int getWidth() const;

    vector<point> getEndPoints() const;

    int getPath() const;

    // Setters
  /**
   * Requires: nothing
   * Modifies: length and width
   * Effects: nothing
   */
    void setDimensions(int l, int w);

    void setEndPoints(std::vector<point> ends);

    void setPath(int newPath);

    void addEndPoint(point toAdd);

    bool checkPlayer(PlayerPiece player) const;

    void moveOnPath();

/**
   * Requires: MonterPiece object
   * Modifies: nothing
   * Effects: draws MonsterPiece as rectangle to graphics
   */
    void draw() const override;


    /**
    * Overloaded Operator (binary)
    * Friend of the class (not a member)
    * Requires: nothing
    * Modifies: nothing
    * Effects: prints the MonsterPiece location to file
    * FORMAT BELOW
    * MONSTERPIECE
     * ENDPOINT (X,Y)
     * ENDPOINT (X,Y)
     * ETC...
     * "E"
    * LENGTH
    * WIDTH
    * CENTER (X,Y)
    * FILL (R,G,B)
    * BORDER (R,G,B)
     *
    */
    friend ostream& operator<< (ostream& outs,
                                 const MonsterPiece &m);


    /**
    * Overloaded Operator (binary)
    * Friend of the class (not a member)
    * Requires: nothing
    * Modifies: nothing
    * Effects: read the MonsterPiece Skills in from the istream
   */
    friend istream& operator>> (istream& ins,
                                 MonsterPiece &m);

    MonsterPiece& operator=(const MonsterPiece& toCopy);
};
#endif //GIT_UP_AND_GO_MONSTERPIECE_H
