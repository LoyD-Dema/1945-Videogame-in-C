#include "player.h"
#include <math.h>

char __currentSprite = 0;
float __playerSpeed;
Vector2 __confiens;
Vector2 __startPos;
Vector2 __velocity;

Sprite_t playerSprites[3];
Vector2 playerPos;

void InitPlayer(Vector2 startPos, float speed, Vector2 confiens)
{
    playerSprites[0] =  (Sprite_t){ 301, 103, 65, 65, CENTERED_PIVOT(65 * GetScale().x , 65 * GetScale().y)};
    playerSprites[1] =  (Sprite_t){ 301, 169, 65, 65, CENTERED_PIVOT(65 * GetScale().x , 65 * GetScale().y)};
    playerSprites[2] =  (Sprite_t){ 301, 235, 65, 65, CENTERED_PIVOT(65 * GetScale().x , 65 * GetScale().y)};   

    __startPos = startPos;
    playerPos = startPos;
    __playerSpeed = speed;    
    __confiens = confiens;
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
        float sum = 1.0f / len;
        dir.x *= sum;
        dir.y *= sum;
    }

    float dt = GetFrameTime();
    __velocity = (Vector2){dir.x * __playerSpeed * dt, dir.y * __playerSpeed * dt};
    
}

void ConfinePlayer()
{
    playerPos.x += __velocity.x;
    float minX = __startPos.x - __confiens.x;
    float maxX = __startPos.x + __confiens.x;

    if (playerPos.x < minX) playerPos.x = minX;
    if (playerPos.x > maxX) playerPos.x = maxX; 


    playerPos.y += __velocity.y;

    float minY = __startPos.y - __confiens.y;
    float maxY = __startPos.y + __confiens.y;

    if (playerPos.y < minY) playerPos.y = minY;
    if (playerPos.y > maxY) playerPos.y = maxY; 
    
}