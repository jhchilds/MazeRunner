//
// Created by Joshua Childs on 4/17/18.
//

#include "PlayerPiece.h"
#include "graphics.h"

void PlayerPiece::calculateArea() {
    area = length * width;
}

void PlayerPiece::calculatePerimeter() {
    perimeter = 2.0 * length + 2.0 * width;
}

PlayerPiece::PlayerPiece() : Piece(), length(0), width(0) { }

PlayerPiece::PlayerPiece(int l, int w) : Piece() {
    setDimensions(l, w);
}

PlayerPiece::PlayerPiece(point c, color b, color f, int l, int w) : Piece(c,b,f) {
    setDimensions(l,w);
}

int PlayerPiece::getLength() const {
    return length;
}

int PlayerPiece::getWidth() const {
    return width;
}

void PlayerPiece::setDimensions(int l, int w) {
    // validation for negative values
    length = (l < 0) ? 0 : l;
    width = (w < 0) ? 0 : w;
    // update area and perimeter
    calculateArea();
    calculatePerimeter();
}

/**
 * FORMAT
 * PLAYERPIECE
 * LENGTH
 * WIDTH
 * CENTER X,Y
 * FILL R,G,B
 * BORDER R,G,B
 */
ostream& operator << (ostream& outs,
                      const PlayerPiece &p) {
    outs << "PLAYERPIECE" << endl;
    outs << p.getLength() << endl;
    outs << p.getWidth() << endl;
    outs << p.getCenter().x << "," << p.getCenter().y << endl;
    outs << p.getFillColor().red << "," << p.getFillColor().green << "," << p.getFillColor().blue << endl;
    outs << p.getBorderColor().red << "," << p.getBorderColor().green << "," << p.getBorderColor().blue << endl;
    return outs;
}
/**
 * FORMAT
 * PLAYERPIECE (type)
 * LENGTH
 * WIDTH
 * CENTER X,Y
 * FILL R,G,B
 * BORDER R,G,B
 */
istream& operator >> (istream& ins,
                      PlayerPiece &p) {

    string type, length, width, startX, startY, fillRed, fillGreen, fillBlue, borderRed, borderGreen, borderBlue;

    if (ins) {
        //type is burned already, so just jump into reading
        getline(ins, length);
        getline(ins, width);
        getline(ins, startX, ',');
        getline(ins, startY);
        getline(ins, fillRed, ',');
        getline(ins, fillGreen, ',');
        getline(ins, fillBlue);
        getline(ins, borderRed, ',');
        getline(ins, borderGreen, ',');
        getline(ins, borderBlue);

        p.setDimensions(stoi(length), stoi(width));
        p.setCenter(stoi(startX), stoi(startY));
        p.setFillColor(stoi(fillRed), stoi(fillGreen), stoi(fillBlue));
        p.setBorderColor(stoi(borderRed), stoi(borderGreen), stoi(borderBlue));
    }
    return ins;
}



void PlayerPiece::draw() const {
    // draw fill
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_QUADS);
    // top left
    glVertex2i(center.x-(width/2.0), center.y-(length/2.0));
    // top right
    glVertex2i(center.x+(width/2.0), center.y-(length/2.0));
    // bottom right
    glVertex2i(center.x+(width/2.0), center.y+(length/2.0));
    // bottom left
    glVertex2i(center.x-(width/2.0), center.y+(length/2.0));
    glEnd();

    glLineWidth((GLfloat)5.0);
    // draw border
    glColor3f(border.red, border.green, border.blue);
    glBegin(GL_LINE_STRIP);
    // top left
    glVertex2i(center.x-(width/2.0), center.y-(length/2.0));
    // top right
    glVertex2i(center.x+(width/2.0), center.y-(length/2.0));
    // bottom right
    glVertex2i(center.x+(width/2.0), center.y+(length/2.0));
    // bottom left
    glVertex2i(center.x-(width/2.0), center.y+(length/2.0));
    // top left
    glVertex2i(center.x-(width/2.0), center.y-(length/2.0));
    glEnd();
};