#include "raylib.h"

struct Actor{
    float posX;
    float posY;
    float width;
    float height;
    Color color;
};

typedef enum GameScreen {LOGO = 0, TITLE, GAMEPLAY, ENDING} GameScreen; 

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    struct Actor ball = {screenWidth * 0.5f, screenHeight * 0.5f, 20,20, WHITE};  
    float ballVelocityX =10;
    float ballVelocityY = 10;
 

    struct Actor player1 = {10,screenHeight * 0.5f , 30, 100, RED}; 
    float player1PaddleWidth = player1.width + ball.width * 0.5f;  

    struct Actor player2 = {screenWidth - 40,screenHeight * 0.5f , 30, 100,BLUE};
    float player2PaddleWidth = player2.width - ball.width * 0.5f;
    int score1 = 0;
    int score2 = 0;
      
    InitWindow(screenWidth, screenHeight, "raylib pong clone");

    GameScreen currentScreen = LOGO; 
    int framesCounter = 0; 

    SetTargetFPS(30);              
  
    while (!WindowShouldClose())   
    {
        switch(currentScreen)
        {
            case LOGO:
            {
                framesCounter++; 

                if(framesCounter > 30)
                {
                    currentScreen = TITLE; 
                }
            }break; 

            case TITLE:
            {
                if(IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = GAMEPLAY;
                }
            }break;

            case GAMEPLAY: 
            {
                 if(score1 >= 1 || score2>= 1)
                {
                    currentScreen = ENDING;
                }

            }break; 

            case ENDING:
            {
            
            }break; 
        }
       
        
        if(currentScreen == GAMEPLAY) 
        {
        //Player input 
        if(IsKeyDown(KEY_DOWN) && player1.posY < screenHeight - player1.height)
        {
            player1.posY += 10;
        }  
        if(IsKeyDown(KEY_UP) && player1.posY > 0)
        {
            player1.posY -= 10;
        }

        //AI Movement 
        if(ballVelocityY < 0 && player2.posY > 0)
        {
            player2.posY -= 6;
        }
        else if (ballVelocityY > 0 && player2.posY < screenHeight - player2.height )
        {
            player2.posY += 6;
        }
        else
        {
            player2.posY += 0;
        }

        //ball collision physics
        if(ball.posX < 0)
        {
            score2++;
            ball.posX = screenWidth * 0.5f; 
            ball.posY = screenHeight * 0.5f;
            ballVelocityY =  -1 * ballVelocityY;
        }
        if( ball.posX > (screenWidth - ball.width) )
        {
            score1++;
            ball.posX = screenWidth * 0.5f; 
            ball.posY = screenHeight * 0.5f;
            ballVelocityY =  -1 * ballVelocityY;
        }
        if (ball.posY < 0 || ball.posY > (screenHeight - ball.width) )
        {
            ballVelocityY =  -1 * ballVelocityY;
        }

        //Paddle collsion physics 
        if((ball.posX < player1.posX +  player1PaddleWidth
            && ball.posY > player1.posY - player1.height * 0.5f 
            && ball.posY < player1.posY + player1.height) || 
        (ball.posX > player2.posX -  player2PaddleWidth 
            && ball.posY > player2.posY - player2.height * 0.5f 
            && ball.posY < player2.posY + player2.height ) )
        {
            ballVelocityY =  -1 * ballVelocityY;
            ballVelocityX =  -1 * ballVelocityX;
        }

        ball.posX += ballVelocityX;
        ball.posY += ballVelocityY;
        }
        
     
        BeginDrawing();

        ClearBackground(BLACK);

        switch(currentScreen)
        {
            case LOGO:
            {
                // TODO: Draw LOGO screen here!
                    DrawText("LOADING ... PONG", 20, 20, 40, LIGHTGRAY);
                    
            }break;
            case TITLE:
            {
                  DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                    DrawText("PONG READY", 20, 20, 40, DARKGREEN);
                    DrawText("PRESS ENTER", 120, 220, 20, DARKGREEN);
            }break; 
            case GAMEPLAY:
            {
                DrawRectangle(player1.posX ,player1.posY, player1.width, player1.height, player1.color);
                DrawRectangle(player2.posX ,player2.posY, player2.width, player2.height, player2.color);
                DrawRectangle(ball.posX, ball.posY, ball.width, ball.height, ball.color); 
                DrawText(TextFormat(" %d:%d", score1,score2), screenWidth * 0.5f - 50, 10, 50, LIGHTGRAY);
            }break;
            case ENDING:
            {
                 DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                DrawText("GAME", 20, 20, 40, DARKBLUE);
                char* winner = "";
                if(score1 > score2)
                {
                  winner ="PLAYER 1 WINS!";
                }
                else
                {
                    winner ="PLAYER 2 WINS!";
                }
                DrawText(("%s", winner), 120, 220, 20, DARKBLUE);
            }
        }
            

        EndDrawing();
       
    }
    
    CloseWindow();       
    

    return 0;
}

