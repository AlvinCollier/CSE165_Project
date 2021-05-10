#include "Score.h"
#include <iostream>
#include <fstream>

Score::Score(QGraphicsItem *parent)
{
    score = 0;
    bestScore=0;
    
    std::ifstream myfile ("score.txt");
    if (myfile.good() && myfile.is_open()){
        int line;
        myfile >>line;
        bestScore=line;
        myfile.close();
    } else{
        bestScore=0;
    }
    setPlainText(QString("SCORE: ") + QString::number(score)+QString(" - Best Score: ")+ QString::number(bestScore));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Score::increase()
{
    score += 100;
    setPlainText(QString("SCORE: ") + QString::number(score)+QString(" - Best Score: ")+ QString::number(bestScore));
}

int Score::getScore()
{
    return score;
}
int Score::getBestScore(){
    return bestScore;
}
