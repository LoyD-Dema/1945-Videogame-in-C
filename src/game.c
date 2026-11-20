#include "raylib.h"
#include "game.h"


void init()
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "1945");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
}

void gameloop()
{
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Input

        // Update

        // Draw
        BeginDrawing();

            ClearBackground(WHITE);

        EndDrawing();
    }

    CloseWindow();
}

    
    