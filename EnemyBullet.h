#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include "Enemy.h"
#include "PlayerRect.h"
#include "Game.h"

class EnemyBullet : public Enemy {
public:
    EnemyBullet();
    void move();
};

#endif // ENEMYBULLET_H
