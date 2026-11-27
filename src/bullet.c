#include "bullet.h"
#include "spriteHandler.h"
#include <stdio.h>

static Sprite_t __bulletSprite;

void InitBullet()
{
    __bulletSprite = (Sprite_t){268, 169, 32, 32, CENTERED_PIVOT(32, 32)};
}

void UpdateBullets(BulletQueue_t* q)
{
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        if(!q->bullets[i].isActive)
            continue;

        if( q->bullets[i].position.y < -100)
        {
            Enqueue(q, &q->bullets[i]);
            q->bullets[i].isActive = false;
            continue;
        }

        q->bullets[i].position.y -= 200 * GetFrameTime();
        q->bullets[i].boxCollider.y =  q->bullets[i].position.y;
    }
}

void DrawBullets(const BulletQueue_t* q)
{
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        if(!q->bullets[i].isActive)
        continue;
        
        DrawSprite(__bulletSprite,q->bullets[i].position, 0, WHITE);
    }
}

void DrawBulletsCollisionRect(const BulletQueue_t* q)
{
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        if(!q->bullets[i].isActive)
        continue;
        
        Rectangle c = q->bullets[i].boxCollider;
        DrawRectangleLines(c.x - c.width * 0.5f, 
                            c.y - c.height * 0.5f, 
                            c.width, c.height, GREEN);
    }
}


// Queue
void InitQueue(BulletQueue_t* q)
{
    q->head = 0;
    q->tail = 0;
    q->size = 0;

    for (int i = 0; i < MAX_SIZE; ++i)
    {
        Bullet_t b;
        b.position = (Vector2){-100, 0};
        b.boxCollider = (Rectangle){b.position.x, b.position.y, 
                                    __bulletSprite.width * GetScale().x - 10,
                                     __bulletSprite.height * GetScale().y - 10};
        b.baseDamage = 10;
        b.speed = 300;
        b.isActive = false;
        q->bullets[i] = b;
        Enqueue(q, &q->bullets[i]);
    }
}

bool IsEmpty(const BulletQueue_t* q) 
{
    return q->size == 0;
}

bool IsFull(const BulletQueue_t* q) 
{
    return q->size == MAX_SIZE;
}

void Enqueue(BulletQueue_t* q, Bullet_t* slot) 
{
    
    if (IsFull(q)) {
        return;
    }

    q->slots[q->tail] = slot;
    q->tail = (q->tail + 1) % MAX_SIZE;
    q->size++;
}

Bullet_t* Dequeue(BulletQueue_t* q) 
{
    if (IsEmpty(q)) {
        return NULL;
    }

    Bullet_t* slot = &(q->bullets[q->head]);
    q->head = (q->head + 1) % MAX_SIZE;
    q->size--;

    return slot;
}

