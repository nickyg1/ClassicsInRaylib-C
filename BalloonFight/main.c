#include "raylib.h"

void StartScreen();

void InitGame();

typedef enum GameState {STARTSCREEN, GAME, GAMEOVER} GameState;

struct Actor 
{
    int x;
    int y;
    int width;
    int height; 
    Color color; 

};
GameState gameState = STARTSCREEN;  
int main(void)
{
    
    InitGame(); 
    
    
    
    switch (gameState)
    {
        case STARTSCREEN:
        { 
            StartScreen();
        }
        break; 
        
        case GAME:
        {

        }break;

    }
   
    CloseWindow();        
   
    return 0;
}
const int screenWidth = 640;
const int screenHeight = 480;
void InitGame()
{
    

    InitWindow(screenWidth, screenHeight, "Balloon Fight Clone");

    SetTargetFPS(60);    
    
}

void StartScreen()
{
    struct Actor startGame = {screenWidth * 0.5f , 100 , 100, 100, GREEN};
    struct Actor secondPlayerGame = {screenWidth * 0.5f - 100, 160 , 100, 100, GREEN};
    struct Actor exitGame = {screenWidth * 0.5f , 220 ,  100, 100, GREEN };
    
    struct Actor actors[] = {startGame, exitGame, secondPlayerGame };
   
    //datatype size_variable = *(&array_name + 1) - array_name;
    int counterMax = *(&actors + 1) - actors;//pointer arithmetic 

    int counter = 0; 
    
    int exitBool;

    while (!WindowShouldClose() && exitBool )    
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
                }
            }break;

            case 2:
            {
                exitGame.color = RED; 
                
                startGame.color = BLUE; 
                secondPlayerGame.color = BLUE;
               
                if(IsKeyPressed(KEY_ENTER))
                {
                  exitBool = 0; 
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

