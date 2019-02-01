//
// Created by PC on 4/8/2018.
//

#include "Map.h"


/**********************************MAP************************************/
Map::Map() {
    walls = {};
    name = "";//only way this happens, unless
    doors = {};
    endPoint = Square();//only time this can happen
    player = PlayerPiece();
    monsters = {};
}

Map::Map(std::vector<Wall> wallsIn, std::string nameIn,std::vector<Door> doorsIn, Square endIn,
            PlayerPiece playerIn, std::vector<MonsterPiece>monstersIn) {
    setEndPoint(endIn);
    setName(nameIn);
    setPlayer(playerIn);
    for (Wall w: wallsIn) {
        addWall(w);
    }
    for (Door d: doorsIn) {
        addDoor(d);
    }
    for (MonsterPiece m : monstersIn) {
        addMonster(m);
    }
}

Map::Map(std::string filename) {
    std::ifstream ins(filename);
    if (ins) {
        ins >> *this;
    }
    else {
        walls = {};
        name = "";
        doors = {};
        endPoint = Square();//only time this can happen
        player = PlayerPiece();
        monsters = {};
    }
    ins.close();
}

std::vector<Wall> Map::getWalls() const {
    return walls;
}

Wall Map::getWall(point start) const {
    int i = 0;
    for (Wall w: walls) {
        if (w.getStart().x == start.x &&
                w.getStart().y == start.y) {
            return w;
        }
    }
    return Wall();
}

std::string Map::getName() const {
    return name;
}

std::vector<Door> & Map::getDoors() {
    return doors;
}

Door & Map::getDoor(point start, Orientation orient) {
    for (int i =0;i<doors.size();i++) {
        if (doors[i].getOrientation() == orient && doors[i].getStart().x == start.x &&
                doors[i].getStart().y == start.y) {
            return doors[i];
        }
    }
    Door toReturn;
    return toReturn;
}

Square & Map::getEndPoint() {
    return endPoint;
}

PlayerPiece & Map::getPlayer() {
    return player;
}

std::vector<MonsterPiece> & Map::getMonsters() {
    return monsters;
}

MonsterPiece & Map::getMonster(point start) {
    for (int i =0;i<monsters.size();i++) {
        if (monsters[i].getCenter().x == start.x && monsters[i].getCenter().y == start.y) {
            return monsters[i];
        }
    }
    MonsterPiece toReturn;
    return toReturn;
}

void Map::addWall(Wall toAdd) {
    if (toAdd.getLength() > 0) {
        walls.push_back(toAdd);
    }
}

void Map::addDoor(Door toAdd) {
    doors.push_back(toAdd);
}

void Map::addMonster(MonsterPiece toAdd) {
    if (toAdd.getCenter().x!=0 && toAdd.getCenter().y!=0 && toAdd.getArea() > 0) {
        monsters.push_back(toAdd);
    }
}

void Map::setEndPoint(Square newEnd) {
    if (newEnd.getCenter().x > 0 && newEnd.getCenter().y > 0) {
        endPoint = newEnd;
    }
}

void Map::setName(std::string newName) {
    if (!newName.empty()) {
        name = newName;
    }
}

void Map::setPlayer(PlayerPiece newP) {
    if (newP.getArea() > 0 && newP.getCenter().x >=0 && newP.getCenter().y>=0) {
        player = newP;
        player.setFillColor({0,0,255});//players are blue
        player.setBorderColor({0,0,255});
    }
}

bool Map::checkWallCollisions() const {
    for (Wall w : walls) {
        if (w.checkPlayer(player)) {
            //overlapping
            w.checkPlayer(player);
            return true;

        }
    }
    return false;
}

bool Map::checkDoorCollisions() const {
    for (Door d : doors) {
        if (d.checkPlayer(player)) {
            //overlapping
            return true;
        }
    }
    return false;
}

bool Map::checkCompleted() const {
    return (!(endPoint.getCenter().x+endPoint.getWidth()/2.0 < player.getCenter().x-(player.getWidth()) ||//end square is left of player
              player.getCenter().x+(player.getWidth()/2.0) < endPoint.getCenter().x-(endPoint.getWidth()/2.0) || // player is left of end square
              endPoint.getCenter().y-(endPoint.getHeight()/2.0) > player.getCenter().y+(player.getLength()/2.0) || // end square is below player
              player.getCenter().y-(player.getLength()/2.0) > endPoint.getCenter().y+(endPoint.getHeight()/2.0))); // player is below end square
}

bool Map::checkMonsterCollision() const {
    for (MonsterPiece m : monsters) {
        if (m.checkPlayer(player)) {
            return true;
        }
    }
    return false;
}

bool Map::activateDoors() {
    for (int c=0;c<doors.size();c++)  {
        if (doors[c].checkSwitch(player)) {
            doors[c].open();
            return true;
        }
    }
    return false;
}

void Map::loadFromFile(std::string fileName) {
    ifstream ins(fileName);
    if (ins) {
        ins >> *this;
    }
    ins.close();
}

void Map::saveToFile(std::string fileName) {
    ofstream outs(fileName);//overwrites each time it saves if filename already exists
    if (outs) {
        outs << *this;
    }
    outs.close();
}

void Map::movePlayer(Direction toMove) {
    switch (toMove) {
        case (UP) : {
            player.move(0,-1);
            if (checkWallCollisions() || checkDoorCollisions()) {
                //if collision, move player back
                player.move(0,1);
            }
            break;
        }
        case (RIGHT) : {
            player.move(1,0);
            if (checkWallCollisions() || checkDoorCollisions()) {
                player.move(-1,0);
                checkDoorCollisions();
                checkWallCollisions();
            }
            break;
        }
        case (DOWN): {
            player.move(0,1);
            if (checkWallCollisions() || checkDoorCollisions()) {
                player.move(0,-1);
            }
            break;
        }
        case (LEFT) : {
            player.move(-1,0);
            if (checkWallCollisions() ||checkDoorCollisions()) {
                player.move(1,0);
            }
            break;
        }
    }
}

void Map::moveMonsters() {
    for (int i=0;i<monsters.size();i++) {
        monsters[i].moveOnPath();
    }
}

void Map::draw() const {
    for (int i=0;i<walls.size();i++) {
        walls[i].draw();
    }
    for (int i=0;i<doors.size();i++) {
        doors[i].draw();//drawing door draws switch
    }
    for (int i = 0;i<monsters.size();i++) {
        monsters[i].draw();
    }
    endPoint.draw();
    player.draw();
}

ostream & operator<<(ostream & outs, const Map & toPrint) {
    outs << "NAME" << endl << toPrint.name<<endl;
    for (const Wall & w : toPrint.walls) {
        outs << w;
    }
    for (const Door & d: toPrint.doors) {
        outs << d;
    }
    for (const MonsterPiece & m : toPrint.monsters) {
        outs << m;
    }
    outs << toPrint.player;
    outs <<"END" << endl ;
    outs<< toPrint.endPoint;
    return outs;

}

istream & operator>>(istream & ins, Map & toFill) {
    string objectType;
    while (ins && ins.peek() != EOF) {
        getline(ins, objectType);
        while (!isalnum(objectType[objectType.length()-1])) {
            objectType = objectType.substr(0, objectType.length()-1);
        }
        if (objectType == "DOOR") {
            Door toAdd;
            ins >> toAdd;
            toFill.addDoor(toAdd);
        } else if (objectType == "WALL") {
            Wall toAdd;
            ins >> toAdd;
            toFill.addWall(toAdd);
        }
        else if (objectType=="NAME") {
            string nme;
            std::getline(ins, nme);//only one name
            while (!isalnum(nme[nme.length()-1])) {
                nme = nme.substr(0, nme.length()-1);
            }
            toFill.name = nme;
        }
        else if (objectType =="END") {
            Square newEnd;
            ins >> newEnd;
            toFill.setEndPoint(newEnd);
            //trust input
        }
        else if (objectType=="PLAYERPIECE") {
            PlayerPiece toAdd;
            ins >> toAdd; //only one player
            toFill.setPlayer(toAdd);
        }
        else if (objectType=="MONSTERPIECE") {
            MonsterPiece toAdd;
            ins >> toAdd;
            toFill.addMonster(toAdd);
        }
    }

    return ins;
}
