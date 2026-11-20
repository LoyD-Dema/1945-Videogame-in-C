#ifndef PLAYER_H
#define PLAYER_H

#include "spriteHandler.h"

extern Sprite_t playerSprites[];
extern Vector2 playerPos;

Sprite_t GetPlayerCurrentSprite();
void HandlePlayerInput();





#endif // PLAYER_H