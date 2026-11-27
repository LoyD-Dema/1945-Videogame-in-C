#ifndef BULLET_H
#define BULLET_H
#define MAX_SIZE 100

#include "raylib.h"


typedef struct Bullet {
    Vector2 position;
    Rectangle boxCollider;
    float baseDamage;
    float speed;
    bool isActive;
    bool drawCollider;
} Bullet_t;

// TODO - Se avanza tempo cambiarla con un vector
typedef struct BulletQueue {
    Bullet_t bullets[MAX_SIZE];
    Bullet_t* slots[MAX_SIZE];
    int head;
    int tail;
    int size;
} BulletQueue_t;

void InitBullet();
void UpdateBullets(BulletQueue_t* q);
void DrawBullets(const BulletQueue_t* q);

// Queue
void InitQueue(BulletQueue_t* q);
bool IsEmpty(const BulletQueue_t* q);
bool IsFull(const BulletQueue_t* q);
void Enqueue(BulletQueue_t* q, Bullet_t* slot);
Bullet_t* Dequeue(BulletQueue_t* q);
void DrawBulletsCollisionRect(const BulletQueue_t* q);



#endif // BULLET_H