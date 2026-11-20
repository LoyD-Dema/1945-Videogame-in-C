#include "player.h"

char __currentSprite = 0;

Sprite_t playerSprites[] =
{
    { 301, 103, 65, 65},
    { 301, 169, 65, 65},
    { 301, 235, 65, 65}    
};

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