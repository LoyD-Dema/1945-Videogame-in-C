#include "raylib.h"
#include "game.h"
#include "spriteHandler.h"
#include "player.h"
#include "UI.h"

// Variables
const int screenWidth = 1280; //640
const int screenHeight =  960; //480


// Private functions
static void __Input()
{
    HandlePlayerInput();
}

static void __Update()
{
    UpdateFrameCounter();
    UpdatePlayer();

    
}

static void __Draw()
{
    ClearBackground(BLUE);
    DrawSprite(GetPlayerCurrentSprite(), playerPos, 0, WHITE);
    
    // CollsionsBox
    DrawPlayerCollisionRect();
    
    // UI
    DrawUI(screenWidth, screenHeight);
}




void Init()
{
    InitWindow(screenWidth, screenHeight, "1945");
    
    // SpriteHandler
    InitSpriteHandler(0.15f);
    ChangeScale((Vector2){2.0f, 2.0f});

    // Player
    InitPlayer((Vector2){screenWidth * 0.5f, screenHeight * 0.5f}, 250.0f, 
                (Vector2){screenWidth * 0.5f - 100, 75});

    // UI
    InitUI(playerHealth, playerLife);
    
    
    
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



    
    