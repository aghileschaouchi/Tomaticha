#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QTimer>
#include "MainPlayer.h"
#include "Score.h"
#include <QString>



class Game: public QGraphicsView {
public:
    Game(QWidget *parent = 0);

    QGraphicsScene *scene;
    MainPlayer *player;
    Score *score;
};

#endif // GAME_H
