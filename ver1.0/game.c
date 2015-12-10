#include"Function.h"

#pragma warning(disable:4996)


int main() {
    gamePane Map;
    plane player;
    OP op,  input = 0;
    obstacle ob[20];
    missile ms[20],*pms[20];
    int i;
    int score = -1;
    for ( i = 0; i < 10; i++ ) {
        pms[i] = &ms[i];
    }
    init(&Map, &player, &ob[0], &ob[1]);
    while ( input != EXIT ) {
        /*UI*/
        if ( score != -1 ) {
            printf("You Score: %d , your best result: %d\n", Map.Score, score);
            printf("Wanna Play again, press 'g',wanna quit ,press 'q':");
        }
        else {
            printf("Press 'g' to start,'q' to quit:");
        }
        while ( (input != START) && (input !=  EXIT) ) {
            Sleep(SleepTime);
            if ( kbhit() != 0 ) {
                input = getch();
            }
            switch ( input ) {
            case 'g':
            case 'G':
                input = START;
                break;
            case 'q':
            case 'Q':
                input = EXIT;
                break;
            default:
                input = 0;
                break;
            }
        }
        if ( input == EXIT ) {
            break;
        }else{
            input = 0;
            init(&Map, &player, &ob[0], &ob[1]);
        }
        /*main game*/
        while ( !Map.gameOver ) {
            /* Read the operation*/
            printPane(&Map);
            Sleep(SleepTime);
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
            ++Map.TimeHadRun;
            if ( Map.ExplosionFlag > 0 ) {
                countExplosion(&Map);
            }
            else {
                Map.TimeBeforeNextExplosion = Map.TimeAlreadyGo = 0;
            }
            if ( Map.TimeHadRun > 10000000 ) {
                Map.TimeHadRun %= 100000000;
            }
            if ( !(Map.TimeHadRun%Map.TimeToLevelUp) ) {
                Map.level++;
                Map.MessageFlag = 1;
                Map.ObstacleFlag = (Map.level > 9) ? 20 : (Map.level * 2 + 1);
                Map.TimeToMove = (7 - Map.level / 2 > 0) ? (7 - Map.level / 2) : 1;
            }
            for ( i = 0; i < Map.MissileFlag; i++ ) {
                moveMissile(&Map, pms, ob, i);
            }
            if ( !(Map.TimeHadRun%Map.TimeToMove) ) {
                for ( i = 0; i < Map.ObstacleFlag; i++ ) {
                moveObstacle(&Map, &ob[i], i,pms);
                }
            }
            movePlane(&Map, &player, op, pms);
        }
        score = (Map.Score > score) ? Map.Score : score;
    }
    
    return 0;
}