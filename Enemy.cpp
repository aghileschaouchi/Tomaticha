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

#include "Enemy.h"

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem() {
    int random_num = rand() % (SCREEN_WEIGHT - 100);
    setPos(random_num, 0);

    int random_enemy  = rand()%4;

    std::string enemy_name = "spaceMeteors_";
    std::stringstream sstm;

    sstm << ":/images/" << enemy_name << random_enemy << ".png";
    std::string result = sstm.str();

    // Draw the enemy
    setPixmap(QPixmap(QString::fromStdString(result))
              .scaled(ENEMY_WEIGHT,ENEMY_HEIGHT,Qt::KeepAspectRatio));

    // Connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer -> start(50);
}

void Enemy::move() {
    // Move enemy down
    setPos(x(), y() + 5);

    if (pos().y() > SCREEN_HEIGHT) {
        scene() -> removeItem(this);
        delete this;
        qDebug() << "Enemy deleted" << endl;
    }
}
