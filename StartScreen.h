//
// Created by Joshua Childs on 5/1/18.
//

#ifndef GIT_UP_AND_GO_STARTSCREEN_H
#define GIT_UP_AND_GO_STARTSCREEN_H

#include "Wall.h"
#include "Door.h"
#include <string>
#include <fstream>
#include "MonsterPiece.h"
#include"Square.h"


class StartScreen {
private:
    MonsterPiece monsterPiece;
    MonsterPiece monsterPiece2;
    MonsterPiece monsterPiece3;
    MonsterPiece monsterPiece4;
    MonsterPiece playerPiece;
    MonsterPiece monsterPiece5; //Chasing player piece around menu
    Square topWall;
    Square bottomWall;
    Square rightWall;
    Square leftWall;
    Square title;
    Square titleShadow;
    Square playButton;
    Square loadButton;
    Square hardButton;
    Square mediumButton;
    Square easyButton;

public:
    StartScreen();

    Square & getTitle();
    Square & getPlayButton();
    Square & getLoadButton();
    Square & getHardButton();
    Square& getMediumButton();
    Square& getEasyButton();

    void moveMonster();

    void draw() const;

};




#endif //GIT_UP_AND_GO_STARTSCREEN_H
