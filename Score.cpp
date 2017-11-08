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

#include "Score.h"

Score::Score(QGraphicsItem *parent) {
    this -> score = 0;

    // Draw the score
    setPlainText((QString("score: ")) +
                 QString::number(this->score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void Score::increase() {
    this->score++;
    // Redraw the score
    setPlainText((QString("score: ")) +
                 QString::number(this->score));
}

int Score::getScore() {
    return this->score;
}

void Score::setScore(int score)
{
    this -> score = score;
}
