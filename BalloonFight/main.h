#ifndef MAIN_H
#define MAIN_H

#include "raylib.h" 

typedef enum GameState {STARTSCREEN = 0, GAME, GAMEOVER} GameState;

struct Actor 
{
    int x;
    int y;
    int width;
    int height; 
    Color color; 

};

#endif
