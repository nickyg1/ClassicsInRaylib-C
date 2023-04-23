#include "raylib.h"
#include <stdio.h>

struct actor
{
    int posX;
    int posY;
    int width;
    int height;
    Color color;
};

//struct actor bricks[];

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;


    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);             
    int brickLayer = screenWidth/60; 
    struct actor bricks[brickLayer]; 

    while (!WindowShouldClose())    
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);

            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            for(int i = 0; i < brickLayer -1; i++)
            {
                bricks[i].posX = i * 30;
                bricks[i].posY = 1;
                bricks[i].width = 50;
                bricks[i].height = 20;
                bricks[i].color = RED; 

                DrawRectangle(bricks[i].posX * 2 , bricks[i].posY * 2 , bricks[i].width, bricks[i].height, bricks[i].color);
            }


        EndDrawing();
       
    }

    CloseWindow(); 
   

    return 0;
}

