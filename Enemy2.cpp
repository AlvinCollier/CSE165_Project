#include "Enemy2.h"
#include "EnemyBullet.h"
#include "PlayerRect.h"
#include "Game.h"
#include <math.h>

extern Game * game;

Enemy2::Enemy2()
{
    count++;
    health = 1;
    shootTimer = 50;

    int random_number = rand() %500;
    setPos(random_number,0);
    setPixmap(QPixmap(":/sprites/SpaceShip3.png"));
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

int Enemy2::count = 0;

void Enemy2::move()
{
    setPos(x()+10*sin(y()/50), y()+2);
    if(y() > 800 + pixmap().height()){
        count--;
        scene()->removeItem(this);
        delete(this);
    }
    //check collisions
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0; i < colliding_items.size(); i++){
        if(typeid(*(colliding_items[i])) == typeid(PlayerRect)){
            game->health->decrease(2);
            scene()->removeItem(this);
            delete(this);
            return;
        }
    }
    //shoot at player
    shootTimer--;
    if(shootTimer == 0){
        Enemy::shoot();
    }
}
