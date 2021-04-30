#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include <QTimer>
#include <QGraphicsScene>
#include <QObject>
#include "Enemy.h"

class EnemySpawner : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    int count;
    EnemySpawner();
public slots:
    void SpawnEnemy();
};

#endif // ENEMYSPAWNER_H
