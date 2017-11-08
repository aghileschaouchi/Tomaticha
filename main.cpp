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

#include <QApplication>
#include <QGraphicsScene>
#include "MainPlayer.h"
#include <QGraphicsView>
#include <QTimer>
#include "Game.h"
// Game is global, so it can be used everywhere
Game *game;

int main (int argc, char *argv[])
{
    QApplication a (argc, argv);
    game = new Game();
    game -> show();

    return a.exec ();
}
