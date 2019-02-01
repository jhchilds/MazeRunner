//
// Created by Luke Faulkner on 4/19/18.
//

#include "PlayerPiece.h"
#include "MonsterPiece.h"
#include "Line.h"
#include "Switch.h"
#include "Door.h"
#include "Wall.h"
#include "Map.h"
#include <iostream>
using namespace std;


void overloadedOperatorsTest();
void testWallOverlap();
void testDoor();
void testMonsterOverlap();
void testMonsterMoveOnPath();
void testMap();
void testMapIO();
//int main(){
//    /******************************************************************************************/
//    /*****Testing the Player Piece class*****/
//    //Testing for player piece also tests piece parent class
//    /**Default Constructor**/
//    cout<<"\n******************************************************************************************"<<endl;
//    cout<<"-Testing player piece class"<<endl;
//    cout<<"\n-Testing the default player piece constructor"<<endl;
//    PlayerPiece player1;
//    cout<<"Default length: "<<player1.getLength()<<endl;
//    cout<<"Default width: "<<player1.getWidth()<<endl;
//    //Getting default piece values
//    point center1=player1.getCenter();
//    cout<<"Default Center point: ("<<center1.x<<","<<center1.y<<")"<<endl;
//    color bColor1=player1.getBorderColor();
//    cout<<"Default Border color: (red "<<bColor1.red<<", green "<<bColor1.green<<", blue "<<bColor1.blue<<")"<<endl;
//    color fColor1=player1.getFillColor();
//    cout<<"Default fill color: (red "<<fColor1.red<<", green "<<fColor1.green<<", blue "<<fColor1.blue<<")"<<endl;
//    cout<<"Default Area: "<<player1.getArea()<<endl;
//    cout<<"Default Perimeter: "<<player1.getPerimeter()<<endl;
//
//    cout<<"\n-Resetting values for default player piece"<<endl;
//    //Setting values for player1 object
//    player1.setDimensions(20,20);
//    point center2;
//    center2.x=50;
//    center2.y=50;
//    player1.setCenter(center2);
//    color bColor2;
//    bColor2.red=50;
//    bColor2.green=25;
//    bColor2.blue=50;
//    player1.setBorderColor(bColor2);
//    color fColor2;
//    fColor2.red=50;
//    fColor2.green=25;
//    fColor2.blue=50;
//    player1.setFillColor(fColor2);
//
//    //Getting Reset Values for player1
//    cout<<"The length has been set to 20, the width 20, the center (50,50), the boarder color (50,25,50)"
//        <<" and the fill color (50,25,50)"<<endl;
//    cout<<"Reset Piece length: "<<player1.getLength()<<endl;
//    cout<<"Reset Piece width: "<<player1.getWidth()<<endl;
//    point center3=player1.getCenter();
//    cout<<"Reset Center point: ("<<center3.x<<","<<center3.y<<")"<<endl;
//    color bColor3=player1.getBorderColor();
//    cout<<"Reset Border color: (red "<<bColor3.red<<", green "<<bColor3.green<<", blue "<<bColor3.blue<<")"<<endl;
//    color fColor3=player1.getFillColor();
//    cout<<"Reset Fill color: (red "<<fColor3.red<<", green "<<fColor3.green<<", blue "<<fColor3.blue<<")"<<endl;
//    cout<<"Recalculated Area: "<<player1.getArea()<<endl;
//    cout<<"Recalculated Perimeter: "<<player1.getPerimeter()<<endl;
//
//    //Testing move and secondary set functions
//    cout<<"\n-Testing the move and secondary set functions"<<endl;
//    point center4=player1.getCenter();
//    cout<<"Before the move the player was at: ("<<center4.x<<","<<center4.y<<")"<<endl;
//    player1.move(10,10);
//    center4=player1.getCenter();
//    cout<<"After the move the player is at: ("<<center4.x<<","<<center4.y<<")"<<endl;
//    player1.setCenter(100,100);
//    center4=player1.getCenter();
//    cout<<"After the secondary center set the player is now at: ("<<center4.x<<","<<center4.y<<")"<<endl;
//    player1.setBorderColor(100,50,125);
//    color bColor4=player1.getBorderColor();
//    cout<<"The border color is now: (red "<<bColor4.red<<", green "<<bColor4.green<<", blue "<<bColor4.blue<<")"<<endl;
//    player1.setFillColor(100,50,125);
//    color fColor4=player1.getFillColor();
//    cout<<"The fill color is now: (red "<<fColor4.red<<", green "<<fColor4.green<<", blue "<<fColor4.blue<<")"<<endl;
//
//    /**Non-Default Constructor**/
//    cout<<"\n-Non-default player piece constructor test"<<endl;
//    PlayerPiece player2(50,50);
//    cout<<"Non-default passed in length value: "<<player2.getLength()<<endl;
//    cout<<"Non-default passed in width value: "<<player2.getWidth()<<endl;
//    cout<<"Non-default Area: "<<player2.getArea()<<endl;
//    cout<<"Non-default Perimeter: "<<player2.getPerimeter()<<endl;
//
//    /******************************************************************************************/
//    /*****Testing the Monster Piece class*****/
//    /**Default Constructor**/
//    cout<<"\n******************************************************************************************"<<endl;
//    cout<<"Testing monster piece class"<<endl;
//    cout<<"\n-Testing monster Default constructor"<<endl;
//    MonsterPiece monster1;
//    cout<<"Default length: "<<monster1.getLength()<<endl;
//    cout<<"Default width: "<<monster1.getWidth()<<endl;
//
//    //Setting dimension for monster1
//    cout<<"\n-Resetting dimensions for default monster piece"<<endl;
//    monster1.setDimensions(60,50);
//    cout<<"Reset dimensions are (60,50)"<<endl;
//    cout<<"Reset Length: "<<monster1.getLength()<<endl;
//    cout<<"Reset Width: "<<monster1.getWidth()<<endl;
//    cout<<"Reset Area: "<<monster1.getArea()<<endl;
//    cout<<"Reset Perimeter: "<<monster1.getPerimeter()<<endl;
//
//    /**Non-Default Constructor**/
//    cout<<"\n-Monster piece non-default constructor test"<<endl;
//    MonsterPiece monster2(100,100);
//    cout<<"The passed in dimensions values are (100,100)"<<endl;
//    cout<<"Non-default passed in length value: "<<monster2.getLength()<<endl;
//    cout<<"Non-default passed in width value: "<<monster2.getWidth()<<endl;
//    cout<<"Non-default Area: "<<monster2.getArea()<<endl;
//    cout<<"Non-default Perimeter: "<<monster2.getPerimeter()<<endl;
//
//
//    /******************************************************************************************/
//    /*****Testing Line Class*****/
//    cout<<"\n******************************************************************************************"<<endl;
//    cout<<"Testing line class"<<endl;
//    cout<<"\n-Testing line default constructor"<<endl;
//    /**Default Constructor**/
//    Line l1;
//    point lStart1=l1.getStart();
//    cout<<"Default line start point: ("<<lStart1.x<<", "<<lStart1.y<<")"<<endl;
//    cout<<"Default line length: "<<l1.getLength()<<endl;
//    Orientation lOrient1=l1.getOrientation();
//    if (lOrient1==VERTICAL){
//        cout<<"Default orientation is: vertical"<<endl;
//    }else{
//        cout<<"Default orientation is: horizontal"<<endl;
//    }
//    /**Non-Default Constructor**/
//    cout<<"\n-Testing non-default line constructor"<<endl;
//    point lStart2;
//    lStart2.x=40;
//    lStart2.y=50;
//    int lineLength=20;
//    Orientation lOrient2=VERTICAL;
//    Line l2(lStart2,lineLength,lOrient2);
//    cout<<"Start point has been set to 40,50; length to 20, and the orientation to vertical"<<endl;
//    point lStart3=l2.getStart();
//    cout<<"Start point is: ("<<lStart3.x<<", "<<lStart3.y<<")"<<endl;
//    cout<<"The length of the line is: "<<l2.getLength()<<endl;
//    Orientation lOrient3=l2.getOrientation();
//    if(lOrient3==VERTICAL){
//        cout<<"The orientation is: vertical"<<endl;
//    }else{
//        cout<<"the orientation is: horizontal"<<endl;
//
//    }
//    //Setting values for line l2
//    cout<<"\n-Resetting values for line l2. Testing setters"<<endl;
//    point lStart4;
//    lStart4.x=70;
//    lStart4.y=90;
//    l2.setStart(lStart4);
//    l2.setLength(50);
//    l2.setOrientation(HORIZONTAL);
//    //Getting reset values
//    cout<<"Start point has been set to (70,90); the length to 50; and the orientation to horizontal."<<endl;
//    point lStart5=l2.getStart();
//    cout<<"The new start point is: "<<lStart5.x<<", "<<lStart5.y<<endl;
//    cout<<"The new line length is: "<<l2.getLength()<<endl;
//    Orientation lOrient4=l2.getOrientation();
//    if(lOrient4==VERTICAL){
//        cout<<"The orientation is: vertical"<<endl;
//    }else{
//        cout<<"the orientaion is: horizontal"<<endl;
//    }
//
//    /******************************************************************************************/
//    /*****Testing Switch Class*****/
//    cout<<"\n******************************************************************************************"<<endl;
//    cout<<"Testing switch class"<<endl;
//    cout<<"\n-Testing switch default constructor"<<endl;
//    /**Default Constructor**/
//    cout<<"The default center point is (0,0); the default height is 0; the default width is 0"<<endl;
//    Switch s1;
//    point sCenter1=s1.getCenter();
//    cout<<"Output of default center point: "<<sCenter1.x<<", "<<sCenter1.y<<endl;
//    cout<<"Output of the default height: "<<s1.getHeight()<<endl;
//    cout<<"Output of the default width: "<<s1.getWidth()<<endl;
//
//    cout<<"\n-Resetting values for default switch"<<endl;
//    //Setting values for switch s1
//    point sCenter2;
//    sCenter2.x=60;
//    sCenter2.y=90;
//    s1.setCenter(sCenter2);
//    s1.setHeight(50);
//    s1.setWidth(40);
//    point sCenter3=s1.getCenter();
//    cout<<"The switch center has been set to (60,90); the height to 50; the width to 40"<<endl;
//    cout<<"Reset default center point with primary center setter: ("<<sCenter3.x<<","<<sCenter3.y<<")"<<endl;
//    cout<<"Reset height: "<<s1.getHeight()<<endl;
//    cout<<"Reset width: "<<s1.getWidth()<<endl;
//    point sCenter4;
//    s1.setCenter(45,55);
//    sCenter4=s1.getCenter();
//    cout<<"Center point set to (45,55) using second center setter"<<endl;
//    cout<<"Reset default center point: ("<<sCenter4.x<<","<<sCenter4.y<<")"<<endl;
//
//    /**Non-Default Constructor**/
//    cout<<"\n-Testing the switch non-default constructor"<<endl;
//    point sCenter5;
//    sCenter5.x=100;
//    sCenter5.y=150;
//    Switch s2(sCenter5,60,60);
//    cout<<"Switch s2 center has been set to (100,150); height to 60; width to 60"<<endl;
//    cout<<"The center point of switch s2 is: ("<<sCenter5.x<<","<<sCenter5.y<<")"<<endl;
//    cout<<"The height of switch s2 is: "<<s2.getHeight()<<endl;
//    cout<<"The width of switch s2 is: "<<s2.getWidth()<<endl;
//
//    /******************************************************************************************/
//    /*****Testing Door Class*****/
//    cout<<"\n******************************************************************************************"<<endl;
//    cout<<"Testing Door class"<<endl;
//    cout<<"\n-Testing Door default constructor"<<endl;
//    /**Default Constructor**/
//    cout<<"The default constructor creates a line; sets the bool isOpen to false; and passes toOpen method a switch"<<endl;
//    Door d1;
//    cout<<"The default door state has been set to: "<<boolalpha<<d1.getDoorState()<<endl;
//    d1.setOpen("TRUE");
//    cout<<"The door state has been reset"<<endl;
//    cout<<"The door state of door d1 is reset to: "<<boolalpha<<d1.getDoorState()<<endl;
//
//    /**Non-Default Constructor**/
//    cout<<"\n-Testing the door non-default constructor"<<endl;
//    point dStart1;
//    dStart1.x=140;
//    dStart1.y=200;
//    int dLength1=20;
//    Orientation dOrient1=HORIZONTAL;
//    bool dOpen1=true;
//    Switch dSwitch1;
//    Door d2(dStart1,dLength1,dOrient1,dOrient1,dSwitch1);
//    point dStart2=d2.getStart();
//    cout<<"Door start point has been set to (140,200); length to 20; open to true, and orientation to horizontal"<<endl;
//    cout<<"The door d2 start point has been set to: ("<<dStart2.x<<","<<dStart2.y<<")"<<endl;
//    cout<<"The door d2 has a length of: "<<d2.getLength()<<endl;
//    cout<<"The door d2 has been set to: "<<boolalpha<<d2.getDoorState()<<endl;
//    if(dOrient1==VERTICAL){
//        cout<<"The orientation of door d2 is set to: vertical"<<endl;
//    }else{
//        cout<<"The orientation of door d2 is set to: horizontal"<<endl;
//    }
//
//
//    /******************************************************************************************/
//    /*****Testing Wall Class*****/
//    cout<<"\n******************************************************************************************"<<endl;
//    cout<<"Testing Wall class"<<endl;
//    cout<<"\n-Testing Wall default constructor"<<endl;
//    /**Default Constructor**/
//    Wall w1;
//    point wStart1=w1.getStart();
//    Orientation wOrient1;
//    cout<<"The default start point is (0,0); orientation is vertical; length is zero"<<endl;
//    cout<<"Default wall start point is: ("<<wStart1.x<<","<<wStart1.y<<")"<<endl;
//    wOrient1=w1.getOrientation();
//    if(wOrient1==VERTICAL){
//        cout<<"The default orientation is: vertical"<<endl;
//    }else{
//        cout<<"The default orientation is: horizontal"<<endl;
//    }
//    cout<<"The default length is: "<<w1.getLength()<<endl;
//
//    /**Non-Default Constructor**/
//    cout<<"\n-Testing the wall non-default constructor"<<endl;
//    point wStart2;
//    wStart2.x=300;
//    wStart2.y=245;
//    Orientation wOrient2=HORIZONTAL;
//    int wLength1=40;
//    Wall w2(wStart2,wLength1,wOrient2);
//    point wStart3=w2.getStart();
//    cout<<"Start point has been set to (300,245); orientation to horizontal; length to 40"<<endl;
//    cout<<"The non-default wall start has beens set to: ("<<wStart3.x<<","<<wStart3.y<<")"<<endl;
//    cout<<"The non-default wall length is: "<<w2.getLength()<<endl;
//    if(wOrient2==VERTICAL){
//        cout<<"The non-default wall orientation is set to: vertical"<<endl;
//    }else{
//        cout<<"The non-default wall orientation is set to: horizontal"<<endl;
//    }
//
//    //overloadedOperatorsTest();
//
//    //testDoor();
//
//    //testMonsterOverlap();
//
//    //testMonsterMoveOnPath();
//
//    //testMap();
//
//    testMapIO();
//
//    return 0;
//}


/************************************* TESTING OVERLOADED OPERATORS **********************************************/



void overloadedOperatorsTest() {
    PlayerPiece player;
    cout << "*********************************** TESTING PLAYERPIECE OVERLOADED OUTPUT OPERATOR ********************************" << endl;
    cout<< player << endl;

    PlayerPiece player2(24, 3667);
    cout<< player2 << endl;

    MonsterPiece monster;
    cout << "*********************************** TESTING MONSTERPIECE OVERLOADED OUTPUT OPERATOR ********************************" << endl;

    cout<< monster << endl;


    MonsterPiece monster2(24, 3667);
    cout<< monster2 << endl;
    cout << "*********************************** TESTING PLAYERPIECE OVERLOADED INPUT OPERATOR ********************************" << endl;
    std::string filename = "playerOverload.test",junk;
    ifstream ins(filename);
    PlayerPiece testPlayer;
    getline(ins,junk);
    if (ins) {
        ins >> testPlayer;
    }
    ins.close();
    cout << testPlayer << endl;
    cout << "*********************************** TESTING MONSTERPIECE OVERLOADED INPUT OPERATOR ********************************" << endl;
    std::string filename2 = "monsterOverload.test",junk2;
    ifstream ins2(filename2);
    MonsterPiece testMonster;
    getline(ins,junk2);
    if (ins) {
        ins >> testMonster;
    }
    ins.close();
    cout << testMonster << endl;


    testWallOverlap();
};

void testWallOverlap() {
    cout << setfill('*') << setw(100) << " " << std::endl;
    cout << "TESTING WALL OVERLAP" << endl;
    PlayerPiece p(50,50);
    p.setCenter({50,50});
    //test left
    Wall w1({24,75},75,VERTICAL);
    p.move(-1,0);
    cout << boolalpha << w1.checkPlayer(p) << endl;

    //test right
    Wall w2({49,75},75,VERTICAL);
    p.move(1,0);
    cout << boolalpha << w2.checkPlayer(p) << endl;
    p.move(0,10);

    //test top
    Wall w3({20,34},100,HORIZONTAL);
    p.move(0,-1);
    cout << boolalpha << w3.checkPlayer(p) << endl;

    //test bottom
    Wall w4({20,84},100,HORIZONTAL);
    p.move(0,1);
    cout << boolalpha << w4.checkPlayer(p) << endl;
    return;
}

void testDoor() {
    std::string filename = "door.test",junk;
    ifstream ins(filename);
    Door test;
    getline(ins,junk);//DOOR
    if (ins) {
        ins >> test;
    }
    ins.close();
    cout << test;
    PlayerPiece p(10,10);
    p.setCenter(25,100);
    if (test.checkSwitch(p)) {
        test.open();
    }
    cout << test;
    return;
}

void testMonsterOverlap() {
    cout << setfill('*') <<setw(75) << " "<< endl;
    cout << "Testing Monster Overlap" << endl;
    MonsterPiece m(50,50);
    m.setCenter(100,100);//left edge at x=75
    PlayerPiece p(50,50);
    m.setCenter(50,50);//right edge at x=75

    cout << endl << boolalpha << m.checkPlayer(p);
    return;
}

void testMonsterMoveOnPath() {
    cout << setfill('*') <<setw(75) << " "<< endl;
    cout << "Testing Monster Overlap" << endl;

    MonsterPiece m({25,25},{100,100,100},{200,175,150},5,5);

    m.addEndPoint({25,25});//start
    m.addEndPoint({30,25});//move right
    m.addEndPoint({30,20});//move up
    m.addEndPoint({25,20});//move left

    for (int c = 0; c < 20;c++) {//should go in a triangle
        m.moveOnPath();
        cout << "Move number " << c << endl;
        cout <<m << "path:" << m.getPath()<<endl<<endl;
        if (c%5==4) {
            cout << "CORNER" << endl;
        }
    }
    return;
}

//void testMap() {
//    cout << endl << setw(75) <<setfill('*') << " " << endl;
//    cout << "TESTING MAP" << endl;
//
//
//Map map({Wall({30,350},100,VERTICAL),Wall({60,350},100,VERTICAL),Wall({30,350},30,HORIZONTAL)},
//            "test1",{Door({30,300},30,HORIZONTAL,false,Switch({35,315},20,20))},{50,200},PlayerPiece({50,340},{0,0,255},
//                                                                                                     {0,0,255},10,10),
//            {MonsterPiece({50,135},{255,0,0},{255,0,0},50,50)});
//
//    //test piece move
//    cout << endl << setw(75) <<setfill('*') << " " << endl;
//    cout << "TESTING PLAYER PIECE MOVE AND DOOR AND WALL OVERLAP LOGIC" << endl<<endl;
//
//
//    cout<<"PLAYER POSITION: "<<map.getPlayer().getCenter()<<endl;
//    for (int i=0;i<50;i++) {
//        cout<<"MOVE LEFT #" <<i <<endl;
//        map.movePlayer(LEFT);
//        cout<<"PLAYER POSITION: "<<map.getPlayer().getCenter()<<endl;
//    }
//
//
//    cout<<endl<<"PRINTING MAP"<<endl;
//    cout<<map;
//    for (int i=0;i<50;i++) {
//        cout<<"MOVE RIGHT #" <<i <<endl;
//        map.movePlayer(RIGHT);
//        cout<<"PLAYER POSITION: "<<map.getPlayer().getCenter()<<endl;
//    }
//
//
//    cout<<endl<<"PRINTING MAP"<<endl;
//    cout<<map;
//    for (int i=0;i<50;i++) {
//        cout<<"MOVE DOWN #" <<i <<endl;
//        map.movePlayer(DOWN);
//        cout<<"PLAYER POSITION: "<<map.getPlayer().getCenter()<<endl;
//    }
//
//
//    cout<<endl<<"PRINTING MAP"<<endl;
//    cout<<map;
//    for (int i=0;i<150;i++) {
//        cout<<"MOVE UP #" <<i <<endl;
//        map.movePlayer(UP);
//        cout<<"PLAYER POSITION: "<<map.getPlayer().getCenter()<<endl;
//    }
//
//
//    cout<<endl<<"PRINTING MAP" <<endl;
//    cout<<map;
//    for (int i=0;i<10;i++) {
//        cout<<"MOVE DOWN #" <<i <<endl;
//        map.movePlayer(DOWN);
//        cout<<"PLAYER POSITION: "<<map.getPlayer().getCenter()<<endl;
//
//    }
//    for (int i=0;i<10;i++) {
//        cout<<"MOVE LEFT #" <<i <<endl;
//        map.movePlayer(LEFT);
//        cout<<"PLAYER POSITION: "<<map.getPlayer().getCenter()<<endl;
//    }
//
//
//    cout<<"TESTING SWITCH ACTIVATION AND DOOR OPENING"<<endl;
//    if(map.activateDoors()) {
//        cout << "SWITCH PUSHED; DOOR SHOULD BE OPEN" << endl;
//        cout << map.getDoors()[0] << endl;
//    }
//    cout<<"PRINTING MAP"<<endl;
//    cout<<map;
//
//    cout<<endl<<"TESTING GAME FINISH CHECK"<<endl;
//
//    for (int i=0;i<5;i++) {
//        cout<<"MOVE RIGHT #" <<i <<endl;
//        map.movePlayer(RIGHT);
//        cout<<"PLAYER POSITION: "<<map.getPlayer().getCenter()<<endl;
//    }
//    for (int i=0;i<250;i++) {
//        cout<<"MOVE UP #" <<i <<endl;
//        map.movePlayer(UP);
//        if (map.checkCompleted()) {
//            cout<<endl<<"LEVEL COMPLETE"<<endl;
//            break;
//        }
//    }
//    cout<<"PRINTING MAP"<<endl;
//    cout<<map;
//
//    cout << endl << "TESTING MONSTER MOVEONPATH FUNCTION" << endl;
//    //add move points to monster piece
//    for (MonsterPiece &m : map.getMonsters()) {
//        m.addEndPoint({50, 200});
//        cout << m;
//    }
//
//    //move monsters
//    for (int i=0;i<65;i++) {
//        cout <<endl<< "MOVE #" << i << endl<<endl;
//        map.moveMonsters();
//        cout <<"MONSTER POSITION: " << map.getMonsters()[0].getCenter();
//    }
//
//
//    if (map.checkMonsterCollision()) {
//        cout <<endl<<"OH NO! A MONSTER ATE YOU!" <<endl;
//    }
//
//    return;
//}
//
//void testMapIO() {
//    Map map({Wall({30,350},100,VERTICAL),Wall({60,350},100,VERTICAL),Wall({30,350},30,HORIZONTAL)},
//                          "test1",{Door({30,300},30,HORIZONTAL,false,Switch({35,315},20,20))},Square()
//                            ,PlayerPiece({50,340},{0,0,255}, {0,0,255},10,10),
//                          {MonsterPiece({50,135},{255,0,0},{255,0,0},50,50)});
//    cout << endl<<setfill('*')<<setw(75)<<" "<< endl<< "TESTING SAVE STATE AND LOAD STATE" <<endl;
//    map.saveToFile("testSave");
//    Map map2("testSave");
//    cout <<"PRINTING MAP 2" << endl << map2;
//}