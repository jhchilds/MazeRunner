//
// Created by PC on 4/19/2018.
//

#include "Wall.h"

Wall::Wall() {
    start = {0,0};
    orientation = VERTICAL;
    length = 0;
}

Wall::Wall(point startIn, int lengthIn, Orientation toGo) :
            Line(startIn,lengthIn,toGo) {}

bool Wall::checkPlayer(PlayerPiece player) const {
    point closest = getClosestPoint(player.getCenter().x,player.getCenter().y);
    return (closest.x >= player.getCenter().x-(player.getWidth()/2.0) - 5 &&//closest point on line > player left edge (-5 for border)
            closest.x <= player.getCenter().x+(player.getWidth()/2.0) + 5 &&//closest x < player right edge + 5 for overlap
            closest.y >= player.getCenter().y -(player.getLength()/2.0) - 5 &&//y of closest point is below (greater than) y of player top - 5
            closest.y <= player.getCenter().y +(player.getLength()/2.0) + 5);//y of closest is above (less than) y of player bottom + 5
}

std::ostream &operator<<(std::ostream & outs, const Wall & toPrint) {
    outs<<"WALL"<<endl;
    outs << toPrint.getStart().x <<","<< toPrint.getStart().y<<std::endl;
    outs << toPrint.getLength() << std::endl;
    if (toPrint.orientation == VERTICAL) {
        outs << "VERTICAL";
    }
    else {
        outs << "HORIZONTAL";
    }
    outs << std::endl;
    return outs;
}

std::istream& operator>>(std::istream & ins, Wall & toFill) {
    std::string startx,starty, orien, lngth;

    if (ins) {
        getline(ins, startx, ',');
        getline(ins, starty);
        getline(ins, lngth);
        getline(ins, orien);
    }

    while (!isalnum(starty[starty.length()-1])) {
        starty = starty.substr(0, starty.length()-1);
    }
    if (isInt(startx) && isInt(starty)) {
        toFill.setStart({stoi(startx),stoi(starty)});
    }
    else {
        toFill.setStart({0,0});
    }
    while (!isalnum(lngth[lngth.length()-1])) {
        lngth = lngth.substr(0, lngth.length()-1);
    }
    if (isInt(lngth)) {
        toFill.setLength(stoi(lngth));
    }
    else {
        toFill.setLength(0);
    }
    while (!isalnum(orien[orien.length()-1])) {
        orien = orien.substr(0, orien.length()-1);
    }
    if (orien == "HORIZONTAL") {
        toFill.setOrientation(HORIZONTAL);
    }
    else {
        toFill.setOrientation(VERTICAL);
    }

    return ins;

}

Wall& Wall::operator=(const Wall& toCopy) {
    this->start = toCopy.start;
    this->orientation = toCopy.orientation;
    this->length = toCopy.length;
    return *this;
}