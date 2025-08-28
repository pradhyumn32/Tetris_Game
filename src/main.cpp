#include "raylib.h"
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;

bool eventTriggered(double interval){
    double currentTime = GetTime();
    if(currentTime-lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}
int main(){
    // Color darkBlue = {44,44,127,255};
    //initialize game window dimensions
    InitWindow(500, 620, "Raylib Tetris");
    SetTargetFPS(60); // setting game fps

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    Game newGame = Game();

    while(!WindowShouldClose()){ //window should close meaning pressing esc key or closing the window action
        UpdateMusicStream(newGame.music);

        newGame.handleInput();

        if(eventTriggered(0.2)) newGame.moveBlockDown();

        BeginDrawing();
        ClearBackground(darkBlue); //fills the background with the specified color


        DrawTextEx(font, "Score:", {365,15}, 38, 2, WHITE);
        DrawRectangleRounded({320,55,170,60}, 0.3,6, lightBlue);
        

        if(newGame.gameOver){
        DrawTextEx(font, "GAME OVER \n Press any \n key for \n New Game", {320,450}, 32, 2, WHITE);
    }
        DrawTextEx(font, "Next:", {370,175}, 38, 2, WHITE);
        DrawRectangleRounded({320,215,170,180}, 0.3,6, lightBlue);

        char scoreText[10];
        sprintf(scoreText,"%d", newGame.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38,2);
        DrawTextEx(font, scoreText, {320+(170-textSize.x)/2,65}, 34, 2, WHITE);

        newGame.Draw();
        EndDrawing();
    }

    //close window
    CloseWindow();
}