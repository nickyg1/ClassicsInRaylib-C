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

    float ballVelocityX = 10;
    float ballVelocityY = 10; 

    InitWindow(screenWidth, screenHeight, "Arkanoid Clone");

    SetTargetFPS(60);         

    for(int i = 0; i < brickLayer -1; i++)
    {
        bricks[i].posX = i * 30;
        bricks[i].posY = 1;
        bricks[i].width = 50;
        bricks[i].height = 20;
        bricks[i].color = GREEN; 
    }

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

            if(ball.posX < 0 || ball.posX > screenWidth - ball.width)
            {
                ballVelocityX = -1 * ballVelocityX;
            }
             
            if(ball.posY > screenHeight - ball.height|| ball.posY < 0 )
            {
                ballVelocityY = -1 * ballVelocityY; 
            }
            
            if(ball.posY + ball.height > player.posY  && ball.posX > player.posX  && ball.posX < player.posX + player.width && ballVelocityY > 0)
            {
                ballVelocityY = -1 * ballVelocityY; 
            }
            
            for(int i = 0; i < brickLayer -1; i++)
            {
                if(ball.posY < bricks[i].posY + 20  && ball.posX > bricks[i].posX && ball.posX  < bricks[i].posX + 50){
                    bricks[i].posX = 5000;
                    bricks[i].posY = 5000;
                    bricks[i].width = 0;
                    bricks[i].height = 0;
                    bricks[i].color = BLANK; 
                    ballVelocityY = -1 * ballVelocityY; 
                }
            }
            //Draw Bricks
            for(int i = 0; i < brickLayer -1; i++)
            {
                DrawRectangle(bricks[i].posX * 2 , bricks[i].posY * 2 , bricks[i].width, bricks[i].height, bricks[i].color);
            }

            ball.posY += ballVelocityY;
            ball.posX += ballVelocityX;            
            
            //Draw the player rectangle 
            DrawRectangle(player.posX, player.posY, player.width, player.height,player.color);
            
            //Draw the ball
            DrawRectangle(ball.posX, ball.posY, ball.width, ball.height, ball.color);

        EndDrawing();
       
    }

    CloseWindow(); 
   

    return 0;
}

