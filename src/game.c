#include "raylib.h"
#include "game.h"
#include <stdio.h>

// Variables



// Private functions
static void __Input()
{

}

static void __Update()
{
    
}

static void __Draw()
{
    ClearBackground(BLUE);

}




void Init()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "1945");

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



    
    