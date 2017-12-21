#ifndef ENEMY_H
#define ENEMY_H

#include "MainPlayer.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h>
#include <string>
#include <sstream>

#define ENEMY_WEIGHT 100
#define ENEMY_HEIGHT 100

class Enemy: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy(QGraphicsItem *parent = 0);

public slots:
    void move();

};

#endif // ENEMY_H
