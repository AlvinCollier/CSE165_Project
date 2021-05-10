#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "PlayerRect.h"
#include "EnemySpawner.h"
#include "Score.h"
#include "Health.h"
#include <QGraphicsView>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>


class Game : public QGraphicsView {
public:
    Game();
    QGraphicsScene * scene;
    PlayerRect * player;
    EnemySpawner * spawner;
    Score * score;
    Health * health;
};

#endif // GAME_H
