#ifndef MAINPLAYER_H
#define MAINPLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <iostream>

#define PLAYER_WEIGHT 100
#define PLAYER_HEIGHT 100

#define SCREEN_HEIGHT 600
#define SCREEN_WEIGHT 1200

class MainPlayer:public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    MainPlayer(QGraphicsItem *parent = 0);
    void keyPressEvent (QKeyEvent *event);
public slots:
    void spawn();
};

#endif // MAINPLAYER_H
