#include "background.h"
#include "stdlib.h"

static Vector2 __startPos;
static Vector2 __currenPos;
static float __speed;
static float __elapsedTimeSpawnIsland;
static Sprite_t __islandSprite;
static Vector2 __islandPos;

Sprite_t waterSprites[2];
Sprite_t islandsprites[3];


// Private funcions
Sprite_t __GetCurrentBgSprite()
{
    switch(GetFrameCounter() % (sizeof(waterSprites) / sizeof(waterSprites[0])))
    {
        default:
        case 0:
            return waterSprites[0];
        case 1:
            return waterSprites[1];
    }
}

Sprite_t __GetRandomIslandSprite()
{
    srand(GetTime());
    int i = rand() % 2;
    return islandsprites[i];
}

float __GetRandomTimerToSpawnInc(float baseTimer, int min, int max)
{
    srand(GetTime());
    return baseTimer + 
           (rand() % (max - min + 1) + min);
}

void __SpawnRandomIsland()
{
    // TODO
}



void InitBackground()
{
    waterSprites[0] = (Sprite_t){268, 367, 32, 32, TOP_LEFT_PIVOT};
    waterSprites[1] = (Sprite_t){301, 367, 32, 32, TOP_LEFT_PIVOT};

    __startPos = (Vector2){0, -128};
    __currenPos = __startPos;

    __speed = 200.0f;
    __elapsedTimeSpawnIsland = __GetRandomTimerToSpawnInc(10, -2, 2);
}

void UpdateBackground()
{
    if(__currenPos.y <= __startPos.y + 128)
    {
         __currenPos = (Vector2){__currenPos.x, __currenPos.y + __speed * GetFrameTime()};
    }
    else
    {
        __currenPos = __startPos;
    }

    __elapsedTimeSpawnIsland -= GetFrameTime();

    if(__elapsedTimeSpawnIsland <= 0)
    {
        __elapsedTimeSpawnIsland = __GetRandomTimerToSpawnInc(10, -2, 2);
        __SpawnRandomIsland();
    }

}

void DrawBackground()
{
    DrawSpriteTiled(__GetCurrentBgSprite(), __currenPos, 0, 20, 15, WHITE);
}

