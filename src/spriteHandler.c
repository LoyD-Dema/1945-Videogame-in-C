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

void DrawSprite(Sprite_t sprite, Vector2 position, float rotation)
{
    DrawTexturePro(__atlas, (Rectangle){sprite.x, sprite.y,sprite.width, sprite.height}, 
                            (Rectangle){position.x, position.y, sprite.width * __xScale, sprite.height * __yScale}, 
                            sprite.pivot, rotation, WHITE); 
}

void ChangeScale(Vector2 scale)
{
    __xScale = scale.x;
    __yScale = scale.y;
}

char GetFrameCounter()
{
    return __frameCounter;
}

