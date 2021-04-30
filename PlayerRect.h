#ifndef PLAYERRECT_H
#define PLAYERRECT_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include <QMediaPlayer>

class PlayerRect : public QGraphicsPixmapItem {
public:
    PlayerRect();
    int hBound, vBound;
    void keyPressEvent(QKeyEvent * event);
private:
    QMediaPlayer * bulletSound;
};

#endif // PLAYERRECT_H
