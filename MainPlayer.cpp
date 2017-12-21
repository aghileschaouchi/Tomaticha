/* **********************************************************
 * Copyright (c) 2017 Aghiles Chaouchi
* This file is part of a free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/lgpl-3.0.html>
   ********************************************************* */

#include "MainPlayer.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Bullet.h"
#include "Enemy.h"

MainPlayer::MainPlayer(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    // Set graphics
    setPixmap(QPixmap(":/images/spaceShips_005.png")
              .scaled(PLAYER_WEIGHT,PLAYER_HEIGHT,Qt::KeepAspectRatio));

}

void MainPlayer::keyPressEvent(QKeyEvent *event) {
    //qDebug() << "Key pressed";
    if (event -> key() == Qt::Key_Left) {
        if (pos().x() > 0)
            setPos (x() - 20, y());
    }
    else if (event -> key() == Qt::Key_Right) {
        if (pos().x() + PLAYER_WEIGHT < SCREEN_WEIGHT)
            setPos (x() + 20, y());
    }
    else if (event -> key() == Qt::Key_Up) {
        setPos (x(), y() - 50);
    }
    else if (event -> key() == Qt::Key_Down) {
        setPos (x(), y() + 20);
    }

    else if (event -> key() == Qt::Key_Space) {
        // Create a bullet
        qDebug() << "Bullet :" << endl;
        qDebug() << x() << y() << endl;

        Bullet * left_bullet = new Bullet();
        Bullet * right_bullet = new Bullet();

        left_bullet -> setPos(x() + PLAYER_WEIGHT/2 + 15, y());
        right_bullet -> setPos(x() + 15, y());

        scene() -> addItem(left_bullet);
        scene() -> addItem(right_bullet);
    }
}

void MainPlayer::spawn(){
    // Create an enemy
    Enemy *enemy = new Enemy();
    scene() -> addItem(enemy);
}
