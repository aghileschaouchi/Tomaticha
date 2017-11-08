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



class Enemy: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy(QGraphicsItem *parent = 0);

public slots:
    void move();

};

#endif // ENEMY_H
