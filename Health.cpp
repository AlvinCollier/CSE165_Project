#include "Health.h"
#include "Game.h"
#include <fstream>

extern Game * game;

Health::Health(QGraphicsItem *parent)
{
    health = 25;
    
    setPlainText(QString("SHIELDS: ") + QString::number(health));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 16));
}
void Health::setScore(Score * score){
    this->score = score;
}

void Health::decrease(int damage)
{
    health -= damage;
    setPlainText(QString("SHIELDS: ") + QString::number(health));
    if(health <= 0){
        setPlainText(QString("Shields down, game over!"));
        game->gameOver = true;
        saveScore();
    }
}

int Health::getHealth()
{
    return health;
}
void Health::saveScore(){
        if(score->getScore() > score->getBestScore()){
            std::ofstream ofs("score.txt", std::ofstream::trunc);

            ofs << score->getScore();

            ofs.close();
        }
}
