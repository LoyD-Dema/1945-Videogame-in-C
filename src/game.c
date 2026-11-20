#include "raylib.h"
#include "game.h"
#include <stdio.h> 
#include <math.h>
#include "spriteHandler.h"

// Variables
const int screenWidth = 1280;
const int screenHeight = 720;


// Private functions
static void __Input()
{

}

static void __Update()
{
    UpdateFrameCounter();
}

static void __Draw()
{
    ClearBackground(BLUE);
}




void Init()
{
    InitWindow(screenWidth, screenHeight, "1945");

    InitSpriteHandler();

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
}

void Gameloop()
{
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Input
        __Input();

        // Update
        __Update();

        // Draw
        BeginDrawing();
        __Draw();
        EndDrawing();
    }

    CloseWindow();
}



    
    