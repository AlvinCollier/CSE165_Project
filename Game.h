#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include "PlayerRect.h"
#include "EnemySpawner.h"
#include "Score.h"
#include "Health.h"
#include "ScrollingBackground.h"
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
    bool gameOver;
    ScrollingBackground * bg1;
    ScrollingBackground * bg2;
};

#endif // GAME_H
