#ifndef GAME_H
#define GAME_H

// const setting
#define TimeToRemoveExplosion 8
#define SleepTime 50
#define Life 6
#define MessageShowUpTime 100
#define TimeToRepair 50
#define HeatEachShoot 36
#define CoolEachMovement 24
#define CoolIfWait 6
#define TimeToLevelUp 500
#define moveObstacleTime 9

// PaneModel
#define PlaneModel "A"
#define ObstacleModel "O"
#define NullPaneModel " "
#define MissileModel "!"
#define ExplosionModel "*"
#define arrow "¡î"
// message setting
#define LevelUpMessage "Level Up!"
#define CoolDownMessage "Needed cool down!"


typedef enum page {
    EXIT = 0, MAIN, START, GAMEOVER, HIGHSCORE, HELP, HELP1, HELP2, HELP3, HELP4, HELP5, HELP6, HELP7, HELP8, HELP9
} page;

typedef struct UI {
    int PAGE;
    int highscore[10];
    int score;
    int level;
    page Selection;
} UI;


typedef struct point {
    int x;
    int y;
} point;

typedef enum objects {
    BLANK = 0, PLANE = 1, OBSTACLE = 30, OBSTACLE_0, OBSTACLE_1, OBSTACLE_2, OBSTACLE_3, OBSTACLE_4, OBSTACLE_5, OBSTACLE_6, OBSTACLE_7, OBSTACLE_8, OBSTACLE_9\
    ,MISSILE_0 = 10, MISSILE_1, MISSILE_2, MISSILE_3, MISSILE_4, MISSILE_5, MISSILE_6, MISSILE_7, MISSILE_8, MISSILE_9, MISSILE_10, EXPLOSION = 2
} OBJ;

typedef enum operations {
    UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3, FIRE = 4, SELECT = 5
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
    // Score Counting
    int  Score, level;
    // stack flag
    int ObstacleFlag, MissileFlag, ExplosionFlag;
    // explosion link
    explosion *pHead, *pEnd, *pTemp, *pNew;
    int TimeBeforeNextExplosion, TimeAlreadyGo;
    // Message
    int MessageFlag, MessageTime;
    // life of a plane
    int LifeOfPlane;
    int cooldown;
    int WeaponIsBroken;
    int TimeBeforeRepair;
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
void printUI(UI theUI);
void RefreshHighScore(int Score, UI *theUI);
void init(gamePane *thePane, plane * thePlane, obstacle * theObstacle1, obstacle * theObstacle2);
void LifeJudge(gamePane *thePane);
void WeaponJudge(gamePane *thePane);

void setplane(gamePane * thePane, plane * plane, obstacle *theObstacle);
void setobstacle(gamePane * thePane, obstacle * theObstacle, int ObstacleNum, missile **theMissile);
void setMissile(gamePane * thePane, missile ** theMissile, obstacle *theObstacle, int MissileNum);

void createExplosion(gamePane *thePane, point position);
void countExplosion(gamePane *thePane);
void removeExplosion(gamePane *thePane);

void createMissile(missile **theMissile, gamePane *thePane, plane *thePlane);

void removeOBJ(gamePane * thePane, const point p);
void printPane(const gamePane thePane);
void movePlane(gamePane * thePane, plane * thePlane, OP op, missile ** theMissile, obstacle *theObstacle);
void moveObstacle(gamePane * thePane, obstacle * theObstacle, int ObstacleNum, missile **theMissile);
void moveMissile(gamePane * thePane, missile ** theMissile, obstacle *theObstacle, int MissileNum);
#endif // GAME_H

