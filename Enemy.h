#ifndef ENEMY_H
#define ENEMY_H

#include<QGraphicsPixmapItem>
#include<QObject>

class Enemy: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    static int count;
    Enemy();
public slots:
    void move();
private:
    int health;
};


#endif // ENEMY_H
