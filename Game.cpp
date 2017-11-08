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

#include "Game.h"

Game::Game(QWidget *parent) {

    // Lets create a scene
    scene = new QGraphicsScene();
    // Create an item to put into the scene


    // Add the item to the scence
    scene -> setSceneRect(0, 0, SCREEN_WEIGHT, SCREEN_HEIGHT);

    // Set the background
    setBackgroundBrush(QBrush(QImage(":/images/bg.jpg")));

    // bind the view (this)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(SCREEN_WEIGHT, SCREEN_HEIGHT);

    // Create a player
    player = new MainPlayer;
    player -> setPos(SCREEN_WEIGHT/2,
                     SCREEN_HEIGHT - PLAYER_WEIGHT - 5);
    // Make the player focusable
    player -> setFlag(QGraphicsItem::ItemIsFocusable);
    player -> setFocus();
    scene -> addItem (player);

    // Create the score
    score = new Score();
    scene -> addItem(score);

    // Spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer -> start(2000);

    show ();

}
