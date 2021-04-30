#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>

extern Game * game;

Bullet::Bullet()
{
    count++;
    setPixmap(QPixmap(":/sprites/laser.png"));
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

Bullet::~Bullet()
{
    count--;
}

int Bullet::count = 0;

void Bullet::move()
{
    //check collisions
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0; i < colliding_items.size(); i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            game->score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete(colliding_items[i]);
            delete(this);
            return;
        }
    }

    setPos(x(), y()-10);
    if(y() < -pixmap().height()){
        scene()->removeItem(this);
        delete(this);
    }
}
