#include "EnemySpawner.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Enemy3.h"

EnemySpawner::EnemySpawner()
{
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(SpawnEnemy()));

    timer->start(1250);
}

void EnemySpawner::SpawnEnemy()
{
    count++;
    if(count <= 9){
        Enemy * enemy = new Enemy();
        enemy->setScale(3);
        scene()->addItem(enemy);
    }
    else if(count <= 19){
        Enemy2 * enemy = new Enemy2();
        enemy->setScale(3);
        scene()->addItem(enemy);
    }
    else if(count <= 29){
        Enemy3 * enemy = new Enemy3();
        enemy->setScale(3);
        scene()->addItem(enemy);
    }
    else{
        count = 0;
    }

}
