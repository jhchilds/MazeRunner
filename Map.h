//
// Created by PC on 4/8/2018.
//

#ifndef GIT_UP_AND_GO_MAP_H
#define GIT_UP_AND_GO_MAP_H


#include "Wall.h"
#include "MonsterPiece.h"
#include "PlayerPiece.h"
#include "Square.h"
#include "Door.h"
#include <fstream>

enum Direction {UP,DOWN,LEFT,RIGHT};


class Map {
public:
    //constructors
    Map();

    Map(std::vector<Wall> wallsIn, std::string nameIn,std::vector<Door> doorsIn, Square endIn,
        PlayerPiece playerIn, std::vector<MonsterPiece>monstersIn);

    /**
     * file in format:
     * Name
     * [NAME]
     * Doors
     * [DOOR INFO]
     * [DOOR INFO]
     * ...
     * Wall
     * [LINE INFO]
     * [LINE INFO]
     * [LINE INFO]
     * ...
     * Start
     * [START POINT]
     * End
     * [END POINT]
     * Switches
     * [SWITCH INFO]
     * [SWITCH INFO]
     * ...
     */
    explicit Map(std::string filename);

    //getters
    //all return references - want game to be able to change these guys
    std::vector<Wall> getWalls() const;//once made, walls are permanent
    Wall getWall(point start) const;
    std::string getName() const;
    std::vector<Door> & getDoors();
    //returns first door with given start point and orientation
    Door & getDoor(point start, Orientation orient);
    Square &getEndPoint();
    PlayerPiece & getPlayer();
    std::vector<MonsterPiece> & getMonsters();
    MonsterPiece & getMonster(point start);

    //setters
    void addWall(Wall toAdd);
    void addDoor(Door toAdd);
    void addMonster(MonsterPiece toAdd);
    void setEndPoint(Square newEnd);
    void setName(std::string newName);
    void setPlayer(PlayerPiece newP);

    //functions
    bool checkWallCollisions() const;
    bool checkDoorCollisions() const;
    bool checkCompleted() const;
    bool checkMonsterCollision() const;//calls is overlapping on each monster
    bool activateDoors();
    void loadFromFile(std::string fileName);
    void saveToFile(std::string filename);
    void movePlayer(Direction toMove);
    void moveMonsters();
    void draw() const;

    /**
     * file in format:
     * Name
     * [NAME]
     * DOOR
     * [DOOR INFO]
     * [SWITCH INFO]
     * DOOR
     * [DOOR INFO]
     * [SWITCH INFO]
     * ...
     * WALL
     * [WALL INFO]
     * WALL
     * [WALL INFO]
     * WALL
     * [WALL INFO]
     * ...
     * END
     * [END POINT]
     * PLAYER
     * [PLAYER INFO]
     * MONSTER
     * [MONSTER INFO]
     * MONSTER
     * [MONSTER INFO]
     * MONSTER
     * [MONSTER INFO]
     * ...
     */
    friend ostream & operator<<(ostream & outs, const Map & toPrint);
    friend istream & operator>>(istream & ins, Map & toPrint);

private:
    std::vector<Wall> walls;
    std::string name;
    std::vector<Door> doors;//each door has a switch
    Square endPoint;
    PlayerPiece player;
    std::vector<MonsterPiece> monsters;
};

#endif //GIT_UP_AND_GO_MAP_H
