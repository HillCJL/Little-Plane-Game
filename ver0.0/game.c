#include"Function.h"

#pragma warning(disable:4996)


int main() {
    gamePane Map;
    plane player;
    OP op,  input = 0;
    obstacle ob[20];
    int i;
    init(&Map, &player, &ob[0], &ob[1]);
        /*main game*/
        while ( !Map.gameOver ) {
            /* Read the operation*/
            printPane(Map);
            Sleep(200);
            system("cls");
            if ( kbhit() != 0 ) {
                while ( kbhit() != 0 ) {
                    op = getch();
                }
            }
            else {
                op = -1;
            }
            switch ( op ) {
            case 'W':
            case 'w':
                op = 0;
                break;
            case 'S':
            case 's':
                op = 1;
                break;
            case 'A':
            case 'a':
                op = 2;
                break;
            case 'D':
            case 'd':
                op = 3;
                break;
            case ' ':
                op = 4;
                break;
            default:
                break;
            }
            movePlane(&Map, &player, op);
            moveObstacle(&Map, ob);
            moveObstacle(&Map, ob + 1);
        } 
    return 0;
}