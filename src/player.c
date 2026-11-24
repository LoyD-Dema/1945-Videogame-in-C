#include "player.h"
#include <math.h>

char __currentSprite = 0;
float __playerSpeed;
Vector2 __confiens;
Vector2 __startPos;
Vector2 __velocity;
float __width;
float __height;
float __fireRate = 0.5f;
float __elapsedFireRateTime;

Sprite_t playerSprites[3];
Vector2 playerPos;
Rectangle boxCollsion;
float playerHealth = 10.0f;
char playerLife = 3;
unsigned int playerScore = 0;

#pragma region Private Functions
static void __HandleMovement()
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

static void __Shoot()
{
    // Pooling
    TraceLog(LOG_INFO,"Im Shooting");
}

static void __HandleShoot()
{
    if(IsKeyDown(KEY_SPACE))
    {
        if(__elapsedFireRateTime <= 0)
        {
            __elapsedFireRateTime = __fireRate;
            
            // Can shoot
            __Shoot();
        }
    }
}

static void __ConfinePlayer()
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

#pragma endregion

void InitPlayer(Vector2 startPos, float speed, Vector2 confiens)
{

    float width = 65;
    float height = 65;

    __width = width * GetScale().x;
    __height = height * GetScale().y;
    __elapsedFireRateTime = 0;


    playerSprites[0] =  (Sprite_t){ 301, 103, width, height, CENTERED_PIVOT(width , height)};
    playerSprites[1] =  (Sprite_t){ 301, 169, width, height, CENTERED_PIVOT(width , height)};
    playerSprites[2] =  (Sprite_t){ 301, 235, width, height, CENTERED_PIVOT(width , height)};   

    __startPos = startPos;
    playerPos = startPos;
    __playerSpeed = speed;    
    __confiens = confiens;
    boxCollsion = (Rectangle){playerPos.x, playerPos.y, __width - 35, __height - 25};
}

void HandlePlayerInput()
{   
    __HandleMovement();
    __HandleShoot();
}

void UpdatePlayer()
{
    __ConfinePlayer();

    // Update boxCollider pod
    boxCollsion.x = playerPos.x;
    boxCollsion.y = playerPos.y;

    __elapsedFireRateTime -= GetFrameTime();
}

Sprite_t GetPlayerCurrentSprite()
{
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





void DrawPlayerCollisionRect()
{
    DrawRectangleLines(boxCollsion.x - boxCollsion.width * 0.5f, boxCollsion.y - boxCollsion.height * 0.5f, boxCollsion.width, boxCollsion.height, GREEN);
}