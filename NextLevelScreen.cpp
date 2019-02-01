//
// Created by Joshua Childs on 5/3/18.
//

#include "NextLevelScreen.h"
NextLevelScreen::NextLevelScreen(){
    monsterPiece = MonsterPiece({80,100},{0,0,255},{0,0,255},20,20);
    monsterPiece.addEndPoint({80,100});
    monsterPiece.addEndPoint({80,600});

    monsterPiece2 = MonsterPiece({920,100},{0,0,255},{0,0,255},20,20);
    monsterPiece2.addEndPoint({920,100});
    monsterPiece2.addEndPoint({920,600});

    monsterPiece3 = MonsterPiece({180,600},{0,0,255},{0,0,255},20,20);
    monsterPiece3.addEndPoint({180,600});
    monsterPiece3.addEndPoint({180,100});


    monsterPiece4 = MonsterPiece({820,600},{0,0,255},{0,0,255},20,20);
    monsterPiece4.addEndPoint({820,100});
    monsterPiece4.addEndPoint({820,600});

    message = Square({500, 350}, {138/255.0,43/255.0,226/255.0}, {138/255.0,43/255.0,226/255.0}, {0, 0, 0},
                     "C O N G R A T U L A T I O N S, YOU'VE WON LEVEL 1! "
                             "CLICK ANYWHERE TO CONTINUE", 100, 1200, -380, 5);
    title = Square({500, 100}, {138/255.0,43/255.0,226/255.0}, {138/255.0,43/255.0,226/255.0}, {1, 1, 1}, "L E V E L   U P ", 18, 1200, -50, 5);
    titleShadow = Square({500, 115}, {138/255.0,43/255.0,226/255.0}, {138/255.0,43/255.0,226/255.0}, {0, 0, 0}, "L E V E L   U P", 20, 1200, -50,5);
    rightWall = Square({1000, 350}, {138/255.0,43/255.0,226/255.0},{138/255.0,43/255.0,226/255.0}, {0, 0, 0}, "", 700, 70, -55, 5);
    leftWall = Square({0, 350}, {138/255.0,43/255.0,226/255.0}, {138/255.0,43/255.0,226/255.0}, {0, 0, 0}, "", 700, 70, -55, 5);
    bottomWall = Square({500, 670},{138/255.0,43/255.0,226/255.0}, {138/255.0,43/255.0,226/255.0}, {0, 0, 0}, "", 70, 1200, -55, 5);
    topWall = Square({500, 30}, {138/255.0,43/255.0,226/255.0}, {138/255.0,43/255.0,226/255.0}, {0, 0, 0}, "", 120, 1200, -55, 5);
}

NextLevelScreen::NextLevelScreen(int mapIndex) {

    monsterPiece = MonsterPiece({80,100},{0,0,255},{0,0,255},20,20);
    monsterPiece.addEndPoint({80,100});
    monsterPiece.addEndPoint({80,600});

    monsterPiece2 = MonsterPiece({920,100},{0,0,255},{0,0,255},20,20);
    monsterPiece2.addEndPoint({920,100});
    monsterPiece2.addEndPoint({920,600});

    monsterPiece3 = MonsterPiece({180,600},{0,0,255},{0,0,255},20,20);
    monsterPiece3.addEndPoint({180,600});
    monsterPiece3.addEndPoint({180,100});


    monsterPiece4 = MonsterPiece({820,600},{0,0,255},{0,0,255},20,20);
    monsterPiece4.addEndPoint({820,100});
    monsterPiece4.addEndPoint({820,600});

    message = Square({500, 350}, {138/255.0,43/255.0,226/255.0}, {138/255.0,43/255.0,226/255.0}, {0, 0, 0},
                     "C O N G R A T U L A T I O N S, YOU'VE WON LEVEL " + to_string(mapIndex + 1) + "! "
                     "CLICK ANYWHERE TO CONTINUE", 100, 1200, -380, 5);
    title = Square({500, 100}, {138/255.0,43/255.0,226/255.0}, {138/255.0,43/255.0,226/255.0}, {1, 1, 1}, "L E V E L   U P ", 18, 1200, -50, 5);
    titleShadow = Square({500, 115}, {138/255.0,43/255.0,226/255.0}, {138/255.0,43/255.0,226/255.0}, {0, 0, 0}, "L E V E L   U P", 20, 1200, -50,5);
    rightWall = Square({1000, 350}, {138/255.0,43/255.0,226/255.0},{138/255.0,43/255.0,226/255.0}, {0, 0, 0}, "", 700, 70, -55, 5);
    leftWall = Square({0, 350}, {138/255.0,43/255.0,226/255.0}, {138/255.0,43/255.0,226/255.0}, {0, 0, 0}, "", 700, 70, -55, 5);
    bottomWall = Square({500, 670},{138/255.0,43/255.0,226/255.0}, {138/255.0,43/255.0,226/255.0}, {0, 0, 0}, "", 70, 1200, -55, 5);
    topWall = Square({500, 30}, {138/255.0,43/255.0,226/255.0}, {138/255.0,43/255.0,226/255.0}, {0, 0, 0}, "", 120, 1200, -55, 5);



};

void NextLevelScreen::moveMonster() {
    monsterPiece.moveOnPath();
    monsterPiece2.moveOnPath();
    monsterPiece3.moveOnPath();
    monsterPiece4.moveOnPath();

}
void NextLevelScreen::draw() const {
    message.draw();
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

}
