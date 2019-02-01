//
// Created by Joshua Childs on 4/17/18.
//

#include "MonsterPiece.h"
#include "graphics.h"

void MonsterPiece::calculateArea() {
    area = length * width;
}

void MonsterPiece::calculatePerimeter() {
    perimeter = 2.0 * length + 2.0 * width;
}

MonsterPiece::MonsterPiece() : Piece(), length(0), width(0),endPoints({}),path(0) { }

MonsterPiece::MonsterPiece(int l, int w) : Piece(),endPoints({}),path(0) {
    setDimensions(l,w);
};

MonsterPiece::MonsterPiece(point start, color border, color fill,int l, int w): Piece(start,border,fill),
                                                                                      endPoints({}), path(0) {
    setDimensions(l,w);
}

int MonsterPiece::getLength() const {
    return length;
}

int MonsterPiece::getWidth() const {
    return width;
}

vector<point> MonsterPiece::getEndPoints() const {
    return endPoints;
}

int MonsterPiece::getPath() const {
    return path;
}

void MonsterPiece::setDimensions(int l, int w) {
    // validation for negative values
    length = (l < 0) ? 0 : l;
    width = (w < 0) ? 0 : w;
    // update area and perimeter
    calculateArea();
    calculatePerimeter();
}

void MonsterPiece::setEndPoints(std::vector<point> ends) {
    endPoints = ends;
}

void MonsterPiece::setPath(int newPath) {
    path = newPath > 0 ? newPath : 0;
}

void MonsterPiece::addEndPoint(point toAdd) {
    if (!(toAdd.x < 0 || toAdd.y < 0)) {
        endPoints.push_back(toAdd);
    }
}

bool MonsterPiece::checkPlayer(PlayerPiece player) const {
    return !(center.x+width/2.0 < player.getCenter().x-(player.getWidth() - 5) ||//monster is left of player
             player.getCenter().x+(player.getWidth()/2.0) + 5 < center.x-(width/2.0) || // player is left of monster
             center.y-(length/2.0) > player.getCenter().y+(player.getLength()/2.0) + 5 || // monster is below player
             player.getCenter().y-(player.getLength()/2.0) - 5 > center.y+(length/2.0)); // player is below monster
}

void MonsterPiece::moveOnPath() {
    if (endPoints.empty()) {
        return;//does nothing if no paths
    }
    if (center.x != endPoints[path].x || center.y != endPoints[path].y) {
        //piece not on next endpoint, so move
        int dx = 0,dy = 0;

        //the ratio of the hypotenuse of larger triangle to smaller triangle is the same as the ratio of the difference
        //between the sides of the larger triangle to the sides of the smaller triangle
        //moves as close to 1 point towards the end point as possible
        int numerator = endPoints[path].y-center.y;

        double denominator = sqrt((endPoints[path].x-center.x)*(endPoints[path].x-center.x)+(endPoints[path].y-center.y)*(endPoints[path].y-center.y));
        dy = numerator/denominator;

        numerator = endPoints[path].x-center.x;

        dx = numerator/denominator;

        if (center.x == endPoints[path].x) {
            if (center.y > endPoints[path].y) {
                //want to move up (neg y)
                dy = -1;
            }
            else {
                dy = 1;
            }
        }

        if (center.y == endPoints[path].y) {
            if (center.x > endPoints[path].x) {
                //move left
                dx = -1;
            }
            else {
                dx = 1;
            }
        }

        if (dx > 2) {
            dx = 1;
        }
        else if (dx < -2) {
            dx = -1;
        }
        if (dy > 2) {
            dy = 1;
        }
        else if (dy < -2) {
            dy = -1;
        }

        move(dx,dy);

    }
    else {
        //we're at the end. advance path, and move along that
        //loops back to first path at end
        if (path >= endPoints.size()-1) {
            path = 0;
            moveOnPath();
        }
        else {
            path++;
        }
        moveOnPath();
    }
}

/**
 * FORMAT
 * MONSTERPIECE
 * LENGTH
 * WIDTH
 * CENTER X,Y
 * FILL R,G,B
 * BORDER R,G,B
 */
ostream& operator<< (ostream& outs,
                      const MonsterPiece &m) {
    outs << "MONSTERPIECE" << endl;
    for (int i = 0; i < m.endPoints.size();i++) {
        outs << m.endPoints[i].x << "," << m.endPoints[i].y << endl;
    }
    outs << "E" << endl;
    outs << m.getLength() << endl;
    outs << m.getWidth() << endl;
    outs << m.getCenter().x << "," << m.getCenter().y << endl;
    outs << m.getFillColor().red << "," << m.getFillColor().green << "," << m.getFillColor().blue << endl;
    outs << m.getBorderColor().red << "," << m.getBorderColor().green << "," << m.getBorderColor().blue << endl;
    outs << m.getPath() << endl;

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
istream& operator>> (istream& ins,
                      MonsterPiece &m) {

    string type, length, width, startX, startY, fillRed, fillGreen, fillBlue, borderRed, borderGreen, borderBlue,e;

    if (ins) {
        //type is going to be burned by whatever it is that is creating the monster (game? map?)
        string end = "";
        string junk;
        while(ins.peek()!='E') {
            //E marks end of endpoints -- read endpoints till then
            string endx, endy;
            getline(ins,endx,',');
            getline(ins,endy);
            //trust the data
            point toAdd(stoi(endx),stoi(endy));
            m.addEndPoint(toAdd);
        }

        //BURN THE E
        getline(ins,e);
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

        m.setDimensions(stoi(length), stoi(width));
        m.setCenter(stoi(startX), stoi(startY));
        m.setFillColor(stoi(fillRed), stoi(fillGreen), stoi(fillBlue));
        m.setBorderColor(stoi(borderRed), stoi(borderGreen), stoi(borderBlue));

        string pth;
        getline(ins, pth);
        if (isInt(pth)) {
            m.setPath(stoi(pth));
        }

        return ins;
    }
}

void MonsterPiece::draw() const {
   // red Border and Fill
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
}

MonsterPiece & MonsterPiece::operator=(const MonsterPiece & toCopy) {

    this->center = toCopy.center;
    this->border = toCopy.border;
    this->fill = toCopy.fill;
    this->length = toCopy.length;
    this->width = toCopy.width;
    this->endPoints.clear();
    for (point point : toCopy.getEndPoints()) {
        this->addEndPoint(point);
    }
    this->path = toCopy.path;
    return *this;
}