//
// Created by PC on 4/19/2018.
//

#include "Door.h"
#include "graphics.h"

Door::Door() : Line(), isOpen(false), toOpen(Switch()) {}

Door::Door(point startIn, int lengthIn, Orientation toGo, bool open,
           Switch toOpn) : Line(startIn, lengthIn,toGo), isOpen(open), toOpen(toOpn){}

Switch Door::getSwitch() const {
   return toOpen;
}

void Door::setOpen(string opn) {
    if (opn == "FALSE") {
        isOpen =false;
    }
    else {
        isOpen = true;
    }
}

bool Door::open() {
    if (isOpen) {
        return false;
    }
    length = 0;
    draw();
    isOpen = true;
    return isOpen;
}

bool Door::getDoorState() const {
    return isOpen;
}

bool Door::checkSwitch(PlayerPiece player) {
    return !(toOpen.getCenter().x+(toOpen.getWidth()/2.0) < player.getCenter().x-(player.getWidth()/2.0) || // switch is left of player
             player.getCenter().x+(player.getWidth()/2.0) < toOpen.getCenter().x-(toOpen.getWidth()/2.0) || // player is left of switch
             toOpen.getCenter().y-(length/2.0) > player.getCenter().y+(player.getLength()/2.0) || // switch is below player
             player.getCenter().y-(player.getLength()/2.0) > toOpen.getCenter().y+(toOpen.getHeight()/2.0));//player is below switch
}

bool Door::checkPlayer(PlayerPiece player) {
    point closest = getClosestPoint(player.getCenter().x, player.getCenter().y);
    //+/- 5 for border
    return (closest.x >= player.getCenter().x - (player.getWidth() / 2.0 - 5) &&//closest is encroaching on left side (player approaching from right)
            closest.x <= player.getCenter().x + (player.getWidth() / 2.0 + 5) &&//closest is encroaching from the right (player approaching from left)
            (closest.y >= player.getCenter().y - (player.getLength() / 2.0) -5) &&//closest is lower than top of player
            closest.y <= player.getCenter().y + (player.getLength() / 2.0) + 5);//closest is higher than bottom of player
}

std::istream & operator>>(std::istream & ins, Door & toFill) {
    std::string strtx,strty, orient, lngth,open;
    if (ins) {
        getline(ins, strtx, ',');
        getline(ins, strty);
        getline(ins, orient);
        getline(ins, lngth);
        getline(ins, open);
        ins >> toFill.toOpen;

        while (!isalnum(strty[strty.length() - 1])) {
            strty = strty.substr(0, strty.length() - 1);
        }

        if (isInt(strtx) && isInt(strty)) {
            toFill.setStart({stoi(strtx), stoi(strty)});
        } else {
            toFill.setStart({0, 0});
        }

        while (!isalnum(lngth[lngth.length() - 1])) {
            lngth = lngth.substr(0, lngth.length() - 1);
        }

        if (isInt(lngth)) {
            toFill.setLength(stoi(lngth));
        } else {
            toFill.setLength(0);
        }
        while (!isalnum(orient[orient.length() - 1])) {
            orient = orient.substr(0, orient.length() - 1);
        }
        if (orient == "HORIZONTAL") {
            toFill.setOrientation(HORIZONTAL);
        } else {
            toFill.setOrientation(VERTICAL);
        }

        while (!isalnum(open[open.length() - 1])) {
            open = open.substr(0, open.length() - 1);
        }
        toFill.setOpen(open);
    }
    return ins;
}

std::ostream & operator<<(std::ostream & outs, const Door & toPrint) {
    outs << "DOOR" << std::endl;
    outs << toPrint.getStart().x << "," << toPrint.getStart().y << std::endl;
    outs << orientationToString(toPrint.getOrientation()) << std::endl;
    outs << toPrint.getLength() << std::endl;
    if (toPrint.isOpen) {
        outs << "TRUE" << std::endl;
    }
    else {
        outs << "FALSE" << std::endl;
    }
    outs << toPrint.getSwitch();
    return outs;
}

Door& Door::operator=(const Door& toCopy) {
    this->start = toCopy.start;
    this->orientation = toCopy.orientation;
    this->length = toCopy.length;
    this->isOpen = toCopy.isOpen;
    this->toOpen = toCopy.getSwitch();
    return *this;
}

void Door::draw() const {
    //draw door
    glLineWidth((GLfloat)5);
    glBegin(GL_LINE_STRIP);
    glVertex2i(start.x,start.y);
    glColor3f(0,255/255.0,0);//doors and switches are green
    if (orientation == VERTICAL) {
        glVertex2i(start.x,start.y-length);
    }
    else {
        glVertex2i(start.x+length,start.y);
    }
    glEnd();
    //draw switch
    toOpen.draw();
}