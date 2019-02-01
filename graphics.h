//
// Created by Joshua Childs on 4/19/18.
//

#ifndef GIT_UP_AND_GO_GRAPHICS_H
#define GIT_UP_AND_GO_GRAPHICS_H

#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <string>
#include "Map.h"
#include "StartScreen.h"
#include "PauseScreen.h"
#include "LoseScreen.h"
#include "WinScreen.h"
#include "NextLevelScreen.h"

enum Screen {START,GAME,PLAYER_LOSE,NEXT_LEVEL, PLAYER_WIN,PAUSE};

/**
 * load function
 * requires: a save.map that was made through the save function
 * modifies: curMap, screen
 * effects: loads the map from save.map, and move screen back to game
 */
void load(int & mapIndex, Screen & curScreen);

// Program initialization NOT OpenGL/GLUT dependent,
// as we haven't created a GLUT window yet
void init(void);

// Initialize OpenGL Graphics
void InitGL(void);

// Callback functions for GLUT */

// Draw the window - this is where all the GL actions are
void display(void);

// Trap and process alphanumeric keyboard events
void kbd(unsigned char key, int x, int y);

// Trap and process special keyboard events
void kbdS(int key, int x, int y);

// Handle "mouse cursor moved" events
void cursor(int x, int y);

// Calls itself after a specified time
void timer(int extra);

void unstunMonsters(int extra);

// Handle mouse button pressed and released events
void mouse(int button, int state, int x, int y);

#endif //GIT_UP_AND_GO_GRAPHICS_H
