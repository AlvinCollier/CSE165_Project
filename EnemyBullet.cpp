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
    //check for game over
    if(game->gameOver==true){
        scene()->removeItem(this);
        delete(this);
        return;
    }
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
            game->health->decrease(1);
            scene()->removeItem(this);
            delete(this);
            return;
        }
    }
}
