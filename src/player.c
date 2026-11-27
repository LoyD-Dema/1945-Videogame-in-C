#include "player.h"
#include <math.h>
#include "bullet.h"
#include "stdlib.h"

static char __currentSprite = 0;
static float __playerSpeed;
static Vector2 __confiens;
static Vector2 __startPos;
static Vector2 __velocity;
static float __width;
static float __height;
static float __fireRate = 0.15f;
static float __elapsedFireRateTime;
static Vector2 __playerPos;
static BulletQueue_t bQueue;

Sprite_t playerSprites[3];
Rectangle playerBoxCollider;
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
    Bullet_t* b = Dequeue(&bQueue);
    if(b != NULL)
    {
        b->position = (Vector2){__playerPos.x, __playerPos.y - 50};
        b->boxCollider.x = __playerPos.x;
        b->boxCollider.y = __playerPos.y;
        b->isActive = true;
    }
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
    __playerPos.x += __velocity.x;
    float minX = __startPos.x - __confiens.x;
    float maxX = __startPos.x + __confiens.x;

    if (__playerPos.x < minX) __playerPos.x = minX;
    if (__playerPos.x > maxX) __playerPos.x = maxX; 


    __playerPos.y += __velocity.y;

    float minY = __startPos.y - __confiens.y;
    float maxY = __startPos.y + __confiens.y;

    if (__playerPos.y < minY) __playerPos.y = minY;
    if (__playerPos.y > maxY) __playerPos.y = maxY; 
    
}

Sprite_t __GetCurrentPlayerSprite()
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
    __playerPos = startPos;
    __playerSpeed = speed;    
    __confiens = confiens;
    playerBoxCollider = (Rectangle){__playerPos.x, __playerPos.y, __width - 35, __height - 25};

    InitQueue(&bQueue);
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
    playerBoxCollider.x = __playerPos.x;
    playerBoxCollider.y = __playerPos.y;

    __elapsedFireRateTime -= GetFrameTime();

    UpdateBullets(&bQueue);
}

void DrawPlayer()
{
    DrawBullets(&bQueue);
    DrawSprite(__GetCurrentPlayerSprite(), __playerPos, 0, WHITE);
}

void DrawPlayerCollisionRect()
{
    DrawRectangleLines(playerBoxCollider.x - playerBoxCollider.width * 0.5f, 
                            playerBoxCollider.y - playerBoxCollider.height * 0.5f, 
                            playerBoxCollider.width, playerBoxCollider.height, GREEN);
    DrawBulletsCollisionRect(&bQueue);
}

Vector2 GetPlayerPos()
{
    return __playerPos;
}