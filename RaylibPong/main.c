#include "raylib.h"
struct Player{
    float xPos;
    float yPos;
}
int main(void)
{
   
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib pong clone");

    SetTargetFPS(60);              
  
    while (!WindowShouldClose())   
    {
        
        BeginDrawing();

            ClearBackground(BLACK);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
       
    }
    
    CloseWindow();       
    

    return 0;
}

