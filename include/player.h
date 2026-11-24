#ifndef PLAYER_H
#define PLAYER_H

#include "spriteHandler.h"

extern Sprite_t playerSprites[];
extern Vector2 playerPos;
extern Rectangle boxCollsion;
extern float playerHealth;
extern char playerLife;
extern unsigned int playerScore;


void InitPlayer(Vector2 startPos, float speed, Vector2 confines);
void UpdatePlayer();
Sprite_t GetPlayerCurrentSprite();
void HandlePlayerInput();
void ConfinePlayer();
void DrawPlayerCollisionRect();





#endif // PLAYER_H