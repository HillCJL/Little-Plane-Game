#ifndef GAME_H
#define GAME_H

// Time setting
#define TimeToRemoveExplosion 8
#define SleepTime 50

// PaneModel
#define PlaneModel "A"
#define ObstacleModel "O"
#define NullPaneModel " "
#define MissileModel "!"
#define ExplosionModel "*"

// message setting
#define LevelUpMessage "Level Up!"
#define CoolDownMessage "Needed cool down!"
#define MessageShowUpTime 50

typedef struct point {
    int x;
    int y;
} point;

typedef enum objects {
    BLANK = 0, PLANE = 1, OBSTACLE = 30, OBSTACLE_0, OBSTACLE_1, OBSTACLE_2, OBSTACLE_3, OBSTACLE_4, OBSTACLE_5, OBSTACLE_6, OBSTACLE_7, OBSTACLE_8, OBSTACLE_9\
    ,MISSILE_0 = 10, MISSILE_1, MISSILE_2, MISSILE_3, MISSILE_4, MISSILE_5, MISSILE_6, MISSILE_7, MISSILE_8, MISSILE_9, MISSILE_10, EXPLOSION = 2
} OBJ;

typedef enum operations {
    UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3, FIRE = 4, START = 5, EXIT = 6
} OP;

typedef struct exp {
    point position;
    int SurviveTime;
    struct exp *pNext;
} explosion;

// Size of map
#define GAME_ROW 11
#define GAME_COL 11
#define TEMP 10

typedef struct gamePane {
    // the game pane, 0 for blank, 1 for plane and 2 for obstacle
    OBJ pane[GAME_ROW + TEMP][GAME_COL];
    point cursor;
    // How long to move the obstacle
    int TimeToMove;
    int TimeHadRun;
    int gameOver;
    // add point
    int  HighScore, Score, level;
    int  TimeToLevelUp;
    // stack flag
    int ObstacleFlag, MissileFlag, ExplosionFlag;
    // explosion link
    explosion *pHead, *pEnd, *pTemp, *pNew;
    int TimeBeforeNextExplosion, TimeAlreadyGo;
    // Message
    int MessageFlag, MessageTime;
} gamePane;

typedef struct plane {
    point position;
} plane;

typedef struct obstacle {
    point position;
} obstacle;

typedef struct missile {
    point position;
} missile;



// function list
void init(gamePane *thePane, plane * thePlane, obstacle * theObstacle1, obstacle * theObstacle2);
void setCursor(gamePane * thePane, const int x, const int y);

void setplane(gamePane * thePane, plane * plane);
void setobstacle(gamePane * thePane, obstacle * theObstacle);
void setMissile(gamePane * thePane, missile ** theMissile, obstacle *theObstacle, int MissileNum);

void createExplosion(gamePane *thePane, point position);
void countExplosion(gamePane *thePane);
void removeExplosion(gamePane *thePane);

void createMissile(missile **theMissile, gamePane *thePane, plane *thePlane);

void removeOBJ(gamePane * thePane, const point p);
void gameOver();
void printPane(const gamePane thePane);
void movePlane(gamePane * thePane, plane * thePlane, OP op);
void moveObstacle(gamePane * thePane, obstacle * theObstacle);
void moveMissile(gamePane * thePane, missile ** theMissile, obstacle *theObstacle, int MissileNum);
#endif // GAME_H

