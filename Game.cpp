#include "Game.h"

Game::Game()
{

    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QImage(":/sprites/SpaceBG.png")));
    setScene(scene);

    player = new PlayerRect();
    player->setPixmap(QPixmap(":/sprites/SpaceShip.png"));
    player->setScale(3);
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setScore(score);
    health->setPos(x(), y()+25);
    scene->addItem(health);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(600,800);
    scene->setSceneRect(0,0,600,800);

    player->setPos((this->width()/2)-(player->pixmap().width()/2),this->height()-(3.5*player->pixmap().height()));
    player->hBound = scene->width();
    player->vBound = scene->height();

    spawner = new EnemySpawner();
    scene->addItem(spawner);

    QMediaPlaylist * playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sfx/GameLoop.wav"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer * music = new QMediaPlayer;
    music->setMedia(playlist);
    music->play();

    
}
