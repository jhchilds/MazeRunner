//
// Created by Joshua Childs on 5/3/18.
//

#ifndef GIT_UP_AND_GO_NEXTLEVELSCREEN_H
#define GIT_UP_AND_GO_NEXTLEVELSCREEN_H

#include "Wall.h"
#include "Door.h"
#include <string>
#include <fstream>
#include "MonsterPiece.h"
#include"Square.h"

class NextLevelScreen {

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
    int level;

public:
    NextLevelScreen();

    NextLevelScreen(int mapIndex);

    void moveMonster();

    void draw() const;



};


#endif //GIT_UP_AND_GO_NEXTLEVELSCREEN_H
