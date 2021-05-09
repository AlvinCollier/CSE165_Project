#include "Enemy.h"
#include "EnemyBullet.h"
#include "PlayerRect.h"
#include "Game.h"

extern Game * game;

Enemy::Enemy()
{
    count++;
    health = 1;
    shootTimer = 50;

    int random_number = rand() %500;
    setPos(random_number,0);
    setPixmap(QPixmap(":/sprites/SpaceShip2.png"));
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

int Enemy::count = 0;

void Enemy::move()
{
    setPos(x(), y()+5);
    if(y() > 800 + pixmap().height()){
        count--;
        scene()->removeItem(this);
        delete(this);
    }
    //check collisions
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0; i < colliding_items.size(); i++){
        if(typeid(*(colliding_items[i])) == typeid(PlayerRect)){
            //factor by which health decreases by
            int dFactor=2;
            game->health->decrease(dFactor);
            scene()->removeItem(this);
            delete(this);
            return;
        }
    }
    //shoot at player
    shootTimer--;
    if(shootTimer == 0){
        shoot();
    }
}

void Enemy::shoot()
{
    shootTimer = 50;
    EnemyBullet * bullet = new EnemyBullet();
    bullet->setScale(3);
    bullet->setPos(x()+pixmap().width()/2+bullet->pixmap().width()/2, y()+pixmap().height()/2);
    scene()->addItem(bullet);
}
