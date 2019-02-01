//
// Created by PC on 5/1/2018.
//

#include "PauseScreen.h"

PauseScreen::PauseScreen() {
    //creates exit and load buttons


    title = Square({500,100}, {0,191,255}, {0,191,255}, {0,0,0}, "M A Z E R U N N E R",18,1200,-80,5);
    titleShadow = Square({500,115}, {0,191,255}, {0,191,255}, {47,79,79}, "M A Z E R U N N E R",20,1200,-80,5);
    rightWall = Square({1000,350}, {0,191,255}, {0,191,255}, {0,0,0}, "",700,70,-55,5);
    leftWall = Square({0,350}, {0,191,255}, {0,191,255}, {0,0,0}, "",700,70,-55,5);
    bottomWall = Square({500,670}, {0,191,255}, {0,191,255}, {0,0,0}, "",70,1200,-55,5);
    topWall = Square({500,30}, {0,191,255}, {0,191,255}, {0,0,0}, "",120,1200,-55,5);


    loadButton = Square({500,200},{0,191,255},{0,191,255},{1,1,1},"LOAD",70,200,-25,7);
    saveButton = Square({500,300},{0,191,255},{0,191,255},{1,1,1},"SAVE",70,200,-25,7);
    exitButton = Square({500,400},{0,191,255},{0,191,255},{1,1,1},"EXIT",70,200,-25,7);
}

Square & PauseScreen::getLoadButton(){
    return loadButton;
}

Square & PauseScreen::getExitButton(){
    return exitButton;
}

Square & PauseScreen::getSaveButton(){
    return saveButton;
}

void PauseScreen::draw() const {
    topWall.draw();
    loadButton.draw();
    saveButton.draw();
    exitButton.draw();
    titleShadow.draw();
    title.draw();
    rightWall.draw();
    leftWall.draw();
    bottomWall.draw();

}