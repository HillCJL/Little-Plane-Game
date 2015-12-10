#ifndef Func_h
#define Func_h
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>
#include"Variable.h"
/* 
This function is used to initial the game.
    For convience , many variables are put into struct gamePane.
    In main function, gamePane wil refresh every 50ms ,I define it a turn.
$Variable introduction$
    TimeToMove is "How many turns to move the obstacle",TimeHadRun is a timer for obstacle.
    TimeToLevelUp is "How man turns to level up".
    TimeAlreadyGo is a timer for Explosion.
    MessageTime is a timer for message showing.
    MissileFlag, ObstacleFlag, ExplosionFlag are stack flags.
*/
void init(gamePane * thePane, plane * thePlane, obstacle * theObstacle1, obstacle * theObstacle2) {
    thePlane->position.x = TEMP + 9;
    thePlane->position.y = 5;
    thePane->TimeHadRun = 1;
    thePane->TimeToMove = 7;
    thePane->TimeToLevelUp = 300;
    thePane->Score = 0;
    thePane->level = 1;
    thePane->ObstacleFlag = 2;
    thePane->MissileFlag = 0;
    thePane->ExplosionFlag = 0;
    thePane->pHead = thePane->pEnd = thePane->pTemp = thePane->pNew = NULL;
    thePane->TimeAlreadyGo = thePane->TimeBeforeNextExplosion = 0;
    thePane->MessageFlag = thePane->MessageTime = 0;
    int i, j;
    for ( i = 0; i < GAME_ROW + TEMP; i++ ) {
        for ( j = 0; j < GAME_COL; j++ ) {
            thePane->pane[i][j] = BLANK;
        }
    }
    for ( i = 0; i < 2; i++ ) {
        for ( j = 0; j < 10; j++ ) {
            (theObstacle1 + i * 10 + j)->position.x = 0;
            (theObstacle1 + i * 10 + j)->position.y = j;
        }
    }
    theObstacle1->position.x = (int)(clock()) % 10;
    theObstacle2->position.x = (int)(clock()) % 8 + 2;
    setplane(thePane, thePlane);
    setobstacle(thePane, theObstacle1, 0, 0);
    setobstacle(thePane, theObstacle2, 1, 0);
    thePane->gameOver = 0;
    thePane->cursor.x = 0;
    thePane->cursor.y = 0;
}
// basic operation for game pane
void setCursor(gamePane * thePane, const int x, const int y) {
    thePane->cursor.x = x;
    thePane->cursor.y = y;
}

/*
This function is used to set the plane position as well as to judge whether the plane is on collision with a obstacle.
*/
void setplane(gamePane * thePane, plane * plane) {
    if ( thePane->pane[plane->position.x][plane->position.y] >= OBSTACLE ) {
        thePane->gameOver = 1;
        gameOver();
        return;
    }
    thePane->pane[plane->position.x][plane->position.y] = PLANE;
}
/*
This function is used to set a missile as well as to judge whether the missile is on collision with a obstacle or a explosion smoke.
    A stack is used to make a missile,when a collision happens,this missile will be exchange with another missile on the top of the stack if this missile isn't on the top. 
    If collision happens, the obstacle will be moved out of the visible map.
*/
void setMissile(gamePane * thePane, missile ** theMissile, obstacle *theObstacle, int MissileNum) {
    missile *mtemp;
    /*If on collision ,remove the missile and move the ostacle out of screen*/
    if ( thePane->pane[(*(theMissile + MissileNum))->position.x][(*(theMissile + MissileNum))->position.y] >= OBSTACLE ) {
        if ( MissileNum != thePane->MissileFlag - 1 ) {
            mtemp = *(theMissile + MissileNum);
            *(theMissile + MissileNum) = *(theMissile + thePane->MissileFlag - 1);
            *(theMissile + thePane->MissileFlag - 1) = mtemp;
            MissileNum = thePane->MissileFlag - 1;
        }
        (theObstacle + thePane->pane[(*(theMissile + MissileNum))->position.x][(*(theMissile + MissileNum))->position.y] - 30)->position.x = 0;
        (theObstacle + thePane->pane[(*(theMissile + MissileNum))->position.x][(*(theMissile + MissileNum))->position.y] - 30)->position.y = (int)(clock()) % 10;
        createExplosion(thePane, (*(theMissile + MissileNum))->position);
        thePane->MissileFlag--;
        thePane->Score += thePane->level;
        return;
    }
    /*If not on collision, set the gamePane*/
    if ( thePane->pane[(*(theMissile + MissileNum))->position.x][(*(theMissile + MissileNum))->position.y] == BLANK ) {
        thePane->pane[(*(theMissile + MissileNum))->position.x][(*(theMissile + MissileNum))->position.y] = MISSILE_0 +(enum object)MissileNum;
    }

}
/*
This function is to used to set a obstacle as well as to judge whether the obstacle is on collision with a missile or a explosion smoke.
*/
void setobstacle(gamePane * thePane, obstacle * theObstacle, int ObstacleNum, missile **theMissile) {
    missile *mtemp;
    int MissileNum;
    /*On collision with the plane*/
    if ( thePane->pane[theObstacle->position.x][theObstacle->position.y] == PLANE ) {
        thePane->gameOver = 1;
        gameOver();
        return;
    }
    /*On collision with a missile*/
    if ( (thePane->pane[theObstacle->position.x][theObstacle->position.y] >= MISSILE_0) && (thePane->pane[theObstacle->position.x][theObstacle->position.y] <= MISSILE_0 +15) ) {
        MissileNum = thePane->pane[theObstacle->position.x][theObstacle->position.y] - MISSILE_0;
        thePane->pane[theObstacle->position.x][theObstacle->position.y] = EXPLOSION;
        theObstacle->position.x = 1;
        theObstacle->position.y = (int)(clock()) % 10;
        if ( MissileNum != thePane->MissileFlag - 1 ) {
            mtemp = *(theMissile + MissileNum);
            *(theMissile + MissileNum) = *(theMissile + thePane->MissileFlag - 1);
            *(theMissile + thePane->MissileFlag - 1) = mtemp;
            MissileNum = thePane->MissileFlag - 1;
        }
        createExplosion(thePane, (*(theMissile + MissileNum))->position);
        thePane->MissileFlag--;
        thePane->Score += thePane->level;
    }
    /*Judge whether anoter obstacle is in this obstacle's new position*/
    while ( thePane->pane[theObstacle->position.x][theObstacle->position.y] >= OBSTACLE ) {
        theObstacle->position.x--;
    }
    while ( (thePane->pane[theObstacle->position.x][theObstacle->position.y] < OBSTACLE) && (theObstacle->position.x < TEMP - 3) ) {
        theObstacle->position.x++;
    }
    /*Set the gamePane*/
    if ( thePane->pane[theObstacle->position.x][theObstacle->position.y] == BLANK ) {
        thePane->pane[theObstacle->position.x][theObstacle->position.y] = OBSTACLE + (enum object)ObstacleNum;
    }
}
/*
This function is used to create an explosion smoke.
    Explosion smoke is made by a queue through link.
*/
void createExplosion(gamePane * thePane, point position) {
    /*Initial smoke*/
    thePane->pNew = (struct exp*)malloc(sizeof(struct exp));
    thePane->pNew->position.x = position.x;
    thePane->pNew->position.y = position.y;
    thePane->pNew->SurviveTime = thePane->TimeBeforeNextExplosion;
    thePane->TimeBeforeNextExplosion = 0;
    if ( thePane->ExplosionFlag == 0 ) {
        thePane->pHead = thePane->pEnd = thePane->pNew;
        (thePane->pNew)->pNext = NULL;
    }
    else {
        thePane->pEnd->pNext = thePane->pNew;
        thePane->pNew->pNext = NULL;
        thePane->pEnd = thePane->pNew;
    }
    thePane->pane[thePane->pNew->position.x][thePane->pNew->position.y] = EXPLOSION;
    thePane->ExplosionFlag++;
}
/*
This function is used to remove the explosion smoke.
    Just a queue operation.
*/
void removeExplosion(gamePane *thePane) {
    thePane->pTemp = thePane->pHead;
    if ( thePane->ExplosionFlag > 1 ) {
        thePane->TimeAlreadyGo -= thePane->pHead->pNext->SurviveTime;
    }
    else {
        thePane->TimeAlreadyGo = thePane->TimeBeforeNextExplosion = 0;
    }
    removeOBJ(thePane, thePane->pTemp->position);
    thePane->pHead = thePane->pTemp->pNext;
    free(thePane->pTemp);
    thePane->ExplosionFlag--;
}

/*
This function is used to count how many turns the explosion smoke exist,and judge whether the smoke shound be remove.
*/
void countExplosion(gamePane *thePane) {
    thePane->TimeBeforeNextExplosion++;
    thePane->TimeAlreadyGo++;
    if ( thePane->TimeAlreadyGo >= TimeToRemoveExplosion ) {
        removeExplosion(thePane);
    }
}

/*
This function is used to create a missile.
    A stack operation.
*/
void createMissile(missile **theMissile, gamePane *thePane, plane *thePlane) {
    if ( thePlane->position.x > TEMP ) {
        (*(theMissile + thePane->MissileFlag))->position.x = thePlane->position.x;
        (*(theMissile + thePane->MissileFlag))->position.y = thePlane->position.y;
        thePane->MissileFlag++;
    }
}
/*
This function is used to remove the objects from the gamePane.
*/
void removeOBJ(gamePane * thePane, const point p) {
    thePane->pane[p.x][p.y] = BLANK;
}

/*
This function is used to print the game over message,but I think it useless.
*/
void gameOver() {
    printf("GameOver\n");
}

/*
This function is used to print the gamePane.
*/
void printPane(gamePane *thePane) {
    int i, j;
    printf("Score:%d\n", thePane->Score);
    printf("Level:%d\n", thePane->level);
    for ( i = 0; i < GAME_COL + 2; i++ ) {
        printf("-");
    }
    printf("\n");
    for ( i = TEMP; i < GAME_ROW + TEMP; i++ ) {
        printf("|");
        for ( j = 0; j < GAME_COL; j++ ) {
            switch ( thePane->pane[i][j] ) {
            case 0:
                printf(NullPaneModel);
                break;
            case 1:
                printf(PlaneModel);
                break;
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18:
            case 19:
            case 20:
                printf(MissileModel);
                break;
            case 30:
            case 31:
            case 32:
            case 33:
            case 34:
            case 35:
            case 36:
            case 37:
            case 38:
            case 39:
            case 40:
            case 41:
            case 42:
            case 43:
            case 44:
            case 45:
            case 46:
            case 47:
            case 48:
            case 49:
            case 50:
            case 51:
                printf(ObstacleModel);
                break;
            case EXPLOSION:
                printf(ExplosionModel);
                break;
            default:
                break;
            }
        }
        printf("|\n");

    }
    for ( i = 0; i < GAME_COL + 2; i++ ) {
        printf("-");
    }
    printf("\n");
    /*Message print.*/
    if ( thePane->MessageFlag == 1 ) {
        printf(LevelUpMessage);
        printf("\n");
        (thePane->MessageTime)++;
    }
    if ( thePane->MessageFlag == 2 ) {
        printf(CoolDownMessage);
        printf("\n");
        (thePane->MessageTime)++;
    }
    if ( thePane->MessageTime == MessageShowUpTime ) {
        thePane->MessageFlag = 0;
    }
}
/*
This function is used to move the plane as well judge whether the player wanna move the plane or fire.
*/
void movePlane(gamePane * thePane, plane * thePlane, OP op, missile ** theMissile) {
    removeOBJ(thePane, thePlane->position);
    switch ( op ) {
    case 0:
        if ( thePlane->position.x > TEMP ) {
            thePlane->position.x--;
        }
        break;
    case 1:
        if ( thePlane->position.x < GAME_ROW + TEMP - 1 ) {
            thePlane->position.x++;
        }
        break;
    case 2:
        if ( thePlane->position.y > 0 ) {
            thePlane->position.y--;
        }
        break;
    case 3:
        if ( thePlane->position.y < GAME_COL - 1 ) {
            thePlane->position.y++;
        }
        break;
    case 4:
        createMissile(theMissile, thePane, thePlane);
        break;
    }
    setplane(thePane, thePlane);
}

/*
This function is used to move the obstacle.
*/
void moveObstacle(gamePane * thePane, obstacle * theObstacle, int ObstacleNum, missile **theMissile) {
    if ( theObstacle->position.x >= 0 ) {
        if ( thePane->pane[theObstacle->position.x][theObstacle->position.y] == EXPLOSION ) {
            removeExplosion(thePane);
        }
        removeOBJ(thePane, theObstacle->position);
    }
    theObstacle->position.x++;
    if ( theObstacle->position.x > GAME_ROW + TEMP - 1 ) {
        theObstacle->position.x = TEMP - 3;
        theObstacle->position.y = (int)(clock()) % GAME_COL;
        //thePane->Score += (thePane->level)/2 + 1;
    }
    setobstacle(thePane, theObstacle, ObstacleNum, theMissile);
}
/*
This function is used to move the missile and remove the missile if the missile is outside the visible map.
*/
void moveMissile(gamePane * thePane, missile ** theMissile, obstacle *theObstacle, int MissileNum) {
    int temp;
    missile *mtemp;
    if ( thePane->pane[(*(theMissile + MissileNum))->position.x][(*(theMissile + MissileNum))->position.y] == EXPLOSION ) {
        removeExplosion(thePane);
    }
    removeOBJ(thePane, (*(theMissile + MissileNum))->position);
    (*(theMissile + MissileNum))->position.x--;

    if ( (*(theMissile + MissileNum))->position.x < TEMP - 3 ) {
        if ( MissileNum != thePane->MissileFlag - 1 ) {
            mtemp = *(theMissile + MissileNum);
            *(theMissile + MissileNum) = *(theMissile + thePane->MissileFlag - 1);
            *(theMissile + thePane->MissileFlag - 1) = mtemp;
            MissileNum = thePane->MissileFlag - 1;
        }
        thePane->MissileFlag--;
    }
    setMissile(thePane, theMissile, theObstacle, MissileNum);
}
#endif