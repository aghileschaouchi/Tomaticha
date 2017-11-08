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

#include "Bullet.h"

extern Game *game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem() {
    // Draw the bullet
    setPixmap(QPixmap(":/images/tomatich.png"));

    // Connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer -> start(50);
}

void Bullet::move() {
    // Check if the bullet collides with an enemy
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size() ; i < n ; i++) {
        if (typeid (*(colliding_items[i])) == typeid(Enemy)) {
            // Remove the both
            scene() -> removeItem (colliding_items[i]);
            scene() -> removeItem (this);

            //Increase the score
            game -> score -> increase();

            // Delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // Move bullet up
    setPos(x(), y() - 10);

    if (pos().y() < 0) {
        scene() -> removeItem(this);
        delete this;
        qDebug() << "Bullet deleted" << endl;
    }
}
