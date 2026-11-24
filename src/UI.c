#include "UI.h"
#include "spriteHandler.h"
#include <math.h>

static float __maxPlayerHealth;
static float __playerHealth;        // normalized: 0-1
static char __maxPlayerLife;
static char __playerLife;
static unsigned int __playerScore;

// Sprites
static Sprite_t __backgroudSprite;
static Sprite_t __splashImageSprite;
static Sprite_t __healthBarOutlineSprite;
static Sprite_t __healthBarInsideSprite;
static Sprite_t __lifeSprite;

static Color __healthBarColor;

static void __DrawLife(float wHeight)
{
    int xStart = 50;
    int xOffset = 70;
    for(int i = 0; i < __maxPlayerLife; ++i)
    {
        if(i < __playerLife)
            DrawSprite(__lifeSprite,  (Vector2){xStart + xOffset * i, wHeight - 100}, 0, WHITE);
        else
            DrawSprite(__lifeSprite,  (Vector2){xStart + xOffset * i, wHeight - 100}, 0, (Color){255, 255, 255, 80});
    }
}

static Vector3 __VectorLerp(Vector3 a, Vector3 b, float t)
{
    return (Vector3)
    {
        a.x + (b.x - a.x) * t,
        a.y + (b.y - a.y) * t,
        a.z + (b.z - a.z) * t,
    };
}

void DrawUI(float wWidth, float wHeight)
{
    __backgroudSprite.pivot = BOTTOM_LEFT_PIVOT(32 * 3);
    DrawSpriteScaled(__backgroudSprite, (Vector2){0, wHeight}, (Vector2){20, 3} , 0, DARKGRAY);

    DrawSprite(__splashImageSprite, (Vector2){wWidth - 25, wHeight - 25}, 0, BLACK);    // Shadow for the splashImage
    DrawSprite(__splashImageSprite, (Vector2){wWidth - 30, wHeight - 30}, 0, WHITE);
    __DrawLife(wHeight);
    
    __backgroudSprite.pivot = BOTTOM_LEFT_PIVOT(32 * 0.4f);
    DrawSpriteScaled(__backgroudSprite, (Vector2){20, wHeight - 30}, (Vector2){4, 0.4f} , 0, BLACK);
    
    __backgroudSprite.pivot = BOTTOM_LEFT_PIVOT(32 * 0.4f);
    DrawSpriteScaled(__backgroudSprite, (Vector2){20, wHeight - 30}, (Vector2){4 * __playerHealth, 0.4f} , 0, __healthBarColor);

    DrawSprite(__healthBarOutlineSprite, (Vector2){20, wHeight - 30}, 0, WHITE);

    DrawText(TextFormat("Score:\n%d", __playerScore), 400, wHeight - 150, 25, YELLOW);
}

void InitUI(float maxPlayerHealth, char maxLife)
{
    // Sprites
    __backgroudSprite = (Sprite_t){433, 367, 32, 32, BOTTOM_LEFT_PIVOT(32 * 3.0f)};
    __splashImageSprite = (Sprite_t){703, 404, 115, 58, BOTTOM_RIGHT_PIVOT(115, 58)};
    __healthBarOutlineSprite = (Sprite_t){372, 211, 130, 14, BOTTOM_LEFT_PIVOT(14)};
    __lifeSprite = (Sprite_t){136, 202, 32, 32, BOTTOM_LEFT_PIVOT(32)};

    __maxPlayerHealth = maxPlayerHealth;
    __maxPlayerLife = maxLife;
    UpdateUIPlayerHealth(maxPlayerHealth);
    UpdateUIPlayerLife(maxLife);
    UpdateUIPlayerScore(0);
}

void UpdateUIPlayerHealth(float newHealth)
{
    __playerHealth = newHealth / __maxPlayerHealth;

    // Change color from Green to Red
    Vector3 green = ColorToHSV(GREEN);
    Vector3 red = ColorToHSV((Color){230, 41, 41, 255});    // Red
    Vector3 finalColor = __VectorLerp(red, green, __playerHealth);
    __healthBarColor = ColorFromHSV(finalColor.x, finalColor.y, finalColor.z);
}

void UpdateUIPlayerLife(char numCurrentLife)
{
    __playerLife = numCurrentLife;
}

void UpdateUIPlayerScore(unsigned int newScore)
{
    __playerScore = newScore;
}