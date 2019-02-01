//
// Created by Joshua Childs on 5/2/18.
//

#ifndef GIT_UP_AND_GO_LOSESCREEN_H
#define GIT_UP_AND_GO_LOSESCREEN_H

#include "Wall.h"
#include "Door.h"
#include <string>
#include <fstream>
#include "MonsterPiece.h"
#include"Square.h"

class LoseScreen {
private:
    MonsterPiece monsterPiece;
    MonsterPiece monsterPiece2;
    MonsterPiece monsterPiece3;
    MonsterPiece monsterPiece4;
    Square message;
    Square topWall;
    Square bottomWall;
    Square rightWall;
    Square leftWall;
    Square title;
    Square titleShadow;
public:
    LoseScreen();

    void moveMonster();

    void draw() const;
};


#endif //GIT_UP_AND_GO_LOSESCREEN_H
