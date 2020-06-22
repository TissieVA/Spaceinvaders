//
// Created by Tijs Van Alphen on 20/06/2020.
//

#include "Cover.h"

using namespace SpaceInvaders::GameObjects;

Cover::Cover(double xpos, double ypos, int width, int height, int piece) : GameObject(xpos, ypos, width, height)
{
    if (piece == 1)
        this->sprite= GameController::getInstance().getFactory()->makeSprite("Assets/Coverpiece.png");
    else if (piece == 2)
        this->sprite= GameController::getInstance().getFactory()->makeSprite("Assets/CoverpieceLeft.png");
    else
        this->sprite= GameController::getInstance().getFactory()->makeSprite("Assets/CoverpieceRight.png");

    this->alive=true;
}

bool Cover::isAlive() const
{
    return alive;
}

void Cover::setAlive(bool alive)
{
    Cover::alive = alive;
}
