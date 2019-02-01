//
// Created by PC on 4/19/2018.
//

#include "Switch.h"
#include "graphics.h"

//Constructors
Switch::Switch() : center({0,0}), height(0), width(0) {}

Switch::Switch(point centerIn, int heightIn, int widthIn) : center(centerIn), height(heightIn), width(widthIn){}

//Getters
point Switch::getCenter() const {
    return center;
}

int Switch::getHeight() const {
    return height;
}

int Switch::getWidth() const {
    return width;
}

//Setters

void Switch::setCenter(point c) {
    center=c;
}

void Switch::setCenter(int xIn, int yIn) {
    center.x=xIn;
    center.y-yIn;
}

void Switch::setHeight(int heightIn) {
    height=heightIn>0?heightIn:1;
}

void Switch::setWidth(int widthIn) {
    width=widthIn>0?widthIn:1;
}

void Switch::draw() const {

    glBegin(GL_QUADS);
    // draw fill
    glColor3f(color.red, color.green, color.blue);
    // top left
    glVertex2i(center.x-(width/2.0), center.y-(height/2.0));
    // top right
    glVertex2i(center.x+(width/2.0), center.y-(height/2.0));
    // bottom right
    glVertex2i(center.x+(width/2.0), center.y+(height/2.0));
    // bottom left
    glVertex2i(center.x-(width/2.0), center.y+(height/2.0));
    glEnd();
}

std::istream& operator>>(std::istream & ins, Switch & toFill) {
    std::string centerx, centery, height, width;
    getline(ins, centerx,',');
    getline(ins, centery);
    getline(ins, height);
    getline(ins, width);

    while (!isalnum(centery[centery.length() - 1])) {
        centery = centery.substr(0, centery.length() - 1);
    }
    if (isInt(centerx) && isInt(centery)) {
        toFill.center = {std::stoi(centerx),std::stoi(centery)};
    }
    else {
        toFill.center = {0,0};
    }

    while (!isalnum(height[height.length() - 1])) {
        height = height.substr(0, height.length() - 1);
    }
    if (isInt(height)) {
        toFill.height = stoi(height);
    }
    else {
        toFill.height = 0;
    }

    while (!isalnum(width[width.length() - 1])) {
        width = width.substr(0, width.length() - 1);
    }
    if (isInt(width)) {
        toFill.width = stoi(width);
    }
    else {
        toFill.width = 0;
    }

    return ins;
}

std::ostream& operator<<(std::ostream & outs, Switch toPrint) {
    outs << toPrint.center.x << "," << toPrint.center.y << std::endl;
    outs << toPrint.height << std::endl;
    outs << toPrint.width << std::endl;
    return outs;
}

Switch& Switch::operator=(const Switch& toCopy) {
    this->center = toCopy.center;
    this->height = toCopy.height;
    this->width = toCopy.width;
    return *this;
}