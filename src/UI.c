#include "UI.h"
#include "spriteHandler.h"

static float __maxPlayerHealth;
static float __playerHealth;        // 0-1
static char __playerLife;
static int __playerScore;

// Sprites
static Sprite_t __backgroudSprite;
static Sprite_t __splashImageSprite;
static Sprite_t __healthBarOutlineSprite;
static Sprite_t __healthBarInsideSprite;
static Sprite_t __lifeSprite;

static void DrawUI(float wWidth, float wHeight)
{
    __backgroudSprite.pivot = BOTTOM_LEFT_PIVOT(32 * 3);
    DrawSpriteScaled(__backgroudSprite, (Vector2){0, wHeight}, (Vector2){20, 3} , 0, DARKGRAY);

    DrawSprite(__splashImageSprite, (Vector2){wWidth - 25, wHeight - 25}, 0, BLACK);    // Shadow for the splashImage
    DrawSprite(__splashImageSprite, (Vector2){wWidth - 30, wHeight - 30}, 0, WHITE);

    DrawSprite(__lifeSprite,  (Vector2){50, wHeight - 100}, 0, (Color){255, 255, 255, 255});
    DrawSprite(__lifeSprite,  (Vector2){120, wHeight - 100}, 0, (Color){255, 255, 255, 255});
    DrawSprite(__lifeSprite,  (Vector2){190, wHeight - 100}, 0, (Color){255, 255, 255, 80});
    
    __backgroudSprite.pivot = BOTTOM_LEFT_PIVOT(32 * 0.4f);
    DrawSpriteScaled(__backgroudSprite, (Vector2){20, wHeight - 30}, (Vector2){4, 0.4f} , 0, BLACK);
    
    __backgroudSprite.pivot = BOTTOM_LEFT_PIVOT(32 * 0.4f);
    DrawSpriteScaled(__backgroudSprite, (Vector2){20, wHeight - 30}, (Vector2){4 * __playerHealth, 0.4f} , 0, GREEN);

    DrawSprite(__healthBarOutlineSprite, (Vector2){20, wHeight - 30}, 0, WHITE);
}

void InitUI(float maxPayerHealth, char numOfLife)
{
    // Sprites
    __backgroudSprite = (Sprite_t){433, 367, 32, 32, BOTTOM_LEFT_PIVOT(32 * 3.0f)};
    __splashImageSprite = (Sprite_t){703, 404, 115, 58, BOTTOM_RIGHT_PIVOT(115, 58)};
    __healthBarOutlineSprite = (Sprite_t){372, 211, 130, 14, BOTTOM_LEFT_PIVOT(14)};
    __lifeSprite = (Sprite_t){136, 202, 32, 32, BOTTOM_LEFT_PIVOT(32)};

    __maxPlayerHealth = maxPayerHealth;
    UpdateUIPlayerHealth(maxPayerHealth);
    UpdateUIPlayerLife(numOfLife);
    UpdateUIPlayerScore(0);
}

void UpdateUIPlayerHealth(float newHealth)
{
    __playerHealth = newHealth / __maxPlayerHealth;
}

void UpdateUIPlayerLife(char numCurrentLife)
{
    __playerLife = numCurrentLife;
}

void UpdateUIPlayerScore(int newScore)
{
    __playerScore = newScore;
}