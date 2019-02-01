//
// Created by Joshua Childs on 4/19/18.
//

/**
 * todo: monster piece istream overloaded operators
 * todo: player piece istream overloaded operators
 * todo: test player and monster piece input and output
 * todo: test wall input and output
 */

#include "graphics.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
using namespace std;


//todo: pizazz up the menus - title
//todo: load only if save file exists
//todo: fix door overlap
//todo: fix monsteroverlap


GLdouble width, height;
int wd;
std::vector<std::string> filenames;
Screen screen;
Map curMap;
StartScreen startScreen;
PauseScreen pauseScreen;
LoseScreen loseScreen;
WinScreen winScreen;
int mapIndex;
NextLevelScreen nextLevelScreen;
bool monstersStunned;
int numStunsLeft;
bool movePlayerUp, movePlayerDown, movePlayerLeft, movePlayerRight;
int playerSpeed;
int monsterSpeed;



void init() {
    width = 1000;
    height = 700;
    filenames = {"level1.map","level2.map","level3.map"};//todo:add additional maps
    mapIndex = 0;
    playerSpeed = 3;
    monsterSpeed = 10;
    screen = START;
    curMap = Map(filenames[mapIndex]);
    startScreen = StartScreen();
    pauseScreen = PauseScreen();

    monstersStunned = false;
    numStunsLeft = 3;
    movePlayerDown = false;
    movePlayerRight = false;
    movePlayerUp = false;
    movePlayerLeft = false;
}

/**
 * save load format:
 * MAP_INDEX\n
 * MAP
 */
void load(int & mapIndex,Screen & curScreen) {
    string tempIndex, junk;

    //loads from save.map
    ifstream ins("save.map");

    if (ins) {
        getline(ins, tempIndex);
        if (isInt(tempIndex)) {
            mapIndex = stoi(tempIndex);
        } else {
            mapIndex = 0;//assumes its the first map, if invalid input or none specified
        }

        Map newMap;
        ins >> newMap;//something happens after here and before the first display function that sets switch width = 100
        curMap = newMap;

        //sets curScreen to game (should change in the game itself, since pass by reference)
        curScreen = GAME;
    }
}

void save(int mapIndex) {
    //loads from save.map
    ofstream outs("save.map");
    //put the index
    outs << mapIndex << endl;
    outs << curMap;

}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    /*
     * All drawing goes here
     */
    switch (screen) {
        case (START) : {
            startScreen.draw();
            break;
        }
        case (GAME) : {
            curMap.draw();
            string message = "Number of Stuns Left: " + to_string(numStunsLeft);
            glColor3f(1,1,1);
            glRasterPos2i(50,20);
            for (char c:message) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c);
            }
            glEnd();
            break;
        }
        case (PAUSE): {
            pauseScreen.draw();
            break;
        }
        case (PLAYER_LOSE) : {
            loseScreen.draw();
            break;
        }
        case (PLAYER_WIN) : {
            winScreen.draw();
            break;
        }
        case (NEXT_LEVEL) : {

            //draw message
            nextLevelScreen.draw();
            break;
        }
    }

    glFlush();//Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    // escape
    if (key == 27) {
        if (screen == GAME) {
            screen = PAUSE;
        }
        else if (screen ==PAUSE) {
            screen = GAME;
        }
        else if (screen == START) {
            glutDestroyWindow(wd);
            exit(0);
        }
    }
    if(screen == GAME) {
        if (key == 119) {
            //move up
            movePlayerUp = true;

        } else if (key == 115) {
            //move down
            movePlayerDown = true;
        } else if (key == 97) {
            //move left
            movePlayerLeft = true;

        } else if (key == 100) {
            //move right
            movePlayerRight = true;
        }
    }

    glutPostRedisplay();

    return;
}

void kbdUp(unsigned char key, int x, int y) {
    switch(key) {
        case 115:
            movePlayerDown = false;
            break;
        case 97:
            movePlayerLeft = false;
            break;
        case 100:
            movePlayerRight = false;
            break;
        case 119:
            movePlayerUp=false;
            break;
    }
    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    if (screen == GAME) {
        switch (key) {
            case GLUT_KEY_DOWN:
                movePlayerDown = true;
                break;
            case GLUT_KEY_LEFT:
                movePlayerLeft = true;
                break;
            case GLUT_KEY_RIGHT:
                movePlayerRight = true;
                break;
            case GLUT_KEY_UP:
                movePlayerUp = true;
                break;
        }
    }

    glutPostRedisplay();

    return;
}

void kbdSUp(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            movePlayerDown = false;
            break;
        case GLUT_KEY_LEFT:
            movePlayerLeft = false;
            break;
        case GLUT_KEY_RIGHT:
            movePlayerRight = false;
            break;
        case GLUT_KEY_UP:
            movePlayerUp=false;
            break;
    }
    glutPostRedisplay();
    return;
}

void cursor(int x, int y) {
    if (screen != GAME) {

    }
    if (screen==START){
        if(startScreen.getPlayButton().overlappingPoint({x,y})) {
            startScreen.getPlayButton().setFillColor({255, 0, 0});
         }
        else if(!startScreen.getPlayButton().overlappingPoint({x,y})){
            startScreen.getPlayButton().setFillColor({0,191,255});
         }
        if(startScreen.getLoadButton().overlappingPoint({x,y})) {
            startScreen.getLoadButton().setFillColor({255, 0, 0});
        }
        else if(!startScreen.getLoadButton().overlappingPoint({x,y})){
            startScreen.getLoadButton().setFillColor({0,191,255});
        }


        if(startScreen.getEasyButton().overlappingPoint({x,y})) {
            startScreen.getEasyButton().setFillColor({255, 0, 0});
        }
        else if(!startScreen.getEasyButton().overlappingPoint({x,y})){
            startScreen.getEasyButton().setFillColor({0,191,255});
        }
        if(startScreen.getMediumButton().overlappingPoint({x,y})) {
            startScreen.getMediumButton().setFillColor({255, 0, 0});
        }
        else if(!startScreen.getMediumButton().overlappingPoint({x,y})){
            startScreen.getMediumButton().setFillColor({0,191,255});
        }

        if(startScreen.getHardButton().overlappingPoint({x,y})) {
            startScreen.getHardButton().setFillColor({255, 0, 0});
        }
        else if(!startScreen.getHardButton().overlappingPoint({x,y})){
            startScreen.getHardButton().setFillColor({0,191,255});
        }
    }

    if (screen==PAUSE){
        if(pauseScreen.getLoadButton().overlappingPoint({x,y})) {
            pauseScreen.getLoadButton().setFillColor({255, 0, 0});
        }
        else if(!pauseScreen.getLoadButton().overlappingPoint({x,y})){
            pauseScreen.getLoadButton().setFillColor({0,191,255});
        }
        if(pauseScreen.getExitButton().overlappingPoint({x,y})) {
            pauseScreen.getExitButton().setFillColor({255, 0, 0});
        }
        else if(!pauseScreen.getExitButton().overlappingPoint({x,y})){
            pauseScreen.getExitButton().setFillColor({0,191,255});
        }
        if(pauseScreen.getSaveButton().overlappingPoint({x,y})) {
            pauseScreen.getSaveButton().setFillColor({255, 0, 0});
        }
        else if(!pauseScreen.getSaveButton().overlappingPoint({x,y})){
            pauseScreen.getSaveButton().setFillColor({0,191,255});
        }
    }
    //Don't think we need this, BUT I DONT KNOW WHY IT WORKS SO WELL....
//    if (screen!=GAME) {
//        glutPostRedisplay();
//    }
//    else if (startScreen.getPlayButton().overlappingPoint({x,y})){
//        glutPostRedisplay();
//    }
//    else if (startScreen.getLoadButton().overlappingPoint({x,y})){
//        glutPostRedisplay();
//    }



}

//button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
//state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && screen == START) {
        if (startScreen.getPlayButton().overlappingPoint({x,y})) {
            //user is hitting play. Start a new game from map 1
            mapIndex = 0;
            screen=GAME;
        }
        else if (startScreen.getLoadButton().overlappingPoint({x,y})) {
            load(mapIndex,screen);
        }
        else if (startScreen.getEasyButton().overlappingPoint({x,y})) {
            //sets player speed to 5, and monster speed to 15
            playerSpeed=8;
            monsterSpeed=20;
        }
        else if (startScreen.getMediumButton().overlappingPoint({x,y})) {
            //sets player speed to 5, and monster speed to 15
            playerSpeed=3;
            monsterSpeed=10;
        }
        else if (startScreen.getHardButton().overlappingPoint({x,y})) {
            //sets player speed to 5, and monster speed to 15
            playerSpeed=0;
            monsterSpeed=2;
        }
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && screen == PAUSE) {
        if (pauseScreen.getExitButton().overlappingPoint({x,y}) ) {
            glutDestroyWindow(wd);
            exit(0);
        }
        else if (pauseScreen.getLoadButton().overlappingPoint({x,y})) {
            //load logic
            load(mapIndex,screen);
            screen=GAME;
        }
        else if (pauseScreen.getSaveButton().overlappingPoint({x,y,})) {
            save(mapIndex);
            screen=GAME;
        }
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && screen == GAME) {
        if (!monstersStunned && numStunsLeft > 0) {
            //stun!
            monstersStunned = true;
            numStunsLeft -= 1;
            //start unstun monsters timer
            glutTimerFunc(1000,unstunMonsters,0);
        }
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && screen == NEXT_LEVEL) {
        mapIndex++;
        curMap = Map(filenames[mapIndex]);
        screen = GAME;
        numStunsLeft = 3;
    }

    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (screen == PLAYER_LOSE || screen == PLAYER_WIN)) {
        //return to start screen, and reset map
        screen = START;
        mapIndex = 0;
        curMap = Map(filenames[mapIndex]);
        numStunsLeft = 3;
    }

    glutPostRedisplay();
}

//checks monster collision
void timer(int extra) {

    if (curMap.checkMonsterCollision()) {
        screen = PLAYER_LOSE;
    }

    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

void moveMonsterTimer(int extra) {
    if (screen == GAME && !monstersStunned) {
        //only move monsters if on game screen
        curMap.moveMonsters();
    }

    if (screen == START){
        startScreen.moveMonster();
    }

    if (screen == PLAYER_LOSE){
        loseScreen.moveMonster();
    }
    if (screen == PLAYER_WIN){
        winScreen.moveMonster();
    }
    if (screen == NEXT_LEVEL){
        nextLevelScreen.moveMonster();
    }

    glutTimerFunc(monsterSpeed,moveMonsterTimer,0);
}

void checkDoorsTimer(int extra) {
    if (screen == GAME) {
        curMap.activateDoors();//todo:decide whether to display a message when a door activates
    }
    glutTimerFunc(0,checkDoorsTimer,0);
}

void checkWinTimer(int extra) {
    if (screen==GAME) {
        if (curMap.checkCompleted()) {
            if (mapIndex == filenames.size()-1) {//beat last level
                screen = PLAYER_WIN;
            }
            else {//next level screen
                nextLevelScreen = NextLevelScreen(mapIndex);
                screen = NEXT_LEVEL;
            }
        }
    }

    glutTimerFunc(0,checkWinTimer,0);
}

void unstunMonsters(int extra) {
    if (extra == 1 && monstersStunned) {
        monstersStunned = false;//if this is the second time through the loop (the only time extra will be 1), unfreeze monsters
    }
    if (monstersStunned) {
        //if monsters still stunned, call the timer again
        glutTimerFunc(1000,unstunMonsters,1);
    }
}

void movePlayerTimer(int extra) {
    if (movePlayerUp) {
        curMap.movePlayer(UP);
    }
    if (movePlayerRight) {
        curMap.movePlayer(RIGHT);
    }
    if (movePlayerDown) {
        curMap.movePlayer(DOWN);
    }
    if (movePlayerLeft) {
        curMap.movePlayer(LEFT);
    }
    glutTimerFunc(playerSpeed,movePlayerTimer,0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Git-Up-And-Go" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);
    glutKeyboardUpFunc(kbdUp);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    glutSpecialUpFunc(kbdSUp);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);//monster collision check
    glutTimerFunc(monsterSpeed,moveMonsterTimer,0);
    glutTimerFunc(0,checkDoorsTimer,0);
    glutTimerFunc(0,checkWinTimer,0);
    glutTimerFunc(playerSpeed,movePlayerTimer,0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}

#pragma clang diagnostic pop