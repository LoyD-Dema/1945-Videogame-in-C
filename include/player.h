#ifndef PLAYER_H
#define PLAYER_H

#include "spriteHandler.h"

extern Sprite_t playerSprites[];
extern Vector2 playerPos;
extern Rectangle boxCollsion;


void InitPlayer(Vector2 startPos, float speed, Vector2 confines);
void UpdatePlayer();
Sprite_t GetPlayerCurrentSprite();
void HandlePlayerInput();
void ConfinePlayer();
void DrawPlayerCollisionRect();





#endif // PLAYER_H