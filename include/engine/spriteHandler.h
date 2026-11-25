#ifndef SPRITEHANDLER_H
#define SPRITEHANDLER_H

#include "raylib.h"


#define CENTERED_PIVOT(w, h) ((Vector2){w * GetScale().x * 0.5f, h * GetScale().y * 0.5f})
#define TOP_LEFT_PIVOT ((Vector2){0, 0})
#define MIDDLE_LEFT_PIVOT(h) ((Vector2){0, h * GetScale().y * 0.5f})
#define BOTTOM_LEFT_PIVOT(h) ((Vector2){0, h * GetScale().y})
#define BOTTOM_RIGHT_PIVOT(w, h) ((Vector2){w * GetScale().x, h* GetScale().y})


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
void DrawSprite(Sprite_t sprite, Vector2 position, float rotation, Color color);
void DrawSpriteScaled(Sprite_t sprite, Vector2 position, Vector2 scale, float rotation, Color color);
void ChangeScale(Vector2 scale);
Vector2 GetScale();
char GetFrameCounter();

void DrawSpriteTiled(Sprite_t sprite, Vector2 startPos, float rotation, float width, float height, Color color);  

#endif // SPRITEHANDLER_H