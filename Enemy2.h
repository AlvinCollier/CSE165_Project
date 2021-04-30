#ifndef ENEMY2_H
#define ENEMY2_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include <QTimer>
#include <QGraphicsScene>
#include "Enemy.h"

class Enemy2 : public Enemy {
    Q_OBJECT
public:
    static int count;
    Enemy2();
public slots:
    virtual void move();
private:
    int health;
    int shootTimer;
};


#endif // ENEMY2_H
