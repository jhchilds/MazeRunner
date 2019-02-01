//
// Created by Joshua Childs on 5/1/18.
//

#include "StartScreen.h"


StartScreen::StartScreen() {
    monsterPiece = MonsterPiece({100,100},{255,0,0},{255,0,0},70,70);
    monsterPiece.addEndPoint({100,100});
    monsterPiece.addEndPoint({100,600});

    monsterPiece2 = MonsterPiece({900,100},{255,0,0},{255,0,0},70,70);
    monsterPiece2.addEndPoint({900,100});
    monsterPiece2.addEndPoint({900,600});

    monsterPiece3 = MonsterPiece({200,600},{255,0,0},{255,0,0},70,70);
    monsterPiece3.addEndPoint({200,600});
    monsterPiece3.addEndPoint({200,100});


    monsterPiece4 = MonsterPiece({800,600},{255,0,0},{255,0,0},70,70);
    monsterPiece4.addEndPoint({800,100});
    monsterPiece4.addEndPoint({800,600});

    playerPiece = MonsterPiece({380,160},{0,0,255},{0,0,255},20,20);
    playerPiece.addEndPoint({380,160});
    playerPiece.addEndPoint({650,160});
    playerPiece.addEndPoint({650,430});
    playerPiece.addEndPoint({350,430});
    playerPiece.addEndPoint({350,160});
    playerPiece.addEndPoint({380,160});

    monsterPiece5 = MonsterPiece({350,240},{255,0,0},{255,0,0},60,60);
    monsterPiece5.addEndPoint({350,240});
    monsterPiece5.addEndPoint({350,170});
    monsterPiece5.addEndPoint({650,170});
    monsterPiece5.addEndPoint({650,440});
    monsterPiece5.addEndPoint({350,440});
    monsterPiece5.addEndPoint({350,240});

    playButton = Square({500,250}, {0,191,255}, {0,191,255}, {1,1,1}, "PLAY",70,200,-20,5);
    loadButton = Square({500,350}, {0,191,255}, {0,191,255}, {1,1,1}, "LOAD",70,200,-20,5);
    title = Square({500,100}, {0,191,255}, {0,191,255}, {0,0,0}, "M A Z E R U N N E R",18,1200,-80,5);
    titleShadow = Square({500,115}, {0,191,255}, {0,191,255}, {47,79,79}, "M A Z E R U N N E R",20,1200,-80,5);
    rightWall = Square({1000,350}, {0,191,255}, {0,191,255}, {0,0,0}, "",700,70,-55,5);
    leftWall = Square({0,350}, {0,191,255}, {0,191,255}, {0,0,0}, "",700,70,-55,5);
    bottomWall = Square({500,670}, {0,191,255}, {0,191,255}, {0,0,0}, "",70,1200,-55,5);
    topWall = Square({500,30}, {0,191,255}, {0,191,255}, {0,0,0}, "",120,1200,-55,5);

    hardButton=Square({650,550},{0,191,255},{0,191,255},{1,1,1},"HARD",50,100,-23,7);
    mediumButton=Square({500,550},{0,191,255},{0,191,255},{1,1,1},"MEDIUM",50,100,-37,7);
    easyButton=Square({350,550},{0,191,255},{0,191,255},{1,1,1},"EASY",50,100,-23,7);
}

Square & StartScreen::getPlayButton() {
    return playButton;
}

Square & StartScreen::getLoadButton() {
    return loadButton;
}

Square & StartScreen::getHardButton() {
    return hardButton;
}

Square & StartScreen::getMediumButton() {
    return mediumButton;
}

Square & StartScreen::getEasyButton() {
    return easyButton;
}

void StartScreen::moveMonster() {
    monsterPiece.moveOnPath();
    monsterPiece2.moveOnPath();
    monsterPiece3.moveOnPath();
    monsterPiece4.moveOnPath();
    playerPiece.moveOnPath();
    monsterPiece5.moveOnPath();
}

void StartScreen::draw() const {
    playButton.draw();
    loadButton.draw();
    bottomWall.draw();
    rightWall.draw();
    leftWall.draw();
    topWall.draw();
    titleShadow.draw();
    title.draw();
    monsterPiece.draw();
    monsterPiece2.draw();
    monsterPiece3.draw();
    monsterPiece4.draw();
    playerPiece.draw();
    monsterPiece5.draw();
    easyButton.draw();
    mediumButton.draw();
    hardButton.draw();
}