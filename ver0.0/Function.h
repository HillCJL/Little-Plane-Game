#ifndef Func_h
#define Func_h
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>
#include"Variable.h"

/*
This function is used to initial the gamePane.
*/
void init(gamePane * thePane, plane * thePlane, obstacle * theObstacle1, obstacle * theObstacle2) {
    thePlane->position.x = 0;
    thePlane->position.y = 0;
    theObstacle1->position.x = 0;
    theObstacle1->position.y = GAME_COL - 1;
    theObstacle2->position.x = 1;
    theObstacle2->position.y = GAME_COL - 3;

    int i, j;

    for ( i = 0; i < GAME_ROW; i++ ) {
        for ( j = 0; j < GAME_COL; j++ ) {
            thePane->pane[i][j] = BLANK;
        }
    }

    setplane(thePane, thePlane);
    setobstacle(thePane, theObstacle1);
    setobstacle(thePane, theObstacle2);
    thePane->gameOver = 0;
    thePane->cursor.x = 0;
    thePane->cursor.y = 0;
}


/*
I didn't use this function because I don't know what it can do
*/
void setCursor(gamePane * thePane, const int x, const int y) {
    thePane->cursor.x = x;
    thePane->cursor.y = y;
}

/*
This function is used to set the plane position as well as to judge whether the plane is on collision with a obstacle.
*/
void setplane(gamePane * thePane, plane * plane) {
    /*On collision with the obstacle*/
    if ( thePane->pane[plane->position.x][plane->position.y] == OBSTACLE ) {
        thePane->gameOver = 1;
        gameOver();
        return;
    }
    thePane->pane[plane->position.x][plane->position.y] = PLANE;
}

/*
This function is to used to set a obstacle as well as to judge whether the obstacle is on collision with a plane.
*/
void setobstacle(gamePane * thePane, obstacle * obstacle) {
    /*On collision with the plane*/
    if ( thePane->pane[obstacle->position.x][obstacle->position.y] == PLANE ) {
        thePane->gameOver = 1;
        gameOver();
        return;
    }
    thePane->pane[obstacle->position.x][obstacle->position.y] = OBSTACLE;
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
void printPane(const gamePane thePane) {
    int i, j;
    for ( i = 0; i < GAME_ROW; i++ ) {
        for ( j = 0; j < GAME_COL; j++ ) {
            printf("%d", thePane.pane[i][j]);
        }
        printf("\n\n");
    }
}

/*
This function is used to move the plane as well judge whether the player wanna move the plane or fire.
*/
void movePlane(gamePane * thePane, plane * thePlane, OP op) {
    removeOBJ(thePane, thePlane->position);
    switch ( op ) {
    case 0:
        if ( thePlane->position.x > 0 ) {
            thePlane->position.x--;
        }
        break;
    case 1:
        if ( thePlane->position.x < GAME_ROW - 1 ) {
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
    }
    setplane(thePane, thePlane);
}

/*
This function is used to move the obstacle.
*/
void moveObstacle(gamePane * thePane, obstacle * theObstacle) {
    removeOBJ(thePane, theObstacle->position);
    if ( theObstacle->position.y <= 0 ) {
        theObstacle->position.y = GAME_COL - 1;
    }

    theObstacle->position.y--;

    setobstacle(thePane, theObstacle);
}
#endif