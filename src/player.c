#include "player.h"
#include <math.h>

char __currentSprite = 0;
float __playerSpeed;

Sprite_t playerSprites[] =
{
    { 301, 103, 65, 65},
    { 301, 169, 65, 65},
    { 301, 235, 65, 65}    
};

Vector2 playerPos;

void InitPlayer(Vector2 startPos, float speed)
{
    playerPos = startPos;
    __playerSpeed = speed;    
}

Sprite_t GetPlayerCurrentSprite()
{
    Sprite_t tmp;

    switch(GetFrameCounter() % (sizeof(playerSprites) / sizeof(playerSprites[0])))
    {
        default:
        case 0:
            return playerSprites[0];
        case 1:
            return playerSprites[1];
        case 2:
            return playerSprites[2];
    }
}

void HandlePlayerInput()
{   
    Vector2 dir = (Vector2){0, 0};

    if (IsKeyDown(KEY_A))
    {
        dir.x -= 1;
    }
    if(IsKeyDown(KEY_D))
    {
        dir.x += 1;                   
    }
    if(IsKeyDown(KEY_W))
    {
        dir.y -= 1;
    }
    if(IsKeyDown(KEY_S))
    {
        dir.y += 1;   
    }


    float len = sqrtf(dir.x * dir.x + dir.y * dir.y);
    if (len > 0.0f)
    {
        dir.x /= len;
        dir.y /= len;
    }

    float dt = GetFrameTime();
    playerPos.x += dir.x * __playerSpeed * dt;
    playerPos.y += dir.y * __playerSpeed * dt;
}