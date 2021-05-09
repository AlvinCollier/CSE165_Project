#include "Enemy3.h"
#include "EnemyBullet.h"
#include "PlayerRect.h"
#include "Game.h"
#include <math.h>

extern Game * game;

Enemy3::Enemy3()
{
    count++;
    health = 1;
    shootTimer = 50;

    int random_number = rand() %500;
    setPos(0,0);
    setPixmap(QPixmap(":/sprites/SpaceShip4.png"));
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

int Enemy3::count = 0;

void Enemy3::move()
{
    if(x() < 300 +pixmap().height()){
        setPos(pow(y()/50,3), y()+5);
    }
    else if(x() >= 300+pixmap().height()){
        setPos(x()+(3200/pow(y()/50,3)), y()+pow(x()/200,3));
    }
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
