#include "ScrollingBackground.h"
#include "Game.h"

ScrollingBackground::ScrollingBackground()
{
    setPixmap(QPixmap(":/sprites/SpaceBG.png"));
    setScale(3);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void ScrollingBackground::move()
{
    setPos(x(), y()+10);
    if(y() > 800){
        setPos(x(), -3*pixmap().height());
    }
}
