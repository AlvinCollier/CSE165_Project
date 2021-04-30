#include "Enemy.h"
#include "PlayerRect.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>

extern Game * game;

Enemy::Enemy()
{
    count++;
    health = 1;

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
            game->health->decrease();
            scene()->removeItem(this);
            delete(this);
            return;
        }
    }
}
