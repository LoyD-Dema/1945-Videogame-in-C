#include "spriteHandler.h"

static Texture2D __atlas;
static float __framesPerSecond = 0.1f;
static float __timeFramePerSecond;
static int __frameCounter = 0;
static float __xScale = 1.0f;
static float __yScale = 1.0f;


void InitSpriteHandler(float framesPerSecond)
{
    __atlas = LoadTexture("resources/1945_atlas.png");
    __timeFramePerSecond = __timeFramePerSecond;
    __framesPerSecond = framesPerSecond;
}

void UpdateFrameCounter()
{
    __timeFramePerSecond -= GetFrameTime();
    if(__timeFramePerSecond <= 0)
    {
        ++__frameCounter;
        __timeFramePerSecond = __framesPerSecond;
    }
}

void DrawSprite(Sprite_t sprite, Vector2 position, float rotation, Color color)
{
    DrawTexturePro(__atlas, (Rectangle){sprite.x, sprite.y,sprite.width, sprite.height}, 
                            (Rectangle){position.x, position.y, sprite.width * __xScale, sprite.height * __yScale}, 
                            sprite.pivot, rotation, color); 
}

void DrawSpriteScaled(Sprite_t sprite, Vector2 position, Vector2 scale, float rotation, Color color)
{
    DrawTexturePro(__atlas, (Rectangle){sprite.x, sprite.y,sprite.width, sprite.height}, 
                            (Rectangle){position.x, position.y, sprite.width * __xScale * scale.x, sprite.height * __yScale * scale.y}, 
                            sprite.pivot, rotation, color); 
}

void ChangeScale(Vector2 scale)
{
    __xScale = scale.x;
    __yScale = scale.y;
}

Vector2 GetScale()
{
    return (Vector2){__xScale, __yScale};
}

char GetFrameCounter()
{
    return __frameCounter;
}

