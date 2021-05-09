#ifndef ENEMY3_H
#define ENEMY3_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include <QTimer>
#include <QGraphicsScene>
#include "Enemy.h"

class Enemy3 : public Enemy {
    Q_OBJECT
public:
    static int count;
    Enemy3();
public slots:
    virtual void move();
private:
    int health;
    int shootTimer;
};

#endif // ENEMY3_H
