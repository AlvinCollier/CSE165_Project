#include "PlayerRect.h"
#include "Bullet.h"

PlayerRect::PlayerRect(){
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sfx/laser.wav"));
}

void PlayerRect::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Left){
        if(x() > 0){
            setPos(x()-10,y());
        }
    }
    else if(event->key() == Qt::Key_Right){
        if(x()+pixmap().width()*3 < hBound){
            setPos(x()+10,y());
        }
    }
    if(event->key() == Qt::Key_Up){
        if(y() > 0){
            setPos(x(),y()-10);
        }
    }
    else if(event->key() == Qt::Key_Down){
        if(y()+pixmap().height()*3 < vBound){
            setPos(x(),y()+10);
        }
    }
    if(event->key() == Qt::Key_Space){
        if(Bullet::count <= 9){
            Bullet * bullet = new Bullet();
            bullet->setScale(3);
            bullet->setPos(x() + pixmap().width()/2 + bullet->pixmap().width()/2,y());
            scene()->addItem(bullet);
            if(bulletSound->state() == QMediaPlayer::PlayingState){
                bulletSound->setPosition(0);
            }
            else{
                bulletSound->play();
                }
            }
        }

}
