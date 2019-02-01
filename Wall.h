//
// Created by PC on 4/19/2018.
//

#ifndef GIT_UP_AND_GO_WALL_H
#define GIT_UP_AND_GO_WALL_H

#include "Switch.h"
#include "Line.h"
#include "PlayerPiece.h"

class Wall : public Line {
public:
    //constructors

    /**
     * Default Wall constructor
     * Requires: Nothing
     * Modifies: start point, orientation enum, and length field
     * Effects: sets the start point to (0,0); the orientation to vertical; and the length to 0
     */
    Wall();

    /**
     * Non-default Wall constructor
     * Requires: point startIn, int lengthIn, and orientation toGo
     * Modifies: start point, orientation enum, and length field
     * Effects: sets the start point to the passed in point; the orientation and length to the passed in values
     */
    Wall(point startIn, int lengthIn, Orientation toGo);

    /**
     * OverlapWithPlayer method
     * Requires: A PlayerPiece object
     * Modifies: Nothing
     * Effects: Returns true if player overlaps with wall, false otherwise
     */
    bool checkPlayer(PlayerPiece player) const;

    /**
     * format:
     * startx,starty
     * length
     * orientation
     */
    friend std::ostream &operator<<(std::ostream & outs, const Wall & toPrint);
    friend std::istream & operator>>(std::istream & ins, Wall & toFill);

    /**
     * necessary because of some weird bug we were getting were creating a vector
     * of walls broke
     * @param toCopy
     * @return
     */
    Wall&operator=(const Wall& toCopy);

private:

};



#endif //GIT_UP_AND_GO_WALL_H
