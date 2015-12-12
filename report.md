#Report of Little Plane Game

---

Well I think starting with the idea of my game is the best.

##Idea of my game

1.A beautiful UI is needed, however, making such a UI will spend too much time, so I didn't write it until ver2.0 .

2.A score-counting system is needed , or the game won't have a goal to achieve.

3.The diffculity should increase as time goes by, so the level system is set.

4.It's boring to keep avoiding being hit by the obstacle, so I make a missile which can destroy the obstacle.

5.I don't want somebody just keep shooting in a corner without moving, so I set a cooldown system to make the game more challenging. 

6.Well finally I add a background story for my game.You can check it in the help menu.


##Algorithm

###1.How to read from the keyboard
First, in order to input the order without waiting for an ENTER, functions in `conio.h` is used in the program.

`kbhit()` ,return 0 if nothing is enter. I use it to judge whether anything is input.

`getch()`, return what is input.I use a while loop to read the last operation enter from the keyboard.

I use the function `Sleep()` from `Windows.h` to let the program wait for player's input , and the obstacle and the plane won't move too fast.

###2.Add a missile

A missile is a struct include its position.

I use a stack to control the missile.I choose array to make a stack. 

When the player enter Space, push a missile.

When the missile is on collision with a obstacle, exchange this missile with the one on the top of the stack, and pop it.

###3.Add explosion

I use a queue to control the explosion, as the explosion act as queue.A link is used to make the queue.

Each explosion is a struct include its position and survive time, so it's easy to let the explosion out of queue.

###4.About obstacle

When a obstacle is on collision with a missile , move it out of screen.

###5.About game pane

To prevent the game pane from bount , I enlarge the array and print only part of them,some of invisible part will be used to store the object that won't show now.

###6.About lifebar and cooldown system

Well it's just some variable operation and judge.

##Problem I met

###1.Struct defination

I wrote the forrowing code at first

```c
// function.h

typedef struct UI {
    int PAGE;
    int highscore[10];
    int score;
    int level;
    page Selection;
} UI;
typedef enum page {
    EXIT = 0, MAIN, START, GAMEOVER, HIGHSCORE, HELP, HELP1, HELP2, HELP3, HELP4, HELP5, HELP6, HELP7, HELP8, HELP9
} page;

// main.c
#include"function.h"
int main() {
	UI ui;
		if(ui.PAGE == 1) { }
}
```

The complier said that ui is not a struct.
When I check it later, I found that `struct page` is used in `struct UI`, however, the declaration of `struct page` is after the `struct UI`. So the complier can't accept the declaration of `struct UI` , and `UI` become a undefine identifier.So I exchange the position of these struct.

```c
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
```

###2.One function call another function

Well the problem is as same as the last question,I call a function before it is declared.

But I don't need to exchange the position of these two function, just write a declaration before functions' defination.

##What I learn?

1.Well I didn't use `typedef` before until I dealt with this project.It's convenient, and I will use it from now on.

2.After searching from the Internet, I knew what the 
```
#ifndef   ××
#define   ××


#endif 
```

is used for and the disadventage of `#pragma once`.

3.I become more skilful in using a link after this project.

---