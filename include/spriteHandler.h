#ifndef SPRITEHANDLER_H
#define SPRITEHANDLER_H

#include "raylib.h"


#define CENTERED_PIVOT(w, h) ((Vector2){(w) * 0.5f, (h) * 0.5f})


typedef struct Sprite {
    
    // Values for read from an Atlas
    float x;
    float y;
    float width;
    float height;

    Vector2 pivot;

} Sprite_t;

void InitSpriteHandler(float framesPerSecond);
void UpdateFrameCounter();
void DrawSprite(Sprite_t sprite, Vector2 position, float rotation);
void ChangeScale(Vector2 scale);
Vector2 GetScale();
char GetFrameCounter();

#endif // SPRITEHANDLER_H