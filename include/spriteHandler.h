#ifndef SPRITEHANDLER_H
#define SPRITEHANDLER_H

#include "raylib.h"

typedef struct Sprite {
    
    // Values for read from an Atlas
    float x;
    float y;
    float width;
    float height;

    Vector2 pivot;

} Sprite_t;

void InitSpriteHandler();
void UpdateFrameCounter();
void DrawSprite(Sprite_t sprite, Vector2 position, float rotation);
void ChangeScale(Vector2 scale);

#endif // SPRITEHANDLER_H