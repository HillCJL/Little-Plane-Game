#include"Function.h"

#pragma warning(disable:4996)

int main() {
    gamePane Map;
    plane player;
    OP op;
    obstacle ob[20];
    missile ms[20],*pms[20];
    struct UI ui;
    int input = 0;
    int i;

    /*Initial the missile's point.*/
    for ( i = 0; i < 10; i++ ) {
        pms[i] = &ms[i];
    }
    /*Initial the gamePane.*/
    init(&Map, &player, &ob[0], &ob[1]);
    /*Initial the UI.*/
    ui.PAGE = MAIN;
    ui.Selection = 1;
    /*Initial the high score.*/
    for ( i = 0; i < 10; i++ ) {
        *(ui.highscore + i) = 0;
    }
    while ( ui.PAGE ) {
        /*UI*/
        while ( (ui.PAGE != START) && (ui.PAGE != EXIT) ) {
            system("cls");
            printUI(ui);
            /*Control of main menu.*/
            while ( ui.PAGE == MAIN ) {
                /*Read the operation from the keyboard.*/
                Sleep(SleepTime);
                if ( kbhit() != 0 ) {
                    input = getch();
                }
                switch ( input ) {

                /*Operation UP*/
                case 'w':
                case 'W':
                    /*Ignore if the arrow is on the first selection.*/
                    if ( ui.Selection == 1 ) {
                        break;
                    }
                    else {
                        ui.Selection -= 1;
                        system("cls");
                        printUI(ui);
                    }
                    break;

                /*Operation DOWN*/
                case 's':
                case 'S':
                    /*Ignore if the arrow is on the last selection.*/
                    if ( ui.Selection == 4 ) {
                        break;
                    }
                    else {
                        ui.Selection += 1;
                        system("cls");
                        printUI(ui);
                    }
                    break;

                /*Operation DECIDE*/
                case ' ':
                    switch ( ui.Selection ) {
                    case 1:
                        ui.PAGE = START;
                        break;
                    case 2:
                        ui.PAGE = HELP;
                        break;
                    case 3:
                        ui.PAGE = HIGHSCORE;
                        break;
                    case 4:
                        ui.PAGE = EXIT;
                        break;
                    default:
                        break;
                    }
                    break;
                default:
                    break;
                }
                input = 0;
            }
            system("cls");
            printUI(ui);
            while ( ui.PAGE == GAMEOVER ) {
                /*Read the operation from the keyboard.*/
                Sleep(SleepTime);
                if ( kbhit() != 0 ) {
                    input = getch();
                }
                /*Operation BACK*/
                if ( input == ' ' ) {
                    ui.PAGE = MAIN;
                }
                input = 0;
            }
            system("cls");
            printUI(ui);
            while ( ui.PAGE == HIGHSCORE ) {
                /*Read the operation from the keyboard.*/
                Sleep(SleepTime);
                if ( kbhit() != 0 ) {
                    input = getch();
                }
                /*Operation BACK*/
                if ( input == ' ' ) {
                    ui.PAGE = MAIN;
                }
                input = 0;
            }
            system("cls");
            printUI(ui);
            while ( ui.PAGE >= HELP ) {
                /*Read the operation from the keyboard.*/
                Sleep(SleepTime);
                if ( kbhit() != 0 ) {
                    input = getch();
                }
                switch ( input ) {

                /*Operation LAST PAGE*/
                case 'a':
                case 'A':
                    /*Ignore if it is the first page now.*/
                    if ( ui.PAGE == HELP ) {
                        break;
                    }
                    else {
                        ui.PAGE -= 1;
                        system("cls");
                        printUI(ui);
                    }
                    break;

                /*Operation NEXT PAGE*/
                case 'd':
                case 'D':
                    /*Ignore if it is the last page now.*/
                    if ( ui.PAGE == HELP9 ) {
                        break;
                    }
                    else {
                        ui.PAGE += 1;
                        system("cls");
                        printUI(ui);
                    }
                    break;
                /*Operation BACK*/
                case ' ':
                    ui.PAGE = MAIN;
                    break;
                default:
                    break;
                }
                input = 0;
            }
        }
        if ( ui.PAGE == EXIT ) {
            break;
        }else{
            input = 0;
            init(&Map, &player, &ob[0], &ob[1]);
        }
        /*main game*/
        if ( ui.PAGE == START ) {
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

                /*Operation of the explosion's timer while there is explosion on the gamePane. */
                if ( Map.ExplosionFlag > 0 ) {
                    countExplosion(&Map);
                }
                else {
                    Map.TimeBeforeNextExplosion = Map.TimeAlreadyGo = 0;
                }

                /*Add the timer's value, and prevent the timer from leaking.*/
                ++Map.TimeHadRun;
                if ( Map.TimeHadRun > 10000000 ) {
                    Map.TimeHadRun %= 100000000;
                }
                /*Level up judge.*/
                if ( !(Map.TimeHadRun%TimeToLevelUp) ) {
                    Map.level++;
                    Map.MessageFlag = 1;
                    Map.ObstacleFlag = (Map.level > 9) ? 20 : (Map.level * 2 + 1);
                    Map.TimeToMove = (7 - Map.level / 2 > 0) ? (7 - Map.level / 2) : 1;
                }
                /*If there are missile, move it.*/
                for ( i = 0; i < Map.MissileFlag; i++ ) {
                    moveMissile(&Map, pms, ob, i);
                }
                /*To control the obstacle's speed, the obstacle will wait for some time before it moves.*/
                if ( !(Map.TimeHadRun%Map.TimeToMove) ) {
                    for ( i = 0; i < Map.ObstacleFlag; i++ ) {
                        moveObstacle(&Map, &ob[i], i, pms);
                    }
                }
                /*When weapon is broken, count down time.*/
                if ( Map.WeaponIsBroken != 0 ) {
                    Map.TimeBeforeRepair--;
                    if ( Map.TimeBeforeRepair <= 0 ) {
                        Map.TimeBeforeRepair = 0;
                        Map.WeaponIsBroken = 0;
                    }
                }
                /*Move the plane*/
                movePlane(&Map, &player, op, pms, ob);
            }
            /*Game Over.*/
            RefreshHighScore(Map.Score, &ui);
            ui.score = Map.Score;
            ui.level = Map.level;
            ui.PAGE = GAMEOVER;
        }
    }
    return 0;
}