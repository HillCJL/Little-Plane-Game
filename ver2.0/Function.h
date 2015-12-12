#ifndef Func_h
#define Func_h
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>
#include"Variable.h"

/*
This function is used to print the UI
MAIN is the main screem include PLAY, HELP ,HIGHSCORE and QUIT.
*/
void printUI(UI theUI) {
    int i, j;
    /*In this part, the function will judge which selection the arrow are,and print it.*/
    if ( theUI.PAGE == MAIN ) {
        printf("------------------\n");
        printf("|   Adventure    |\n");
        printf("|       of       |\n");
        printf("|  Little Plane  |\n");
        printf("|                |\n");
        /*Play*/
        printf("|    ");
        if ( theUI.Selection == 1 ) {
            printf(arrow);
        }
        else {
            printf("  ");
        }
        printf("play      |\n");
        /*Help*/
        printf("|    ");
        if ( theUI.Selection == 2 ) {
            printf(arrow);
        }
        else {
            printf("  ");
        }
        printf("help      |\n");
        /*HighScore*/
        printf("| ");
        if ( theUI.Selection == 3 ) {
            printf(arrow);
        }
        else {
            printf("  ");
        }
        printf("High Score   |\n");
        /*Quit*/
        printf("|    ");
        if ( theUI.Selection == 4 ) {
            printf(arrow);
        }
        else {
            printf("  ");
        }
        printf("quit      |\n");
        printf("|                |\n");
        printf("|  w s to move   |\n");
        printf("| Space to select|\n");
        printf("------------------\n");

    }
    /*In this part, the function will print the score and level.*/
    if ( theUI.PAGE == GAMEOVER ) {
        printf("------------------\n");
        printf("|                |\n");
        printf("|                |\n");
        printf("|   Game Over!   |\n");
        printf("|                |\n");
        printf("|Score:");
        printf("%-10d|\n", theUI.score);
        printf("|Level:");
        printf("%-10d|\n", theUI.level);
        printf("|Best:");
        printf("%-11d|\n", (theUI.highscore)[0]);
        printf("|                |\n");
        printf("| Press Space to |\n");
        printf("|    continue    |\n");
        printf("|                |\n");
        printf("------------------\n");
        printf("\n");
    }
    /*In this part, high score will be printed.*/
    if ( theUI.PAGE == HIGHSCORE ) {
        printf("------------------\n");
        printf("|   High Score   |\n");
        for ( i = 0; i < 8; i++ ) {
            printf("|  %d  %-11d|\n", i+1,(theUI.highscore)[i]);
        }
        printf("|                |\n");
        printf("| Space to exit  |\n");
        printf("------------------\n");
    }
    /*In this part, help message will be printed.*/
    if ( theUI.PAGE >= HELP ) {
        switch ( theUI.PAGE ) {
        case HELP:
            printf("------------------\n");
            printf("|      Help      |\n");
            printf("| 2221 year,human|\n");
            printf("| start exploring|\n");
            printf("| the space using|\n");
            printf("| unmanned       |\n");
            printf("| spaceship which|\n");
            printf("| can move fast  |\n");
            printf("| and shoot.     |\n");
            printf("| And now you're |\n");
            printf("|             d¡ú|\n");
            printf("| Space to exit  |\n");
            printf("------------------\n");
            break;
        case HELP1:
            printf("------------------\n");
            printf("|      Help      |\n");
            printf("| the captain of |\n");
            printf("| a spaceship.   |\n");
            printf("| Your aim is to |\n");
            printf("| control a space|\n");
            printf("| ship to fly as |\n");
            printf("| further as you |\n");
            printf("| can and destroy|\n");
            printf("| the meteorolite|\n");
            printf("|¡ûa          d¡ú|\n");
            printf("| Space to exit  |\n");
            printf("------------------\n");
            break;
        case HELP2:
            printf("------------------\n");
            printf("|      Help      |\n");
            printf("| to collect some|\n");
            printf("| important      |\n");
            printf("| sample for     |\n");
            printf("| research.      |\n");
            printf("| But be careful |\n");
            printf("| don't be       |\n");
            printf("| crashed by the |\n");
            printf("| meteorolites.  |\n");
            printf("|¡ûa          d¡ú|\n");
            printf("| Space to exit  |\n");
            printf("------------------\n");
            break;
        case HELP3:
            printf("------------------\n");
            printf("|      Help      |\n");
            printf("| Basic Operation|\n");
            printf("|                |\n");
            printf("|wsad  move      |\n");
            printf("|      your plane|\n");
            printf("|                |\n");
            printf("|Space Select    |\n");
            printf("|      or fire   |\n");
            printf("|                |\n");
            printf("|¡ûa          d¡ú|\n");
            printf("| Space to exit  |\n");
            printf("------------------\n");
            break;
        case HELP4:
            printf("------------------\n");
            printf("|      Help      |\n");
            printf("| A   Plane      |\n");
            printf("| O   Meteorolite|\n");
            printf("| !   Missile    |\n");
            printf("| Life  Life bar |\n");
            printf("| Score Score    |\n");
            printf("| Heat  Weapon's |\n");
            printf("|       heat     |\n");
            printf("|                |\n");
            printf("|¡ûa          d¡ú|\n");
            printf("| Space to exit  |\n");
            printf("------------------\n");
            break;
        case HELP5:
            printf("------------------\n");
            printf("|      Help      |\n");
            printf("| Score and level|\n");
            printf("|    You can get |\n");
            printf("| score by shoot |\n");
            printf("| them or wait   |\n");
            printf("| until it is    |\n");
            printf("| outside the    |\n");
            printf("| screem, but    |\n");
            printf("| you will get   |\n");
            printf("|¡ûa          d¡ú|\n");
            printf("| Space to exit  |\n");
            printf("------------------\n");
            break;
        case HELP6:
            printf("------------------\n");
            printf("|      Help      |\n");
            printf("| fewer score if |\n");
            printf("| you choose the |\n");
            printf("| second way.    |\n");
            printf("| As time goes by|\n");
            printf("| the diffculity |\n");
            printf("| will increase  |\n");
            printf("| but you can get|\n");
            printf("| more score as  |\n");
            printf("|¡ûa          d¡ú|\n");
            printf("| Space to exit  |\n");
            printf("------------------\n");
            break;
        case HELP7:
            printf("------------------\n");
            printf("|      Help      |\n");
            printf("| the sample you |\n");
            printf("| get is more    |\n");
            printf("| variable       |\n");
            printf("| comparing to   |\n");
            printf("| the sample     |\n");
            printf("| before.        |\n");
            printf("|                |\n");
            printf("|                |\n");
            printf("|¡ûa          d¡ú|\n");
            printf("| Space to exit  |\n");
            printf("------------------\n");
            break;
        case HELP8:
            printf("------------------\n");
            printf("|      Help      |\n");
            printf("| Cooldown system|\n");
            printf("|   You can't    |\n");
            printf("| keep shooting  |\n");
            printf("| because the    |\n");
            printf("| weapon will    |\n");
            printf("| overheat.      |\n");
            printf("|   You should   |\n");
            printf("| move frequently|\n");
            printf("|¡ûa          d¡ú|\n");
            printf("| Space to exit  |\n");
            printf("------------------\n");
            break;
        case HELP9:
            printf("------------------\n");
            printf("|      Help      |\n");
            printf("| to avoid the   |\n");
            printf("| weapon being   |\n");
            printf("| overheat.      |\n");
            printf("|  If the weapon |\n");
            printf("| is overheat,   |\n");
            printf("| you need to    |\n");
            printf("| wait until it's|\n");
            printf("| repaired.      |\n");
            printf("|¡ûa             |\n");
            printf("| Space to exit  |\n");
            printf("------------------\n");
            break;
        }
    }
}
/*
This function is used to refresh the highscore.
*/
void RefreshHighScore(int Score, struct UI *theUI) {
    int i;
    int InsertFlag = 0;
    int temp, store;
    for ( i = 0; i < 10; i++ ) {
        if ( InsertFlag == 0 ) {
            if ( (theUI->highscore)[i] <= Score ) {
                store = (theUI->highscore)[i];
                (theUI->highscore)[i] = Score;
                InsertFlag = 1;
            }
        }
        else {
            temp = (theUI->highscore)[i];
            (theUI->highscore)[i] = store;
            store = temp;
        }
    }
}

/* 
This function is used to initial the game.
    For convience , many variables are put into struct gamePane.
    In main function, gamePane wil refresh every 50ms ,I define it a turn.
$Variable introduction$
    TimeToMove is "How many turns to move the obstacle",TimeHadRun is a timer for obstacle.
    TimeAlreadyGo is a timer for Explosion.
    MessageTime is a timer for message showing.
    MissileFlag, ObstacleFlag, ExplosionFlag are stack flags.
    LifeOfPlane is the life of plane.
    cooldown is a counter of heat.
    WeaponIsBroken is a flag to show whether the weapon needs be repaired.0 is no,1 is yes.
*/
void init(gamePane * thePane, plane * thePlane, obstacle * theObstacle1, obstacle * theObstacle2) {
    thePlane->position.x = TEMP + 9;
    thePlane->position.y = 5;
    thePane->TimeHadRun = 1;
    thePane->TimeToMove = 7;
    thePane->Score = 0;
    thePane->level = 1;
    thePane->ObstacleFlag = 2;
    thePane->MissileFlag = 0;
    thePane->ExplosionFlag = 0;
    thePane->pHead = thePane->pEnd = thePane->pTemp = thePane->pNew = NULL;
    thePane->TimeAlreadyGo = thePane->TimeBeforeNextExplosion = 0;
    thePane->MessageFlag = thePane->MessageTime = 0;
    thePane->LifeOfPlane = Life;
    thePane->cooldown = 0;
    thePane->WeaponIsBroken = 0;
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
    setplane(thePane, thePlane,0);
    setobstacle(thePane, theObstacle1, 0, 0);
    setobstacle(thePane, theObstacle2, 1, 0);
    thePane->gameOver = 0;
    thePane->cursor.x = 0;
    thePane->cursor.y = 0;
}

/*
This function is used to judge whether the plane is destroyed.
*/
void LifeJudge(gamePane *thePane) {
    if ( thePane->LifeOfPlane <= 0 ) {
        thePane->gameOver = 1;
    }
}

/*
This function is used to judge if the weapon is overheated.
*/
void WeaponJudge(gamePane *thePane) {
    if ( thePane->cooldown >= 1000 ) {
        thePane->WeaponIsBroken = 1;
        thePane->cooldown = 0;
        thePane->TimeBeforeRepair = (TimeToRepair)*((thePane->level) / 2 + 1);
    }
}

/*
This function is used to set the plane position as well as to judge whether the plane is on collision with a obstacle.
*/
void setplane(gamePane * thePane, plane * plane,obstacle *theObstacle) {
    /*On collision with the obstacle*/
    if ( thePane->pane[plane->position.x][plane->position.y] >= OBSTACLE ) {
        thePane->LifeOfPlane--;
        LifeJudge(thePane);
        (theObstacle + thePane->pane[plane->position.x][plane->position.y] - OBSTACLE)->position.x = 1;
        (theObstacle + thePane->pane[plane->position.x][plane->position.y] - OBSTACLE)->position.y = (int)(clock()) % 10;
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
        thePane->Score += (thePane->level) * 3;
        return;
    }
    /*If not on collision, set the gamePane*/
    if ( thePane->pane[(*(theMissile + MissileNum))->position.x][(*(theMissile + MissileNum))->position.y] == EXPLOSION ) {
        removeExplosion(thePane);
    }
    if ( thePane->pane[(*(theMissile + MissileNum))->position.x][(*(theMissile + MissileNum))->position.y] == BLANK ) {
        thePane->pane[(*(theMissile + MissileNum))->position.x][(*(theMissile + MissileNum))->position.y] = MISSILE_0 +(enum object)MissileNum;
    }

}

/*
This function is to used to set a obstacle as well as to judge whether the obstacle is on collision with a missile, a plane or a explosion smoke.
*/
void setobstacle(gamePane * thePane, obstacle * theObstacle, int ObstacleNum, missile **theMissile) {
    missile *mtemp;
    int MissileNum;
    /*On collision with the plane*/
    if ( thePane->pane[theObstacle->position.x][theObstacle->position.y] == PLANE ) {
        thePane->LifeOfPlane--;
        LifeJudge(thePane);
        theObstacle->position.x = 1;
        theObstacle->position.y = (int)(clock()) % 10;
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
        thePane->Score += thePane->level * 3;
    }
    if ( thePane->pane[theObstacle->position.x][theObstacle->position.y] == EXPLOSION ) {
        removeExplosion(thePane);
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
    thePane->pHead = thePane->pHead->pNext;
    removeOBJ(thePane, thePane->pTemp->position);
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
This function is used to print the gamePane.
*/
void printPane(gamePane *thePane) {
    int i, j, k;
    for ( k = 0; k < GAME_COL + 2; k++ ) {
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
        printf("|");
        /*Print the score.*/
        if ( i == TEMP ) {
            printf("Score:%d", thePane->Score);
        }
        /*Print the level.*/
        if ( i == TEMP + 1 ) {
            printf("Level:%d", thePane->level);
        }
        /*Print the lifebar.*/
        if ( i == TEMP + 2 ) {
            printf("Life:");
        }
        if ( i == TEMP + 3 ) {
            for ( j = 0; j < thePane->LifeOfPlane; j++ ) {
                printf("¨{");
            }
        }
        /*Print the level-up message*/
        if ( i == TEMP + 4) {
            if ( thePane->MessageFlag == 1 ) {
                printf(LevelUpMessage);
                (thePane->MessageTime)++;
            }
            if ( thePane->MessageTime >= MessageShowUpTime ) {
                thePane->MessageFlag = 0;
            }
        }
        /*Print the heat message or the repair message.*/
        if ( i == TEMP + 5 ) {
            if ( thePane->WeaponIsBroken == 0 ) {
                printf("Heat");
            }
            else {
                printf("Repairing:");
            }
        }
        if ( i == TEMP + 6 ) {
            if ( thePane->WeaponIsBroken == 0 ) {
                for ( j = 0; j < ((thePane->cooldown) / 200); j++ ) {
                    printf("¨z");
                }
            }
            else {
                printf("%ds left", ((thePane->TimeBeforeRepair) / 10 + 1));
            }
        }
        if ( i == TEMP + 7 ) {
            if( thePane->cooldown >= 800 ) printf(CoolDownMessage);
        }

        printf("\n");
    }
    for ( i = 0;  i< GAME_COL + 2; i++ ) {
        printf("-");
    }
    printf("\n");
}

/*
This function is used to move the plane as well judge whether the player wanna move the plane or fire.
    If the weapon need not to be repair, count the cooldown value.
*/
void movePlane(gamePane * thePane, plane * thePlane, OP op, missile ** theMissile, obstacle *theObstacle) {
    removeOBJ(thePane, thePlane->position);
    switch ( op ) {
    case 0:
        if ( thePane->WeaponIsBroken == 0 ) {
            thePane->cooldown -= CoolEachMovement;
            thePane->cooldown = (thePane->cooldown <= 0) ? 0 : thePane->cooldown;
        }
        if ( thePlane->position.x > TEMP ) {
            thePlane->position.x--;
        }
        break;
    case 1:
        if ( thePane->WeaponIsBroken == 0 ) {
            thePane->cooldown -= CoolEachMovement;
            thePane->cooldown = (thePane->cooldown <= 0) ? 0 : thePane->cooldown;
        }
        if ( thePlane->position.x < GAME_ROW + TEMP - 1 ) {
            thePlane->position.x++;
        }
        break;
    case 2:
        if ( thePane->WeaponIsBroken == 0 ) {
            thePane->cooldown -= CoolEachMovement;
            thePane->cooldown = (thePane->cooldown <= 0) ? 0 : thePane->cooldown;
        }
        if ( thePlane->position.y > 0 ) {
            thePlane->position.y--;
        }
        break;
    case 3:
        if ( thePane->WeaponIsBroken == 0 ) {
            thePane->cooldown -= CoolEachMovement;
            thePane->cooldown = (thePane->cooldown <= 0) ? 0 : thePane->cooldown;
        }
        if ( thePlane->position.y < GAME_COL - 1 ) {
            thePlane->position.y++;
        }
        break;
    case 4:
        if ( thePane->WeaponIsBroken == 0 ) {
            createMissile(theMissile, thePane, thePlane);
            thePane->cooldown += HeatEachShoot;
            WeaponJudge(thePane);
        }
        break;
    default:
        if ( thePane->WeaponIsBroken == 0 ) {
            thePane->cooldown -= CoolIfWait;
            thePane->cooldown = (thePane->cooldown <= 0) ? 0 : thePane->cooldown;
        }
        break;
    }
    setplane(thePane, thePlane, theObstacle);
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
        thePane->Score += (thePane->level)/2 + 1;
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