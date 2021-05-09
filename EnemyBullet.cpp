#include "EnemyBullet.h"

extern Game * game;

EnemyBullet::EnemyBullet()
{
    setPixmap(QPixmap(":/sprites/laser2.png"));
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void EnemyBullet::move()
{
    setPos(x(), y()+10);
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
            int dFactor = 1;
            game->health->decrease(dFactor);
            scene()->removeItem(this);
            delete(this);
            return;
        }
    }
}
