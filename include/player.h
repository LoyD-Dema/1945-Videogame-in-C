#ifndef PLAYER_H
#define PLAYER_H

#include "spriteHandler.h"

extern Sprite_t playerSprites[];
extern Vector2 playerPos;


void InitPlayer(Vector2 startPos, float speed, Vector2 confines);
Sprite_t GetPlayerCurrentSprite();
void HandlePlayerInput();
void ConfinePlayer();





#endif // PLAYER_H