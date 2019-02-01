GAME:
    default constructor
    constructor that loads filenames for maps from another file

fields:
    vector of string filenames
    vector of maps
    int curMap
    player piece
    vector of monster pieces

methods:
    draw map
    clear screen
    draw player
    draw monsters
    move monsters
    move player left
    move player up
    move player right
    move player down
    next map
    stun monsters
    check player death
        collision with monster
    check switch activation
    
    save
        integer of level, pos of player - map and monsters are reset from file
    load

MAP:
    constructor that loads map from file

fields:
    vector of switches : square
    vector of walls
    vector of doors : line w/ open method (length = 0 and draw)
    point begin
    square end

methods:
    draw
    draw walls
    draw doors
    draw switches
    draw end

    vector<Wall> getWallsRow(int yCoordinate)
    vector<Wall> getWallsColumn(int xCoordinate)
        having these guys will allow us to only test collisions with walls that are feasible

    activate switch (int switch num)

    >> operator

MONSTER PIECE: circle

once created, a monster's state cannot be changed (except speed during stun)
fields:
    vector<Path> paths
    int curPath
    int stepsAlongPath
        we know the length of each line, so we can run move until stepsAlongPath == paths[curpath].length,
        then reset stepsAlongPath and increment curPath

methods:
    nextPath - goes backwards through paths once calling nextpath when curpath = nextpath.size-1
    move - switches on path direction, then increments appropriate position value appropriately


LINE:
enum Direction {UP, DOWN, LEFT, RIGHT}
constructors:
    default
    (start, length, direction)

fields:
    point start
    int length
    direction

methods:
    getstart
    getlength
    getdirection

    getPoints()
    getClosestPoint()
    distance(point a, point b)//global


WALL: Line

fields:
    color

methods:
    getcolor()
    setcolor(color new)

    draw()

    >> operator


DOOR: line
state: 
    isOpen
methods:
    open()
        sets length to 0

    >> operator


SWITCH: square
switch and square are exactly the same




For loading from file:
    we have two options
    1. we hard code into the file all wall and switch and piece and door info
        WALL
        HORIZONTAL
        0,0                     -start
        1000                    -length
        WALL
        etc...
        
    2. We have static fields (examples? TODO: ASK) within the game, that is attributed to a key word
    eg. '500rightwall', that we keep in Game