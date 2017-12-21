#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include "Enemy.h"
#include "Game.h"

#define BULLET_WEIGHT 40
#define BULLET_HEIGHT 40

class Bullet: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent = 0);
public slots:
    void move();

};

#endif // BULLET_H
