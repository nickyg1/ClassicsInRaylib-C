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

    struct Actor ball = {screenWidth * 0.5f, screenHeight * 0.5f, 20,20, WHITE};  
    float ballVelocityX =10;
    float ballVelocityY = 10; 

    struct Actor player1 = {10,screenHeight * 0.5f , 30, 100, RED}; 
    float player1PaddleWidth = player1.width + ball.width * 0.5f;  
      
    InitWindow(screenWidth, screenHeight, "raylib pong clone");

    SetTargetFPS(60);              
  
    while (!WindowShouldClose())   
    {
        if(IsKeyDown(KEY_DOWN) && player1.posY < screenHeight - player1.height)
        {
            player1.posY += 10;
        }  
        
        if(IsKeyDown(KEY_UP) && player1.posY > 0)
        {
            player1.posY -= 10;
        }

        if(ball.posX < 0 || ball.posX > (screenWidth - ball.width) )
        {
           ballVelocityX =  -1 * ballVelocityX;
        }

        if(ball.posY < 0 || ball.posY > (screenHeight - ball.width) )
        {
            ballVelocityY =  -1 * ballVelocityY;
        }

        if(ball.posX < player1.posX +  player1PaddleWidth
            && ball.posY > player1.posY - player1.height * 0.5f 
            && ball.posY < player1.posY + player1.height ) 
        {
            ballVelocityY =  -1 * ballVelocityY;
            ballVelocityX =  -1 * ballVelocityX;
        }

        ball.posX += ballVelocityX;
        ball.posY += ballVelocityY;
            
        BeginDrawing();

            ClearBackground(BLACK);
            
            DrawRectangle(player1.posX ,player1.posY, player1.width, player1.height, player1.color); 
            DrawRectangle(ball.posX, ball.posY, ball.width, ball.height, ball.color); 
            DrawText("Actor can now move up and down", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
       
    }
    
    CloseWindow();       
    

    return 0;
}

