#include "raylib.h"
#include "game.h"
#include "spriteHandler.h"
#include "player.h"

// Variables
const int screenWidth = 1280;
const int screenHeight = 960;


// Private functions
static void __Input()
{
    HandlePlayerInput();
}

static void __Update()
{
    UpdateFrameCounter();
    ConfinePlayer();
}

static void __Draw()
{
    ClearBackground(BLUE);
    DrawSprite(GetPlayerCurrentSprite(), playerPos, 0);
}




void Init()
{
    InitWindow(screenWidth, screenHeight, "1945");
    
    // SpriteHandler
    InitSpriteHandler(0.15f);
    ChangeScale((Vector2){2.0f, 2.0f});

    // Player
    InitPlayer((Vector2){screenWidth * 0.5f, screenHeight * 0.5f}, 250.0f, (Vector2){screenWidth * 0.5f - 100, 75});
    
    
    
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



    
    