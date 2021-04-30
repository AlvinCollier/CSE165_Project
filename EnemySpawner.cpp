#include "EnemySpawner.h"
#include "Enemy.h"

EnemySpawner::EnemySpawner()
{
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(SpawnEnemy()));

    timer->start(1250);
}

void EnemySpawner::SpawnEnemy()
{
    Enemy * enemy = new Enemy();
    enemy->setScale(3);
    scene()->addItem(enemy);
}
