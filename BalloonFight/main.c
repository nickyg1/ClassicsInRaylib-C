#include "raylib.h"

void StartScreen();
void GameScreen();
void GameOverScreen();

void InitGame();

typedef enum GameState {STARTSCREEN = 0, GAME, GAMEOVER} GameState;

struct Actor 
{
    int x;
    int y;
    int width;
    int height; 
    Color color; 

};
GameState gameState;  

void GameChanger()
{
 switch (gameState)
    {
        case STARTSCREEN:
        { 
            StartScreen();
        }
        break; 
        
        case GAME:
        {
            GameScreen();

        }break;

        case GAMEOVER:
        {
            GameOverScreen();
        } break;
    }

}

int main(void)
{
    
    InitGame(); 

    GameChanger();
   
    CloseWindow();        
   
    return 0;
}

const int screenWidth = 640;
const int screenHeight = 480;

void InitGame()
{
    gameState = STARTSCREEN; 
    InitWindow(screenWidth, screenHeight, "Balloon Fight Clone");

    SetTargetFPS(60);    
    
}
void StartScreen()
{
    struct Actor startGame = {screenWidth * 0.5f, 100, 100, 100, GREEN};
    struct Actor secondPlayerGame = {screenWidth * 0.5f - 100, 160, 100, 100, GREEN};
    struct Actor exitGame = {screenWidth * 0.5f, 220, 100, 100, GREEN};

    struct Actor actors[] = {startGame, exitGame, secondPlayerGame};

    //datatype size_variable = *(&array_name + 1) - array_name;
    int counterMax = *(&actors + 1) - actors;//pointer arithmetic 

    int counter = 0;

    while (!WindowShouldClose() && gameState == STARTSCREEN)    
    {

        if(IsKeyPressed(KEY_UP))
        {
            counter--;
        }

        if(IsKeyPressed(KEY_DOWN))
        {
            counter++; 
        }  
       
        if(counter >= counterMax )
        {
            counter = 0;
        }
        if(counter < 0)
        {
            counter = counterMax-1; 
        }
    

        switch(counter)
        {
            case 0:
            {
                //has to be a better way to assign color changes, seems so bulky 
               startGame.color = RED; 
              
               exitGame.color = BLUE; 
               secondPlayerGame.color = BLUE;
               
               if(IsKeyPressed(KEY_ENTER))
               {
                    gameState = GAME;
                  GameChanger();
               }

            }break;
            
            case 1:
            {
                secondPlayerGame.color = RED;
               
                exitGame.color = BLUE; 
                startGame.color = BLUE; 
               
                if(IsKeyPressed(KEY_ENTER))
                {
                    
                   gameState = GAME;
                   GameChanger();
                
                }

            }break;

            case 2:
            {
                exitGame.color = RED; 
                
                startGame.color = BLUE; 
                secondPlayerGame.color = BLUE;
               
                if(IsKeyPressed(KEY_ENTER))
                {
                  gameState = GAMEOVER;
                  GameChanger();
                }

            }break;
       }

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawRectangle(startGame.x,  startGame.y,  startGame.width, startGame.height, startGame.color); 
        DrawRectangle(secondPlayerGame.x,  secondPlayerGame.y,  secondPlayerGame.width,secondPlayerGame.height, secondPlayerGame.color); 
        DrawRectangle(exitGame.x,  exitGame.y,  exitGame.width, exitGame.height, exitGame.color); 
        EndDrawing();
    }
}

void GameScreen()
{
    struct Actor player = {10,10,10,10,BLUE};

    while (!WindowShouldClose() && gameState == GAME)    
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(player.x, player.y, player.width, player.height, player.color);
        
        EndDrawing();
   }
}

void GameOverScreen()
{
     EndDrawing();
}

