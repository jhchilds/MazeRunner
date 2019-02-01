//
// Created by PC on 5/1/2018.
//

#ifndef GIT_UP_AND_GO_PAUSESCREEN_H
#define GIT_UP_AND_GO_PAUSESCREEN_H

#include"Square.h"

class PauseScreen {
private:
    //pause can load or exit
    Square topWall;
    Square bottomWall;
    Square rightWall;
    Square leftWall;
    Square title;
    Square titleShadow;

    Square loadButton;
    Square exitButton;
    Square saveButton;

public:
    //constructor - only default
    PauseScreen();

    //getters
    Square & getLoadButton();
    Square & getExitButton();
    Square & getSaveButton();

    void draw() const;
};

#endif //GIT_UP_AND_GO_PAUSESCREEN_H
