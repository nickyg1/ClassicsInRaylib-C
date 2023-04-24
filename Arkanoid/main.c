#include "raylib.h"

struct actor
{
    int posX;
    int posY;
    int width;
    int height;
    Color color;
};

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    int brickLayer = screenWidth/60; 
    struct actor bricks[brickLayer];


    struct actor player = {screenWidth/2 - 75, screenHeight - 60, 150, 20, BLUE};
    struct actor ball = {screenWidth/2 , screenHeight/2, 20, 20, RED};

    InitWindow(screenWidth, screenHeight, "Arkanoid Clone");

    SetTargetFPS(60);         


    while (!WindowShouldClose())    
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            //Player Controls
            if(IsKeyDown(KEY_LEFT) && player.posX > 0)
            {
             player.posX -= 10;
            }

            if(IsKeyDown(KEY_RIGHT) && player.posX < screenWidth - player.width)
            {
              player.posX += 10;       
            }

            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            for(int i = 0; i < brickLayer -1; i++)
            {
                bricks[i].posX = i * 30;
                bricks[i].posY = 1;
                bricks[i].width = 50;
                bricks[i].height = 20;
                bricks[i].color = GREEN; 

                DrawRectangle(bricks[i].posX * 2 , bricks[i].posY * 2 , bricks[i].width, bricks[i].height, bricks[i].color);
            }
            
            //Draw the player rectangle 
            DrawRectangle(player.posX, player.posY, player.width, player.height,player.color);
            
            //Draw the ball
            DrawRectangle(ball.posX, ball.posY, ball.width, ball.height, ball.color);

        EndDrawing();
       
    }

    CloseWindow(); 
   

    return 0;
}

