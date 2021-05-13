#ifndef SCROLLINGBACKGROUND_H
#define SCROLLINGBACKGROUND_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>

class ScrollingBackground: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    ScrollingBackground();
    int scrollSpeed;
public slots:
    void move();
};

#endif // SCROLLINGBACKGROUND_H
