#ifndef PLAYER_H
#define PLAYER_H

#include "spriteHandler.h"

extern Sprite_t playerSprites[];
extern Rectangle boxCollsion;
extern float playerHealth;
extern char playerLife;
extern unsigned int playerScore;


void InitPlayer(Vector2 startPos, float speed, Vector2 confines);
void HandlePlayerInput();
void UpdatePlayer();
void DrawPlayer();
void DrawPlayerCollisionRect();
Vector2 GetPlayerPos();




#endif // PLAYER_H