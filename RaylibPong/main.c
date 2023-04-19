#include "raylib.h"

struct Actor{
    float posX;
    float posY;
    float width;
    float height;
    Color color;
};

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    struct Actor
 player1 = {10,screenHeight/2 , 30, 100, RED}; 
    
    InitWindow(screenWidth, screenHeight, "raylib pong clone");

    SetTargetFPS(60);              
  
    while (!WindowShouldClose())   
    {
        if(IsKeyDown(KEY_DOWN))
        {
            player1.posY += 10;
        }  
        
        if(IsKeyDown(KEY_UP))
        {
            player1.posY -= 10;
        }

        BeginDrawing();

            ClearBackground(BLACK);
            
            DrawRectangle(player1.posX ,player1.posY, player1.width, player1.height, player1.color); 

            DrawText("Actor
         1 can now move up and down", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
       
    }
    
    CloseWindow();       
    

    return 0;
}

