//
// Created by PC on 4/24/2018.
//

#include "Square.h"
#include "Line.h"
#include "graphics.h"

Square::Square() : center({0,0}), fill({0,0,0}),border({0,0,0}), textColor({0,0,0}),
                            message(""), yOffset(0), xOffset(0) {}

Square::Square(point cIn, color fIn, color bIn, color tIn, string mIn, int hIn, int wIn, int xOff, int yOff) : center(cIn),
                        fill(fIn), border(bIn), textColor(tIn), message(mIn), width(wIn), height(hIn), xOffset(xOff), yOffset(yOff) {}

point Square::getCenter() const {
    return center;
}

color Square::getFillColor() const {
    return fill;
}

color Square::getBorderColor() const {
    return border;
}

color Square::getTextColor() const {
    return textColor;
}

int Square::getHeight() const {
    return height;
}

int Square::getWidth() const {
    return width;
}

string Square::getMessage() const {
    return message;
}

int Square::getYOffset() const {
    return yOffset;
}

int Square::getXOffset() const {
    return xOffset;
}

void Square::setCenter(point newC) {
    if (newC.x >= 0 && newC.y >= 0) {
        center = newC;
    }
}

void Square::setFillColor(color newF) {
    if (newF.red >= 0 && newF.blue >= 0 && newF.green >= 0) {
        fill = newF;
    }
}

void Square::setBorderColor(color newB) {
    if (newB.red >= 0 && newB.blue >= 0 && newB.green >= 0) {
        fill = newB;
    }
}

void Square::setTextColor(color newT) {
    if (newT.red >= 0 && newT.blue >= 0 && newT.green >= 0) {
        fill = newT;
    }
}

void Square::setHeight(int newH) {
    height = newH>0?newH:0;
}

void Square::setWidth(int newW) {
    width = newW>0?newW:0;
}

void Square::setMessage(string newM) {
    if (newM.size() >0) {
        message = newM;
    }
}

void Square::draw() const {
    // draw fill
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_QUADS);
    // top left
    glVertex2i(center.x-(width/2.0), center.y-(height/2.0));
    // top right
    glVertex2i(center.x+(width/2.0), center.y-(height/2.0));
    // bottom right
    glVertex2i(center.x+(width/2.0), center.y+(height/2.0));
    // bottom left
    glVertex2i(center.x-(width/2.0), center.y+(height/2.0));
    glEnd();

    glLineWidth((GLfloat)5.0);
    // draw border
    glColor3f(border.red, border.green, border.blue);
    glBegin(GL_LINE_STRIP);
    // top left
    glVertex2i(center.x-(width/2.0), center.y-(height/2.0));
    // top right
    glVertex2i(center.x+(width/2.0), center.y-(height/2.0));
    // bottom right
    glVertex2i(center.x+(width/2.0), center.y+(height/2.0));
    // bottom left
    glVertex2i(center.x-(width/2.0), center.y+(height/2.0));
    // top left
    glVertex2i(center.x-(width/2.0), center.y-(height/2.0));
    glEnd();

    //draw message
    glColor3f(textColor.red,textColor.green,textColor.blue);
    glRasterPos2i(center.x+xOffset,center.y+yOffset);
    for (char c:message) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c);
    }
}

bool Square::overlappingPoint(point toCheck) const {
    return (toCheck.x > center.x - width / 2 && toCheck.x < center.x + width / 2 && toCheck.y < center.y + height / 2 &&
            toCheck.y > center.y - height / 2);
}

istream& operator>>(istream& ins, Square & toFill) {
    string h,w,x,y,fillr,fillg,fillb,bordr,bordg,bordb,txt,tr,tg,tb,xOff,yOff;
    getline(ins,h);
    while (!isalnum(h[h.length() - 1])) {
        h = h.substr(0, h.length() - 1);
    }
    if (isInt(h)) {
        toFill.setHeight(stoi(h));
    }
    else {
        toFill.setHeight(0);
    }

    getline(ins,w);
    while (!isalnum(w[w.length() - 1])) {
        w = w.substr(0, w.length() - 1);
    }
    if (isInt(w)) {
        toFill.setWidth(stoi(w));
    }
    else {
        toFill.setWidth(0);
    }

    getline(ins,x,',');
    while (!isalnum(x[x.length() - 1])) {
        x = x.substr(0, x.length() - 1);
    }
    if (isInt(x)) {
        toFill.center.x = (stoi(x));
    }
    else {
        toFill.center.x =0;
    }

    getline(ins,y);
    while (!isalnum(y[y.length() - 1])) {
        y = y.substr(0, y.length() - 1);
    }
    if (isInt(y)) {
        toFill.center.y = (stoi(y));
    }
    else {
        toFill.center.y = 0;
    }

    getline(ins,fillr,',');
    if (isInt(fillr)) {
        toFill.fill.red=stoi(fillr);
    }
    else {
        toFill.fill.red = 0;
    }
    getline(ins,fillg,',');
    if (isInt(fillg)) {
        toFill.fill.green = (stoi(fillg));
    }
    else {
        toFill.fill.green = 0;
    }

    getline(ins,fillb);
    while (!isalnum(fillb[fillb.length() - 1])) {
        fillb = fillb.substr(0, fillb.length() - 1);
    }
    if (isInt(fillb)) {
        toFill.fill.blue = (stoi(fillb));
    }
    else {
        toFill.fill.blue = 0;
    }

    getline(ins,bordr,',');
    if (isInt(bordr)) {
        toFill.border.red = (stoi(bordr));
    }
    else {
        toFill.border.red = 0;
    }
    getline(ins,bordg,',');
    if (isInt(bordg)) {
        toFill.border.green = (stoi(bordg));
    }
    else {
        toFill.border.green = 0;
    }
    getline(ins,bordb);
    while (!isalnum(bordb[bordb.length() - 1])) {
        bordb = bordb.substr(0, bordb.length() - 1);
    }
    if (isInt(bordb)) {
        toFill.border.blue = (stoi(bordb));
    }
    else {
        toFill.border.blue = 0;
    }

    getline(ins,txt);
    while (!isalnum(txt[txt.length() - 1])) {
        txt = txt.substr(0, txt.length() - 1);
    }
    toFill.setMessage(txt);

    getline(ins,tr,',');
    while (!isalnum(tr[tr.length() - 1])) {
        tr = tr.substr(0, tr.length() - 1);
    }
    if (isInt(tr)) {
        toFill.textColor.red = (stoi(tr));
    }
    else {
        toFill.textColor.red = 0;
    }


    getline(ins,tg,',');
    while (!isalnum(tg[tg.length() - 1])) {
        tg = tg.substr(0, tg.length() - 1);
    }
    if (isInt(tg)) {
        toFill.textColor.green = (stoi(tg));
    }
    else {
        toFill.textColor.green = 0;
    }

    getline(ins,tb);
    while (!isalnum(tb[tb.length() - 1])) {
        tb = tb.substr(0, tb.length() - 1);
    }
    if (isInt(tb)) {
        toFill.textColor.blue = (stoi(tb));
    }
    else {
        toFill.textColor.blue = 0;
    }

    getline(ins,xOff);
    while (!isalnum(xOff[xOff.length() - 1])) {
        xOff = xOff.substr(0, xOff.length() - 1);
    }

    toFill.xOffset = (stoi(xOff));

    getline(ins,yOff);
    while (!isalnum(yOff[yOff.length() - 1])) {
        yOff = yOff.substr(0, yOff.length() - 1);
    }
    toFill.yOffset = (stoi(yOff));

    return ins;
}

ostream& operator<<(ostream& outs, const Square& toPrint) {
    outs<<toPrint.height<<endl;
    outs<<toPrint.width<<endl;
    outs<<toPrint.center.x<<','<<toPrint.center.y<<endl;
    outs<<toPrint.fill.red<<','<<toPrint.fill.green<<','<<toPrint.fill.blue<<endl;
    outs<<toPrint.border.red<<','<<toPrint.border.green<<','<<toPrint.border.blue<<endl;
    outs<<toPrint.message<<endl;
    outs<<toPrint.textColor.red <<','<<toPrint.textColor.green<<','<<toPrint.textColor.blue<<endl;
    outs << toPrint.xOffset<<endl;
    outs<<toPrint.yOffset<<endl;
    return outs;
}