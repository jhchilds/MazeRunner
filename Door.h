//
// Created by PC on 4/19/2018.
//

#ifndef GIT_UP_AND_GO_DOOR_H
#define GIT_UP_AND_GO_DOOR_H

#include "Line.h"
#include "Switch.h"
#include "PlayerPiece.h"

/**
 * door and wall are lines
 * doors can open, which sets their length to 0
 */
class Door : public Line {
private:
    bool isOpen;
    Switch toOpen;

public:
    /**
     * calls line()
     * defaults to closed
     */
    Door();
    Door(point startIn, int lengthIn, Orientation toGo, bool isOpen,
         Switch toOpen);

    Switch getSwitch() const;

    void setOpen(string open);

    bool open();//returns false if already open; draws again after opening
    bool getDoorState() const; //returns bool of door open/close state
    bool checkSwitch(PlayerPiece player);//checks if player is on switch, and opens it if it does

    bool checkPlayer(PlayerPiece player);

    void draw() const override;

    /**
     *format
     * DOOR
     * startx, starty
     * orientation
     * length
     * isOpen
     * switch center location
     * switch width
     * switch height
     */
    friend std::istream & operator>>(std::istream & ins, Door & toFill);
    friend std::ostream & operator<<(std::ostream & outs, const Door & toPrint);

    //required because of some weird error we were getting
    Door& operator=(const Door & toCopy);
};

#endif //GIT_UP_AND_GO_DOOR_H
